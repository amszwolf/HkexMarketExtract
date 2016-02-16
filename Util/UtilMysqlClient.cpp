/* 
 * File:   UtilMysqlClient.cpp
 * Author: Gavin Chan
 * 
 * Created on February 13, 2016, 10:24 PM
 */

#include "UtilMysqlClient.h"

using namespace std;
using namespace mysqlpp;

CUtilMysqlClient::CUtilMysqlClient() 
	: conn(false)
{
}

CUtilMysqlClient::~CUtilMysqlClient()
{
}

bool CUtilMysqlClient::Connect(string dbname,
		string host,
		string user,
		string pwd)
{
	return conn.connect(dbname.c_str(), host.c_str(), user.c_str(), pwd.c_str());
}

bool CUtilMysqlClient::Query(std::string queryString)
{
	if (conn.connected())
	{
		mysqlpp::Query sqlQuery = conn.query();
		sqlQuery << queryString;
		return sqlQuery.execute();
	}
	else
	{
		return false;
	}
}