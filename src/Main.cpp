/*
PROJECT: Ludum Dare 
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include <SDL.h>

/* Engine Includes */
#include "Engine\Engine.h"
#include "Engine\Graphics.h"
#include "Engine\Audio.h"
#include "Engine\Text.h"
#include "Engine\Timers.h"


/* Game Includes  */
#include "Resources.h"
#include "Interface.h"
#include "World.h"
#include "Player.h"
#include "Lasers.h"


/* Main Fuctions */
void render();
void simulate();

int main(int argc, char *argv[]) {

	//Timers
	int lastTime = 0;
	float frameTimer = 0;

	//Set Up Windows
	Graphics::createSDLVideoContext();
	Graphics::createNewWindow("Ludum Dare 34", 1240, 720);

	Text::loadFonts();

	Audio::initAudio();

	//Load Graphical Resources
	Resources::load();

	Engine::running = true;

	//State
	Engine::changeState(STATE_STARTUP);

	//Main Game Loop
	while (Engine::running){

		const float FRAME_TIME = 1.0f / 60.0f;
		int dtMs = SDL_GetTicks() - lastTime;
		Timers::deltaTime = FRAME_TIME;
		frameTimer += dtMs / 1000.f;
		bool updated = false;

		while (frameTimer >= FRAME_TIME){
			Engine::run();

			frameTimer -= FRAME_TIME;
			updated = true;
		}

		if (updated){
			simulate();
			render();
		}

	}

	Engine::quit();

	return 0;
}

void simulate() {

	switch (Engine::state){
	case STATE_STARTUP:
		Audio::playMusic("Assets/Sounds/Menu.wav");
		Engine::changeState(STATE_MENU);
		break;
	case STATE_MENU:
		Interface::controlUI();
		break;
	case STATE_LOADING:
		World::set(1);
		Audio::playMusic("Assets/Sounds/Mission1.wav");
		Engine::changeState(STATE_GAMEPLAY);
		break;
	case STATE_GAMEPLAY:

		Player::control();
		Player::move();

		Lasers::move();

		World::explore();

		break;
	}


}

void render() {
	//Clear Previous Frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	//RENDER STUFF HERE
	switch (Engine::state){
	case STATE_STARTUP:

		break;
	case STATE_MENU:
		Interface::renderUI();
		break;
	case STATE_GAMEPLAY:

		World::render();

		Lasers::render();

		Player::render();
		Interface::renderUI();

		break;
	case STATE_ERROR:

		break;
	}

	//Apply New Frame
	SDL_GL_SwapWindow(Graphics::window);

}

