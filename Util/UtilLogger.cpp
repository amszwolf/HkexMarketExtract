/*
 * UtilLogger.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: user
 */

#include "UtilLogger.h"
#include "UtilDateTime.h"
#include <stdlib.h>

#include <boost/range/algorithm_ext/erase.hpp>

using boost::format;

CUtilLogger& Utllog = CUtilLogger::Instance();

CUtilLogger::CUtilLogger()
	: _consoleAppender(new ConsoleAppender()),
	  _fileAppender(new FileAppender(GetLogName())),
	  _consoleAppenderLayout(new PatternLayout(_pattern)),
	  _fileAppenderLayout(new PatternLayout(_pattern)),
	  _logger(Logger::getInstance("logger"))
{
	_consoleAppender->setName("Console appender");
	_fileAppender->setName("File appender");
	_consoleAppender->setLayout(_consoleAppenderLayout);
	_fileAppender->setLayout(_fileAppenderLayout);

	_logger.addAppender(_consoleAppender);
	_logger.addAppender(_fileAppender);

	LOG4CPLUS_DEBUG(_logger, "Utillogger initialized.");
}

CUtilLogger::~CUtilLogger() {
}

CUtilLogger &CUtilLogger::Instance()
{
	static CUtilLogger instance;
	return instance;
}

void CUtilLogger::LogDebug(const char* msg)
{
	if (0 == strlen(msg))
	{
		msg = this->Dump().c_str();
	}

	LOG4CPLUS_DEBUG(_logger, msg);
}

void CUtilLogger::LogWarning(const char* msg)
{
	if (0 == strlen(msg))
	{
		msg = this->Dump().c_str();
	}

	LOG4CPLUS_WARN(_logger, msg);
}

void CUtilLogger::LogTrace(const char* msg)
{
	if (0 == strlen(msg))
	{
		msg = this->Dump().c_str();
	}

	LOG4CPLUS_TRACE(_logger, msg);
}

void CUtilLogger::LogInfo(const char* msg)
{
	if (0 == strlen(msg))
	{
		msg = this->Dump().c_str();
	}

	LOG4CPLUS_INFO(_logger, msg);
}

const char* CUtilLogger::GetLogName()
{
	std::string currDate;
	std::string currTime;
	CUtilDateTime::GetCurrentTimeString(currDate, currTime);
	boost::erase_all(currTime, ":");
	return (std::string{getenv("HOME")} + "/log/" +
		   GetProcessName() + "_" +
		   currDate + "_" +
		   currTime.substr(0, 6)).c_str();
}
