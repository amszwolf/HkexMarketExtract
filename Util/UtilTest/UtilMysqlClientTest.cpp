/* 
 * File:   UtilMysqlClientTest.cpp
 * Author: Gavin Chan
 *
 * Created on Feb 13, 2016, 11:01:00 PM
 */
#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#	define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>

#include "UtilMysqlClient.h"

#include <stdlib.h>
#include <iostream>

auto dbname = "hkex";
auto dbhost = "104.197.19.54:3306";
auto name = "extract";
auto password = "extract";
auto selectQuery = "select * from hkex.historical_px;";
auto createQuery = "create table `test` ( `id` int(11), `text` varchar(8) ) ENGINE=InnoDB";
auto dropQuery = "drop table hkex.test";
auto insertQuery = "insert into hkex.test (id,text) values (1,'test')";

BOOST_AUTO_TEST_SUITE( GeneralTest )

BOOST_AUTO_TEST_CASE( Connect )
{
	CUtilMysqlClient client;

	BOOST_CHECK(client.Connect(dbname, dbhost, name, password));
}

BOOST_AUTO_TEST_CASE( DisconnectedQuery )
{
	CUtilMysqlClient client;
	BOOST_CHECK_EQUAL(false, client.Query(selectQuery));
}

BOOST_AUTO_TEST_CASE( SelectQuery )
{
	CUtilMysqlClient client;

	BOOST_CHECK(client.Connect(dbname, dbhost, name, password));
	BOOST_CHECK(client.Query(selectQuery));
}

BOOST_AUTO_TEST_CASE( CreateDropQuery )
{
	CUtilMysqlClient client;

	BOOST_CHECK(client.Connect(dbname, dbhost, name, password));
	BOOST_CHECK(client.Query(createQuery));
	BOOST_CHECK(client.Query(dropQuery));
}

BOOST_AUTO_TEST_CASE( InsertQuery )
{
	CUtilMysqlClient client;

	BOOST_CHECK(client.Connect(dbname, dbhost, name, password));
	BOOST_CHECK(client.Query(createQuery));
	BOOST_CHECK(client.Query(insertQuery));
	BOOST_CHECK(client.Query(dropQuery));
}

BOOST_AUTO_TEST_SUITE_END()
