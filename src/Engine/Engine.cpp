/*
PROJECT: Areigna Client
CREATED: 3rd August 2015
AUTHORS: Oliver Hirschfield
*/

#include "Engine.h"
#include "Controls.h"
#include "Timers.h"

bool Engine::running = false;
int Engine::state;

void Engine::run() {

	Timers::run();

	if (!Controls::poll()){
		Engine::running = false;
	}
}

void Engine::quit() {
	SDL_Quit();
}

void Engine::changeState(int s) {

	//General Changes
	state = s;
	Timers::newStateTimer();
	std::cout << "Game State Changed To: " << s << std::endl;

}