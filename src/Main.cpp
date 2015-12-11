/*
PROJECT: Ludum Dare 
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include <SDL.h>

/* Engine Includes */
#include "Engine\Engine.h"
#include "Engine\Graphics.h"


/* Main Fuctions */
void render();
void simulate();

int main(int argc, char *argv[]) {

	//Set Up Windows
	Graphics::createSDLVideoContext();
	Graphics::createNewWindow("Ludum Dare 34", 1240, 720);

	Engine::running = true;

	//State
	Engine::changeState(STATE_STARTUP);

	//Main Game Loop
	while (Engine::running){

		Engine::run();

		simulate();

		render();

	}

	Engine::quit();

	return 0;
}

void simulate() {




}

void render() {
	//Clear Previous Frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	//RENDER STUFF HERE


	//Apply New Frame
	SDL_GL_SwapWindow(Graphics::window);

}

