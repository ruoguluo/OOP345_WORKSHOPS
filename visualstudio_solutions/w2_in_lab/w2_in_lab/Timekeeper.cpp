/*
program: Timekeeper.cpp
programmer: yathavan, parameshwaran
date: January 21, 2019
description: workshop 2 in lab portion
*/

#include <iostream>
#include <chrono>
#include <string>
#include <cstring>

#include "Timekeeper.h"

using namespace std;

namespace sict
{
    Timekeeper::Timekeeper()
    {
		static int numberOfObjectsCreated = 0;
		numOfRecords = 0;
		record->messageString = nullptr;
		record->unitsOfTime = nullptr;
		numberOfObjectsCreated++;
    }

	void Timekeeper::start() 
    {
        startTime = chrono::steady_clock::now();
    }

    void Timekeeper::stop()
    {
        endTime = chrono::steady_clock::now();
    }

    void Timekeeper::recordEvent(const char* incomingStr)
    {
		static int counter = 0;
		const char* unitTime = "seconds";
		record[counter].messageString = incomingStr;
		record[counter].unitsOfTime = unitTime;
		auto returnTime = record->durationTime = chrono::duration_cast<chrono::seconds>(endTime - startTime);
		record[counter].durationTime = endTime - startTime;
		counter++;
		numOfRecords++;
    }

	void Timekeeper::report(std::ostream& incoming_ostream_object) const
	{
		incoming_ostream_object << "\nExecution Times:" << std::endl;
		for (int index = 0; index < numOfRecords; index++)
		{
			incoming_ostream_object << record[index].messageString;
			incoming_ostream_object << " ";
			incoming_ostream_object << record[index].durationTime.count();
			incoming_ostream_object << " ";
			incoming_ostream_object << record[index].unitsOfTime;
			incoming_ostream_object << "\n";
		}
	}
}


