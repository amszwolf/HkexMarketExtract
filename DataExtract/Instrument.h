/* 
 * File:   Instrument.h
 * Author: Gavin Chan
 *
 * Created on February 6, 2016, 9:50 AM
 */

#ifndef INSTRUMENT_H
#define	INSTRUMENT_H

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
	
	std::string InstrumentName;
	
	Month ExpiryMonth;

	int ExpiryYear;
	
	double OpenPrice;
	
	double ClosePrice;
	
	double DailyHigh;
	
	double DailyLow;
	
	long Volume;

	long OpenInterest;

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
    virtual ~CInstrument();

private:
	/**
	 * Copy constructor 
	 * @param orig
	 */
    CInstrument(const CInstrument& orig);

};

#endif	/* INSTRUMENT_H */

