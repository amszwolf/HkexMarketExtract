/* 
 * File:   FutureInstrumentTest.cpp
 * Author: Gavin Chan
 *
 * Created on Feb 10, 2016, 1:39:27 PM
 */
#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#	define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>

#include "FutureInstrument.h"

/*
 * Simple C++ Test Suite
 */
BOOST_AUTO_TEST_SUITE( GeneralTest )

BOOST_AUTO_TEST_CASE( FromHkexStringTest )
{
	CFutureInstrument instmt;
	
	std::string raw = "FEB-16   19,161  19,288  19,050  19,257  12,410  |  19,188  19,409  19,186  81,586   19,313     +157  |   21,988   18,533   93,996   104,620     -2,089 ";

	BOOST_CHECK(instmt.FromHkexString(raw));

	BOOST_CHECK_EQUAL(instmt.ExpiryMonth, CFutureInstrument::FEB);
	BOOST_CHECK_EQUAL(instmt.ExpiryYear, 2016);
	BOOST_CHECK_EQUAL(instmt.OpenPrice, 19188);
	BOOST_CHECK_EQUAL(instmt.ClosePrice, 19313);
	BOOST_CHECK_EQUAL(instmt.ClosePriceChange, 157);
	BOOST_CHECK_EQUAL(instmt.DailyHigh, 19409);
	BOOST_CHECK_EQUAL(instmt.DailyLow, 19186);
	BOOST_CHECK_EQUAL(instmt.Volume, 81586);
	BOOST_CHECK_EQUAL(instmt.OpenInterest, 104620);
	BOOST_CHECK_EQUAL(instmt.OpenInterestChange, -2089);
}

BOOST_AUTO_TEST_CASE( FromHkexStringTest2 )
{
	CFutureInstrument instmt;
	
	std::string raw = "MAR-16   19,078  19,300  18,990  19,200     142  |  19,179  19,330  19,150     435   19,241     +152  |   24,700   18,493      577     9,388        +45";

	BOOST_CHECK(instmt.FromHkexString(raw));

	BOOST_CHECK_EQUAL(instmt.ExpiryMonth, CFutureInstrument::MAR);
	BOOST_CHECK_EQUAL(instmt.ExpiryYear, 2016);
	BOOST_CHECK_EQUAL(instmt.OpenPrice, 19179);
	BOOST_CHECK_EQUAL(instmt.ClosePrice, 19241);
	BOOST_CHECK_EQUAL(instmt.ClosePriceChange, 152);
	BOOST_CHECK_EQUAL(instmt.DailyHigh, 19330);
	BOOST_CHECK_EQUAL(instmt.DailyLow, 19150);
	BOOST_CHECK_EQUAL(instmt.Volume, 435);
	BOOST_CHECK_EQUAL(instmt.OpenInterest, 9388);
	BOOST_CHECK_EQUAL(instmt.OpenInterestChange, 45);
}

BOOST_AUTO_TEST_SUITE_END()

