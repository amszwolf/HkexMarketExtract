/* 
 * File:   HkexExtractor.cpp
 * Author: Gavin Chan
 * 
 * Created on February 14, 2016, 12:16 AM
 */

#include "HkexExtractor.h"

#include <boost/algorithm/string.hpp>
#include <algorithm>

using namespace std;

CHkexExtractor::CHkexExtractor() :
	mysqlClient(),
	httpReq(),
	config(CUtilConfigAccess::Instance()),
	hkexSite("www.hkex.com.hk"),
	hkexSiteSuffix("/eng/stat/dmstat/dayrpt/"),
	underlyingList({"hsif"}),
	backDays(0),
	schemaName(""),
	tableName("historical_px")
{
}

CHkexExtractor::~CHkexExtractor() {
}

bool CHkexExtractor::Initialize(int numberOfDays)
{
	backDays = numberOfDays;
	schemaName = config.GetValue("MysqlConnection.SchemaName");
	auto dbhost = config.GetValue("MysqlConnection.Host");
	auto user = config.GetValue("MysqlConnection.UserName");
	auto pwd = config.GetValue("MysqlConnection.UserPassword");

	if (backDays <= 0)
	{
		Utllog << "Invalid value of backDays : " << backDays;
		Utllog.LogWarning();
		return false;
	}
	
	return mysqlClient.Connect(schemaName, dbhost, user, pwd);
}

bool CHkexExtractor::StartExtract()
{
	bool ret = true;
	auto instmtPrefix = underlyingList.begin();
	auto currDateTime = CUtilDateTime::GetCurrentTime();

	for (int day = 0; day < backDays; day++)
	{
		string date{};
		string time{};
		CUtilDateTime::TimeConvertString(currDateTime, date, time);
		date = date.substr(2);

		auto request = hkexSiteSuffix + *instmtPrefix + date + ".htm";
		Utllog << "Address : " << hkexSite << endl
			   << "Request : " << request << endl;
		Utllog.LogDebug();

		string result{};
		ret &= httpReq.SendRequest(hkexSite, request, result);
		ret &= ExtractInstrumentFromString(*instmtPrefix, currDateTime, result);

		// Decrement a day
		currDateTime -= boost::gregorian::date_duration(1);
	}

	ret &= InsertHistorialPx();

	return ret;
}

bool CHkexExtractor::ExtractInstrumentFromString(
						std::string& instmtPrefix,
						CUtilDateTime& dateTime,
						std::string& str)
{
	auto lines = vector<string>{};
	boost::split(lines, str, boost::is_any_of("\n"), boost::token_compress_on);

	for (auto line : lines)
	{
		CFutureInstrument instmt;
		if (instmt.FromHkexString(line))
		{
			instmt.InstrumentName = instmtPrefix;
			instmt.DateTime = dateTime;
			instrumentList.push_back(instmt);

			instmt.Dump(Utllog);
			Utllog.LogDebug();
		}
	}

	Utllog << "Instrument list count = " << instrumentList.size();
	Utllog.LogDebug();

	return true;
}
	
bool CHkexExtractor::InsertHistorialPx()
{

	for (auto& instmt : instrumentList)
	{
		string sql 
			= string{"insert into "} + schemaName + "." 
			+ tableName 
			+ " (date,month,type,strike,op_t,cl_t,high_t,low_t,vol_t,oi,chg_cl,chg_oi,instrument,record_key) values ";

		// Validation
		if (CInstrument::ExpiryMonthReverseMap.end() ==
			CInstrument::ExpiryMonthReverseMap.find(instmt.ExpiryMonth))
		{
			Utllog << "Invalid month : " << instmt.ExpiryMonth;
			Utllog.LogWarning();
			return false;
		}
		
		string date{};
		string time{};
		string instmtName = instmt.InstrumentName;
		string expiryMonth = CInstrument::ExpiryMonthReverseMap[instmt.ExpiryMonth]
							+ "-" + to_string(instmt.ExpiryYear-2000);
		string type = string(1, static_cast<char>(instmt.Type));
		string strike = to_string((int)instmt.Strike);
		CUtilDateTime::TimeConvertString(instmt.DateTime, date, time);
		string key = date + instmtName + expiryMonth + type + strike;
		
		// Start
		sql += "(";

		// Date
		sql += "'" + date + "',";

		// Expiry Month
		sql += "'" + expiryMonth + "',";

		// Type
		sql += "'" + string(1, static_cast<char>(instmt.Type)) + "',";

		// Strike
		sql += strike + ",";

		// All prices, volume and open interest
		sql += to_string(instmt.OpenPrice) + ","
			 + to_string(instmt.ClosePrice) + ","
			 + to_string(instmt.DailyHigh) + ","
			 + to_string(instmt.DailyLow) + ","
			 + to_string(instmt.Volume) + ","
			 + to_string(instmt.OpenInterest) + ","
			 + to_string(instmt.ClosePriceChange) + ","
			 + to_string(instmt.OpenInterestChange) + ",";

		// Instrument
		sql += "'" + instmt.InstrumentName + "',";

		// Record key
		sql += "'" + key + "'";

		// End
		sql += ")";

		// Query
		if (mysqlClient.Query(sql))
		{
			Utllog << "Query succeeded : " << endl
				   << sql;
			Utllog.LogInfo();
		}
		else
		{
			Utllog << "Query failed : " << endl
				   << sql;
			Utllog.LogWarning();
		}
	}

	return true;
}