/* 
 * File:   Instrument.h
 * Author: Gavin Chan
 *
 * Created on February 6, 2016, 9:50 AM
 */

#ifndef INSTRUMENT_H
#define	INSTRUMENT_H

#include <string>
#include <map>

typedef double PriceType;
typedef long VolumeType;

class CInstrument {
public:
	enum Month
	{
		DEF = 0,
		JAN = 1,
		FEB = 2,
		MAR = 3,
		APR = 4,
		MAY = 5,
		JUN = 6,
		JUL = 7,
		AUG = 8,
		SEP = 9,
		OCT = 10,
		NOV = 11,
		DEC = 12
	};	
	
	static std::map<std::string, int> ExpiryMonthMap;
	
	std::string InstrumentName;
	
	Month ExpiryMonth;

	int ExpiryYear;
	
	PriceType OpenPrice;
	
	PriceType ClosePrice;
	
	PriceType DailyHigh;
	
	PriceType DailyLow;

	PriceType ClosePriceChange;
	
	VolumeType Volume;

	VolumeType OpenInterest;

	int	 OpenInterestChange;
	
	/**
	 * Constructor 
	 */
    CInstrument() :
		InstrumentName(""),
		ExpiryMonth(DEF),
		ExpiryYear(1900),
		OpenPrice(0),
		ClosePrice(0),
		DailyHigh(0),
		DailyLow(0),
		Volume(0),
		OpenInterest(0),
		OpenInterestChange(0)
	{}
				

	/**
	 * Destructor
	 */
    virtual ~CInstrument() {}

protected:

	/**
	 * Convert string to int
	 * 
	 * @param str 	Raw text
	 * @return Converted value
	 */
	int ConvertStringToInt(std::string&& str) const;

private:
	/**
	 * Copy constructor 
	 * @param orig
	 */
    CInstrument(const CInstrument& orig);

};

#endif	/* INSTRUMENT_H */

