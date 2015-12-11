/*
PROJECT: Areigna Client
CREATED: 30th September 2015
AUTHORS: Oliver Hirschfield
*/

#include "Window.h"
#include "Texture.h"
#include "Text.h"

int Window::currentLayer;

GSLTexture WindowSys400;
GSLTexture WindowSys200;


void Window::loadTypes() {

	WindowSys400 = Texture::load("Assets/UI/Windows/System400x400.png"); //Normal Sized Windows
	WindowSys200 = Texture::load("Assets/UI/Windows/System400x200.png"); //Error Sized Windows


}

void Window::draw(int type, std::string title, int x, int y) {

	GSLTexture tempWindow;
	int titleX = x, titleY = y;

	switch (type){
	case 1: //400x400
		tempWindow = WindowSys400;
		titleX += 4; titleY += 2;
		break;
	case 2: //400x200
		tempWindow = WindowSys200;
		titleX += 4; titleY += 2;
		break;
	default: //400x400
		tempWindow = WindowSys400;
		titleX += 4; titleY += 2;
		title = "UNKNOWN WINDOW";
		break;
	}

	Texture::draw(tempWindow, x, y, 1.0);
	Text::drawText(title, titleX, titleY, Texture::colorSDL(255,255,255));
}