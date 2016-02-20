/* 
 * File:   Instrument.h
 * Author: Gavin Chan
 *
 * Created on February 6, 2016, 9:50 AM
 */

#ifndef INSTRUMENT_H
#define	INSTRUMENT_H

#include "UtilDateTime.h"

#include <string>
#include <map>
#include <sstream>

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

	enum CallPut
	{
		CALL = 'C',
		PUT = 'P'
	};
	
	static std::map<std::string, int> ExpiryMonthMap;

	static std::map<int, std::string> ExpiryMonthReverseMap;
	
	std::string InstrumentName;
	
	CUtilDateTime DateTime;	
	
	Month ExpiryMonth;

	int ExpiryYear;
	
	PriceType Strike;
	
	PriceType OpenPrice;
	
	PriceType ClosePrice;
	
	PriceType DailyHigh;
	
	PriceType DailyLow;

	PriceType ClosePriceChange;
	
	VolumeType Volume;

	VolumeType OpenInterest;

	int	 OpenInterestChange;
	
	CallPut Type;

	/**
	 * Dump the instrument
	 * @param stream String stream
	 * @return true if success
	 */
	bool Dump(std::ostringstream& stream);

	/**
	 * Constructor 
	 */
    CInstrument() :
		InstrumentName(""),
		DateTime(1900, 1, 1),
		ExpiryMonth(DEF),
		ExpiryYear(1900),
		OpenPrice(0),
		ClosePrice(0),
		ClosePriceChange(0),
		DailyHigh(0),
		DailyLow(0),
		Volume(0),
		OpenInterest(0),
		OpenInterestChange(0),
		Type(CALL),
		Strike(0)
	{}
				
	/**
	 * Copy constructor 
	 * @param orig
	 */
    CInstrument(const CInstrument& orig) :
		InstrumentName(orig.InstrumentName),
		DateTime(orig.DateTime),
		ExpiryMonth(orig.ExpiryMonth),
		ExpiryYear(orig.ExpiryYear),
		OpenPrice(orig.OpenPrice),
		ClosePrice(orig.ClosePrice),
		ClosePriceChange(orig.ClosePriceChange),
		DailyHigh(orig.DailyHigh),
		DailyLow(orig.DailyLow),
		Volume(orig.Volume),
		OpenInterest(orig.OpenInterest),
		OpenInterestChange(orig.OpenInterestChange),
		Type(orig.Type),
		Strike(orig.Strike)
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

};

#endif	/* INSTRUMENT_H */

