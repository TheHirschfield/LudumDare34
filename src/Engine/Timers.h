#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <iostream>
#include <string>

class Timers
{
public:

	//Get Current Time
	static time_t getTime();
	static std::string getDateString();
	static std::string getTimeString();

	//Begin Time Management
	static void start();
	static void newStateTimer();

	//Run Timers
	static void run();

	static double getUptime();
	static double getStatetime();


private:
	//Timer Storage Variables
	static double uptime;
	static double stateTime;
	static time_t clientStartTime;
	static time_t stateStartTime;
	static std::string serverTime;

};

