/*
 * UtilDateTime.cpp
 *
 *  Created on: Oct 10, 2015
 *      Author: user
 */

#include "UtilDateTime.h"

#include <boost/algorithm/string.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;

CUtilDateTime::CUtilDateTime(ptime pt)
	: ptime(pt)
{
}

CUtilDateTime::CUtilDateTime()
{
}

CUtilDateTime::~CUtilDateTime() {
	// delete dateTimeFacetPtr;
}

CUtilDateTime::CUtilDateTime(boost::gregorian::date dt, ptime::time_duration_type dur)
	: ptime(dt, dur)
{
}

CUtilDateTime::CUtilDateTime(
			  date::year_type years,
			  date::month_type months,
			  date::day_type days)
	: ptime(boost::gregorian::date(years, months, days))
{
}

CUtilDateTime::CUtilDateTime(boost::gregorian::date::year_type years,
						     boost::gregorian::date::month_type months,
						     boost::gregorian::date::day_type days, 
						     int hour,
						     int minutes,
						     int seconds)
	: ptime(boost::gregorian::date(years, months, days),
			time_duration(hour, minutes, seconds))
{
}

void CUtilDateTime::TimeConvertString(ptime time,
									  std::string &dateString,
									  std::string &timeString)
{
	std::string dateTime = to_iso_extended_string(time);
	boost::replace_all(dateTime, "-", "");
	boost::replace_all(dateTime, ",", ".");
	dateString = dateTime.substr(0, 8);
	timeString = dateTime.substr(9, 15);
}


void CUtilDateTime::GetCurrentTimeString(std::string &date,
										 std::string &time)
{
	TimeConvertString(microsec_clock::local_time(), date, time);
}

