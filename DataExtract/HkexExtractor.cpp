/* 
 * File:   HkexExtractor.cpp
 * Author: Gavin Chan
 * 
 * Created on February 14, 2016, 12:16 AM
 */

#include "HkexExtractor.h"

#include <boost/algorithm/string.hpp>

using namespace std;

CHkexExtractor::CHkexExtractor() :
	mysqlClient(),
	httpReq(),
	config(CUtilConfigAccess::Instance()),
	hkexSite("www.hkex.com.hk"),
	hkexSiteSuffix("/eng/stat/dmstat/dayrpt/"),
	underlyingList({"hsif"})
{
}

CHkexExtractor::~CHkexExtractor() {
}

bool CHkexExtractor::Initialize()
{
	auto dbname = config.GetValue("MysqlConnection.SchemaName");
	auto dbhost = config.GetValue("MysqlConnection.Host");
	auto user = config.GetValue("MysqlConnection.UserName");
	auto pwd = config.GetValue("MysqlConnection.UserPassword");

	return mysqlClient.Connect(dbname, dbhost, user, pwd);
}

bool CHkexExtractor::StartExtract()
{
	bool ret = true;
	auto instmtPrefix = underlyingList.begin();
	auto currDateTime = CUtilDateTime::GetCurrentTime();
	currDateTime -= boost::gregorian::date_duration(4);
	auto date = string{};
	auto time = string{};
	CUtilDateTime::TimeConvertString(currDateTime, date, time);
	date = date.substr(2);

	auto request = hkexSiteSuffix + *instmtPrefix + date + ".htm";
	Utllog << "Address : " << hkexSite << endl
		   << "Request : " << request << endl;
	Utllog.LogDebug();

	auto result = string{};
	ret &= httpReq.SendRequest(hkexSite, request, result);
	ret &= ExtractInstrumentFromString(result);

	return ret;
}

bool CHkexExtractor::ExtractInstrumentFromString(std::string& str)
{
	auto lines = vector<string>{};
	boost::split(lines, str, boost::is_any_of("\n"), boost::token_compress_on);

	for (auto line : lines)
	{
		CFutureInstrument instmt;
		if (instmt.FromHkexString(line))
		{
			instrumentList.push_back(instmt);

			instmt.Dump(Utllog);
			Utllog.LogDebug();
		}
	}

	Utllog << "Instrument list count = " << instrumentList.size();
	Utllog.LogDebug();

	return true;
}
	