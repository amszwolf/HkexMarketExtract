/* 
 * File:   newsimpletest.cpp
 * Author: Gavin Chan
 *
 * Created on Jan 30, 2016, 1:39:27 PM
 */
#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#	define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>

#include "UtilDateTime.h"

#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#	define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */
BOOST_AUTO_TEST_SUITE( GeneralTest )

BOOST_AUTO_TEST_CASE( DateConvertStringYYYYMMDD )
{
	using namespace std;
	CUtilDateTime datetime(2000, 1, 1);
	string date = "";
	string time = "";

	CUtilDateTime::TimeConvertString(datetime, date, time);

	BOOST_CHECK(date == "20000101");

	BOOST_CHECK(time == "00:00:00");
}

BOOST_AUTO_TEST_CASE( DateTimeConvertString )
{
	using namespace std;
	CUtilDateTime datetime(2000, 1, 1, 11, 10, 22);
	string date = "";
	string time = "";

	CUtilDateTime::TimeConvertString(datetime, date, time);

	BOOST_CHECK(date == "20000101");

	BOOST_CHECK(time == "11:10:22");
}

BOOST_AUTO_TEST_SUITE_END()
