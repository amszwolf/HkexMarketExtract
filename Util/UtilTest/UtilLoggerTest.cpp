/* 
 * File:   UtilLoggerTest.cpp
 * Author: Gavin Chan
 *
 * Created on Feb 15, 2016, 2:39:27 PM
 */
#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#	define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>

#include "UtilLogger.h"

/*
 * Simple C++ Test Suite
 */
BOOST_AUTO_TEST_SUITE( GeneralTest )

BOOST_AUTO_TEST_CASE( Dump )
{
	CUtilLoggerBase loggerBase;
	auto string1 = std::string{"Hello world!"};
	auto string2 = std::string{"This is test case."};

	loggerBase << string1;
	BOOST_CHECK_EQUAL(string1, loggerBase.Dump());
	
	loggerBase << string2;
	BOOST_CHECK_EQUAL(string2, loggerBase.Dump());
}

BOOST_AUTO_TEST_SUITE_END()
