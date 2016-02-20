/* 
 * File:   HkexExtractor.h
 * Author: Gavin Chan
 *
 * Created on February 14, 2016, 12:16 AM
 */

#ifndef CHKEXEXTRACTOR_H
#define	CHKEXEXTRACTOR_H

#include "FutureInstrument.h"
#include "UtilHttpRequestHandler.h"
#include "UtilMysqlClient.h"
#include "UtilConfigAccess.h"
#include "UtilLogger.h"
#include "UtilDateTime.h"

#include <vector>

class CHkexExtractor {
public:

	/**
	 * Initialization
	 * @return true if success 
	 */
	bool Initialize(int numberOfDays);

	/**
	 * Start to extract
	 * @return true if success 
	 */
	bool StartExtract();

	/**
	 * Constructor
	 */
    CHkexExtractor();

	/**
	 * Destructor
	 */
    virtual ~CHkexExtractor();
private:

	/**
	 * Extract instrument from string
	 * @param instmtPrefix Instrument prefix
	 * @param str Raw string
	 * @return true if success
	 */
	bool ExtractInstrumentFromString(std::string& instmtPrefix,
									 CUtilDateTime& dateTime,
									 std::string& str);
	
	bool InsertHistorialPx();
	
	int backDays;
		
	std::string hkexSite;

	std::string hkexSiteSuffix;
	
	std::string schemaName;
	
	std::string tableName;

	std::vector<std::string> underlyingList;
	
	std::vector<CInstrument> instrumentList;

	CUtilConfigAccess& config;

	CUtilHttpRequestHandler httpReq;

	CUtilMysqlClient mysqlClient;

	/**
	 * Copy constructor 
	 * @param orig Copied object
	 */
		
    CHkexExtractor(const CHkexExtractor& orig);
};

#endif	/* CHTMLEXTRACTOR_H */

