/*
 * UtilDateTime.h
 *
 *  Created on: Oct 10, 2015
 *      Author: user
 */

#ifndef UTILDATETIME_H_
#define UTILDATETIME_H_

#include <boost/date_time/posix_time/posix_time.hpp>

class CUtilDateTime : public boost::posix_time::ptime
{
public:

	/**
	 * Copy constructor
	 * 
	 * @param pt ptime
	 */
	CUtilDateTime(boost::posix_time::ptime pt);
	
	/**
	 * Constructor
	 * @param date Gregorian date
	 * @param dur  Time duration
	 */
	CUtilDateTime(boost::gregorian::date date, boost::posix_time::ptime::time_duration_type dur);

	/**
	 * Constructor
	 * 
	 * @param years Gregorian year
	 * @param months Gregorian month
	 * @param days Gregorian day 
	 */
	CUtilDateTime(boost::gregorian::date::year_type years,
				  boost::gregorian::date::month_type months,
				  boost::gregorian::date::day_type days);

	/**
	 * Constructor
	 * 
	 * @param years Gregorian year
	 * @param months Gregorian month
	 * @param days Gregorian day 
	 * @param hour Hour
	 * @param minutes Minutes
	 * @param seconds Seconds
	 */
	CUtilDateTime(boost::gregorian::date::year_type years,
				  boost::gregorian::date::month_type months,
				  boost::gregorian::date::day_type days, 
				  int hour,
				  int minutes,
				  int seconds);

	/**
	 * Destructor
	 */
	virtual ~CUtilDateTime();

	// Convert boost date time to string

	/**
	 * Convert boost date time to string
	 * 
	 * @param time Posix time
	 * @param dateString Date string reference
	 * @param timeString Time string reference
	 */
	static void TimeConvertString(boost::posix_time::ptime time,
								  std::string &dateString,
								  std::string &timeString);

	/**
	 * Get the current time in string
	 * 
	 * @param date Date string reference
	 * @param time Time string reference
	 */
	static void GetCurrentTimeString(std::string &date,
							  		 std::string &time);

	static CUtilDateTime GetCurrentTime()
	{ return CUtilDateTime(boost::posix_time::microsec_clock::local_time());}

private:
	CUtilDateTime();
};

#endif /* UTILDATETIME_H_ */
