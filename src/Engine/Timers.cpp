/*
PROJECT: Game Studio Online Server
CREATED: 2nd June 2015
AUTHORS: Oliver Hirschfield
*/

#include "Timers.h"

#include <Windows.h>

//Time
time_t Timers::clientStartTime;
time_t Timers::stateStartTime;


double Timers::uptime;
double Timers::stateTime;


//Get Current Time
time_t Timers::getTime() {

	//Time Storage
	time_t rawtime;

	//Get Current Time
	time(&rawtime);

	//Return Time
	return rawtime;
}


std::string Timers::getDateString() {
	char buffer[80];

	time_t now = getTime();

	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&now));

	return buffer;
}

std::string Timers::getTimeString() {
	char buffer[80];

	time_t now = getTime();

	strftime(buffer, 80, "%H:%M:%S", localtime(&now));

	return buffer;
}

void Timers::start() {
	clientStartTime = getTime();
}

void Timers::newStateTimer() {
	stateStartTime = getTime();
}

//Run All Availiable Timers 
void Timers::run() {

	int pastTime = uptime;

	//Get New Uptime
	uptime = difftime(getTime(), clientStartTime);
	stateTime = difftime(getTime(), stateStartTime);
}


double Timers::getUptime() {
	return uptime;
}

double Timers::getStatetime() {
	return stateTime;
}