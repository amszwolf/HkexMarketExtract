/*
 * UtilLogger.h
 *
 *  Created on: Oct 13, 2015
 *      Author: user
 */

#ifndef UTILLOGGER_H_
#define UTILLOGGER_H_
#include "UtilDateTime.h"

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/layout.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

class CUtilLogger
{
public:
	static CUtilLogger &Instance();

	/**
	 * Log at debug level
	 * 
	 * @param msg Log message
	 */
	void LogDebug(const char* msg);

	/**
	 * Log at warning level
	 * 
	 * @param msg Log message
	 */
	void LogWarning(const char* msg);

	/**
	 * Log at trace level
	 * 
	 * @param msg Log message
	 */
	void LogTrace(const char* msg);

	/**
	 * Log at info level
	 * 
	 * @param msg Log message
	 */
	void LogInfo(const char* msg);

	static const char* GetLogName();
	
	static const char* GetProcessName() { return "HkexMarketExtract"; }

private:
	CUtilLogger();
	virtual ~CUtilLogger();

	static constexpr const char* _pattern = "%d{%Y%m%d %H:%M:%S.%q} - [%M:%F:%L]%n%m%n%n";

	SharedObjectPtr<Appender> _consoleAppender;
	SharedObjectPtr<Appender> _fileAppender;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	std::auto_ptr<Layout> _consoleAppenderLayout;
	std::auto_ptr<Layout> _fileAppenderLayout;
#pragma GCC diagnostic pop

	Logger _logger;
};

extern CUtilLogger& Utllog;

#endif /* UTILLOGGER_H_ */
