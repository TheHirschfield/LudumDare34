#pragma once

#include <SDL.h>
#include <GL\glew.h>
#include <SDL_opengl.h>

#include <iostream>

class Graphics
{
public:
	
	//Window Management
	static SDL_Window* window;
	static SDL_GLContext context;

	//Window Information
	static char* screenTitle;
	static float screenWidth;
	static float screenHeight;

	//Set Up SDL
	static void createSDLVideoContext();

	//Create Window
	static void createNewWindow(char* setTitle, int setWidth, int setHeight);
	static void destroyWindow();

	//Change Properties 
	static void changeRenderColor(float r, float g, float b);

};

