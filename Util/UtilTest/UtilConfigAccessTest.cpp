/* 
 * File:   UtilConfigAccessTest.cpp
 * Author: Gavin Chan
 *
 * Created on Feb 13, 2016, 1:14:00 AM
 */
#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#	define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>

#include "UtilConfigAccess.h"

#include <stdlib.h>

BOOST_AUTO_TEST_SUITE( GeneralTest )

BOOST_AUTO_TEST_CASE( GetValue )
{
	auto path = std::string{getenv("HOME")} + "/config/UtilConfigAccessTest.config";
	CUtilConfigAccess configAccess;
	std::string key1 = "test1";
	std::string key2 = "test2";
	std::string value = "";
	
	BOOST_CHECK(configAccess.ReadFromPath(path));

	BOOST_CHECK(configAccess.GetValue(key1, value));
	BOOST_CHECK_EQUAL(value, "ABC");

	BOOST_CHECK(configAccess.GetValue(key2, value));
	BOOST_CHECK_EQUAL(value, "ABC=CDE");
}

BOOST_AUTO_TEST_SUITE_END()
