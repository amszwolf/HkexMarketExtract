/* 
 * File:   UtilConfigAccess.cpp
 * Author: Gavin Chan
 * 
 * Created on February 14, 2016, 12:25 AM
 */

#include "UtilConfigAccess.h"

#include <boost/regex.hpp>

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>

std::string CUtilConfigAccess::PATH = 
	std::string{getenv("HOME")} + "/config/HkexMarketExtract.config";

CUtilConfigAccess::CUtilConfigAccess() :
	_map()
{
}

CUtilConfigAccess::CUtilConfigAccess(std::string path) :
	_map()
{
	ReadFromPath(path);
}

CUtilConfigAccess::CUtilConfigAccess(const CUtilConfigAccess& orig) :
	_map(orig._map)
{
}

CUtilConfigAccess::~CUtilConfigAccess() {
}

bool CUtilConfigAccess::ReadFromPath(std::string path)
{
	using namespace std;
	using namespace boost;

	ifstream infile;
	infile.open(path.c_str());

	if (false == infile.is_open())
	{
		return false;
	}

	while(!infile.eof())
	{
		auto line = string{""};
		auto results = match_results<std::string::const_iterator>{};
		
		getline(infile, line);
		line = regex_replace(line, regex{"\\r"}, "");

		if (regex_match(line, results, regex{"(.*)=\"(.*)\""}) ||
			regex_match(line, results, regex{"(.*)=(.*)"}))
		{
			_map.insert({results[1].str(), results[2].str()});
		}
	}
	
	return true;
}


bool CUtilConfigAccess::GetValue(std::string key, std::string& value)
{
	if (_map.find(key) != _map.end())
	{
		value = _map[key];
		return true;
	}
	else
	{
		return false;
	}
}
std::string CUtilConfigAccess::GetValue(std::string key)
{
	std::string value = "";
	bool ret = GetValue(key, value);
	assert(ret);
	return value;
}