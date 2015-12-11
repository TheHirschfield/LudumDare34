/*
PROJECT: Areigna Client
CREATED: 3rd August 2015
AUTHORS: Oliver Hirschfield
*/

#include "Controls.h"

//Main Event Handler 
SDL_Event eInput;

//Current Keyboard Inputs
const Uint8* Controls::currentKeyStates;

//Mouse Position
int Controls::GSLMousePositionX;
int Controls::GSLMousePositionY;

//Mouse States
bool Controls::GSLMouseButtonLeft;
bool Controls::GSLMouseButtonRight;

/* Poll For Key and Mouse Events  */
bool Controls::poll() {

	while (SDL_PollEvent(&eInput)){

		//Set Current Key Presses
		currentKeyStates = SDL_GetKeyboardState(NULL);

		//Set Mouse Position
		SDL_GetMouseState(&GSLMousePositionX, &GSLMousePositionY);

		//Mouse Controls
		if (eInput.type == SDL_MOUSEBUTTONDOWN){
			if (eInput.button.button == SDL_BUTTON_LEFT){
				GSLMouseButtonLeft = true;

			}
		}
		if (eInput.type == SDL_MOUSEBUTTONUP){
			GSLMouseButtonLeft = false;
			GSLMouseButtonRight = false;

		}

		//If (X) Button Is Pressed
		if (eInput.type == SDL_QUIT)
		{
			return 0;
		}
	}

	return 1;
}

/* Returns mouse x position. */
int Controls::getMousePositionX() {
	return GSLMousePositionX;
}

/* Returns mouse y position. */
int Controls::getMousePositionY() {
	return GSLMousePositionY;
}

/* Check if a certain mouse button is down. */
bool Controls::isMouseButtonDown(int type) {
	switch (type){
		case 1: // LEFT
			return GSLMouseButtonLeft;
			break;
		case 2: // RIGHT
			return GSLMouseButtonRight;
			break;
	}
	return 0;
}