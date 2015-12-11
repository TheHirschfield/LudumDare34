/*
PROJECT: Areigna Client
CREATED: 3rd August 2015
AUTHORS: Oliver Hirschfield
*/

#include "Graphics.h"

//Window Management
SDL_Window* Graphics::window;
SDL_GLContext Graphics::context;

//Window Information
char* Graphics::screenTitle = "";
float Graphics::screenWidth = 0, Graphics::screenHeight = 0;

//Set Up SDL Video
void Graphics::createSDLVideoContext() {

	//Using SDL Video
	if (SDL_Init(SDL_INIT_VIDEO) == 0){
		std::cout << "SDL Initialisation Successful..." << std::endl;
	} else{
		std::cout << "SDL Initialisation Failed." << std::endl;
	}

	//Use OpenGL 3.1
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	//Use Hardware Acceleration
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	//Turn V-Sync On/Off
	SDL_GL_SetSwapInterval(1);

	//Multisampling
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);
}

//Create Game Window
void Graphics::createNewWindow(char* setTitle, int setWidth, int setHeight) {

	screenWidth = setWidth;
	screenHeight = setHeight;
	screenTitle = setTitle;

	//Create Window
	if (window = SDL_CreateWindow(screenTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)screenWidth, (int)screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)){
		std::cout << "Window Creation '" << screenTitle << "' Successful..." << std::endl;

		//Make Window Use OpenGL Context
		if (context = SDL_GL_CreateContext(window)){
			std::cout << "OpenGL Setup Successful..." << std::endl;
		} else{
			std::cout << "OpenGL Setup Failed..." << std::endl;
		}
	} else{
		std::cout << "Window Creation '" << screenTitle << "' Failed." << std::endl;
	}

	/* OpenGl View Settings */

	//Set Clear Color
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f); // Blue

	//Set Correct Depth Rendering
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//Set Correct View Port Options
	glViewport(0, 0, screenWidth, screenHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);

}

//Change 3D Background Color
void Graphics::changeRenderColor(float r, float g, float b) {
	glClearColor(r, g, b, 1.0f);
}