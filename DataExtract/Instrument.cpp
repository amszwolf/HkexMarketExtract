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