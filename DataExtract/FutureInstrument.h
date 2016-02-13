/* 
 * File:   FutureInstrument.h
 * Author: Gavin Chan
 *
 * Created on February 9, 2016, 8:40 AM
 */

#ifndef CFUTUREINSTRUMENT_H
#define	CFUTUREINSTRUMENT_H

#include "Instrument.h"

class CFutureInstrument : public CInstrument 
{
 public:

	/**
	 * Constructor
	 */
    CFutureInstrument();

	/**
	 * Destructor
	 */
    virtual ~CFutureInstrument();


	virtual bool FromHkexString(std::string& hkex);

 private:

	/**
	 * Indices
	 */
	const size_t iExpiryMonth = 1;
	const size_t iExpiryYear = 2;
	const size_t iOpenPrice = 8;
	const size_t iDailyHigh = 9;
	const size_t iDailyLow = 10;
	const size_t iVolume = 11;
	const size_t iClosePrice = 12;
	const size_t iChangeClosePrice = 13;
	const size_t iOpenInterest = 17;
	const size_t iChangeOI = 18;
	
	/**
	 * Deleted copy constructor
	 * 
	 * @param orig
	 */
    CFutureInstrument(const CFutureInstrument& orig);

};

#endif	/* CFUTUREINSTRUMENT_H */

