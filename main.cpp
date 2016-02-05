/* 
 * File:   main.cpp
 * Author: Gavin Chan
 *
 * Created on January 29, 2016, 11:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "UtilDateTime.h"
#include "UtilLogger.h"
#include "UtilHttpRequestHandler.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	Utllog.LogDebug("Started...");

	CUtilHttpRequestHandler req;
	std::string report;
	req.SendRequest("www.hkex.com.hk",
					"/eng/stat/dmstat/dayrpt/hsif160205.htm",
					report);

	std::cout << "Report:\n" << report;
	
    return 0;
}

