/* 
 * File:   main.cpp
 * Author: Gavin Chan
 *
 * Created on January 29, 2016, 11:06 PM
 */

#include "DataExtract/HkexExtractor.h"

using namespace std;

bool Validation(int& argc, char**& argv, int& numberDays)
{
	if (argc == 2 || argc > 3)
	{
		Utllog << "Invalid number of arguments : " << argc;
		Utllog.LogWarning();
		return false;
	}

	if (argc == 3 && strcmp(argv[1], "-d") == 0)
	{
		numberDays = atoi(argv[2]);
		if (numberDays <= 0)
		{
			Utllog << "Invalid number of days : " << numberDays;
			Utllog.LogWarning();
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv) 
{
	int numberOfDays = 60;
	if (false == Validation(argc, argv, numberOfDays))
	{
		return -1;
	}

	Utllog.LogInfo("Started...");

	CHkexExtractor htmlExtractor;

	Utllog.LogInfo("Initializing html extractor.");
	if (false == htmlExtractor.Initialize(numberOfDays))
	{
		Utllog.LogWarning("Failed to initialize the extractor.");
		return -1;
	}

	Utllog.LogInfo("Start to extract.");
	htmlExtractor.StartExtract();
	
	Utllog.LogInfo("Process ended.");

    return 0;
}

