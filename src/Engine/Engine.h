#pragma once

#include <SDL.h>

#include <iostream>
#include <string>

//Game State Types
enum states_t { STATE_DEBUG, STATE_STARTUP, STATE_VIDEO, STATE_LOGIN, STATE_MENU, STATE_LOADING, STATE_GAMEPLAY, STATE_ERROR };

class Engine
{
public:

	static bool running;
	static int state;

	//Core Event Methods
	static void run();
	static void poll();

	static void changeState(int s);

	//Game Running Methods
	static void quit();

	
};

