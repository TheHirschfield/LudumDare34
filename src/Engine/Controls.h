#pragma once

#include <SDL.h>

class Controls
{
public:

	//Current Key Input Storage
	static const Uint8* currentKeyStates;

	//Main Control Poll
	static bool poll();

	//Mouse Check Functions
	static int getMousePositionX();
	static int getMousePositionY();

	static bool isMouseButtonDown(int type);



private:

	//Mouse Position Storage
	static int GSLMousePositionX;
	static int GSLMousePositionY;

	//Mouse Button Storage
	static bool GSLMouseButtonLeft;
	static bool GSLMouseButtonRight;


};

