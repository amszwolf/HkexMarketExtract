/* 
 * File:   FutureInstrument.cpp
 * Author: Gavin Chan
 * 
 * Created on February 9, 2016, 8:40 AM
 */

#include "FutureInstrument.h"

#include <boost/regex.hpp>

#include <iostream>

using namespace std;

CFutureInstrument::CFutureInstrument() :
	CInstrument()
{
}

CFutureInstrument::CFutureInstrument(const CFutureInstrument& orig) {
}

CFutureInstrument::~CFutureInstrument() {
}

bool CFutureInstrument::FromHkexString(string& hkex)
{
	using namespace boost;

	// =============================================
	// Define the regex
	// =============================================
	// 1. Define expiry month and year
	auto regexStr = string{"([A-Z]{3})-(\\d{2})"};

	// 2. Define after-hour trading session
	for (int i = 0; i < 5; i++)
	{
		regexStr += "\\s+(\\+?-?\\d+,?\\d+)";
	}

	// 3. Define day trading session
	regexStr += "\\s+\\|";
	for (int i = 0; i < 6; i++)
	{
		regexStr += "\\s+(\\+?-?\\d+,?\\d+)";
	}

	// 4. Define combined
	regexStr += "\\s+\\|";
	for (int i = 0; i < 5; i++)
	{
		regexStr += "\\s+(\\+?-?\\d+,?\\d+)";
	}

	regexStr += ".*";

	// =============================================
	// Search for text
	// =============================================
	auto rgx = regex(regexStr);

	match_results<std::string::const_iterator> results;

	if(regex_match(hkex, results, rgx))
	{
		// Parsing expiry month
		auto monthString = results[iExpiryMonth].str();
		if (ExpiryMonthMap.end() != 
			ExpiryMonthMap.find(monthString))
		{
			ExpiryMonth = static_cast<Month>(ExpiryMonthMap[monthString]);
		}

		// Parsing expiry year
		auto yearString = results[iExpiryYear].str();
		ExpiryYear = atoi(yearString.c_str()) + 2000;

		// Parsing all values
		OpenPrice = ConvertStringToInt(results[iOpenPrice].str());
		ClosePrice = ConvertStringToInt(results[iClosePrice].str());
		ClosePriceChange = ConvertStringToInt(results[iChangeClosePrice].str());
		DailyHigh = ConvertStringToInt(results[iDailyHigh].str());
		DailyLow = ConvertStringToInt(results[iDailyLow].str());
		Volume = ConvertStringToInt(results[iVolume].str());
		OpenInterest = ConvertStringToInt(results[iOpenInterest].str());
		OpenInterestChange = ConvertStringToInt(results[iChangeOI].str());
	}
	else
	{
		return false;
	}

	return true;
}
