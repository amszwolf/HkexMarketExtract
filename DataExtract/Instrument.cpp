/* 
 * File:   FutureInstrument.cpp
 * Author: Gavin Chan
 * 
 * Created on February 12, 2016, 11:41 PM
 */

#include "Instrument.h"

#include <boost/regex.hpp>

using namespace boost;

std::map<std::string, int> CInstrument::ExpiryMonthMap = 
	{{"JAN", 1},
	 {"FEB", 2},
	 {"MAR", 3},
	 {"APR", 4},
	 {"MAY", 5},
	 {"JUN", 6},
	 {"JUL", 7},
	 {"AUG", 8},
	 {"SEP", 9},
	 {"OCT", 10},
	 {"NOV", 11},
	 {"DEC", 12}};

std::map<int, std::string> CInstrument::ExpiryMonthReverseMap = 
	{{1, "JAN"},
	 {2, "FEB"},
	 {3, "MAR"},
	 {4, "APR"},
	 {5, "MAY"},
	 {6, "JUN"},
	 {7, "JUL"},
	 {8, "AUG"},
	 {9, "SEP"},
	 {10, "OCT"},
	 {11, "NOV"},
	 {12, "DEC"}};


int CInstrument::ConvertStringToInt(std::string&& str) const
{
	auto sign = (str.find("-") == std::string::npos ? 1 : -1);
	auto px = regex_replace(str, 
							regex(","),
							"");
	px = regex_replace(px, regex("\\+"), "");
	px = regex_replace(px, regex("-"), "");
	
	return sign * atoi(px.c_str());
}

bool CInstrument::Dump(std::ostringstream& stream)
{
	using namespace std;

	stream << "InstrumentName = " << InstrumentName << endl;
	stream << "ExpiryMonth = " << ExpiryMonth << endl;
	stream << "ExpiryYear = " << ExpiryYear << endl;
	stream << "DateTime = " << DateTime << endl;
	stream << "OpenPrice = " << OpenPrice << endl;
	stream << "ClosePrice = " << ClosePrice << endl;
	stream << "DailyHigh = " << DailyHigh << endl;
	stream << "DailyLow = " << DailyLow << endl;
	stream << "ClosePriceChange = " << ClosePriceChange << endl;
	stream << "Volume = " << Volume << endl;
	stream << "OpenInterest = " << OpenInterest << endl;
	stream << "OpenInterestChange = " << OpenInterestChange << endl;

	return true;
}
	