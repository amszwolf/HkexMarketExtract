/* 
 * File:   main.cpp
 * Author: Gavin Chan
 *
 * Created on January 29, 2016, 11:06 PM
 */

#include "DataExtract/HkexExtractor.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	Utllog.LogDebug("Started...");

	CHkexExtractor htmlExtractor;

	Utllog.LogDebug("Initializing html extractor.");
	htmlExtractor.Initialize();

	htmlExtractor.StartExtract();
	
    return 0;
}

