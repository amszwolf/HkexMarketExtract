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

#include "UtilHttpRequestHandler.h"

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */
BOOST_AUTO_TEST_SUITE( GeneralTest )

BOOST_AUTO_TEST_CASE( Request )
{
	CUtilHttpRequestHandler req;
	std::string response = "";
	BOOST_CHECK(req.SendRequest("josh.com", 
								"/notes/island-ecn-10th-birthday/",
								response));

	BOOST_CHECK(response.find("ECN 10th Birthday Source Code Release") !=
				std::string::npos);
}

BOOST_AUTO_TEST_SUITE_END()
