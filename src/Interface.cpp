/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Interface.h"
#include "Resources.h"
#include "Player.h"
#include "World.h"

//Engine includes
#include "Engine\Engine.h"
#include "Engine\Texture.h"
#include "Engine\Controls.h"
#include "Engine\Text.h"

int Interface::menuTimeout;

float robotHight = 0;
int robotFloatDirection = 0;
int controlFade = 360;

void Interface::renderUI() {


	if (Engine::state == STATE_GAMEPLAY){ // Gameplay
		//Health
		for (int i = 0; i < 3; i++){
			if (i < Player::getHealth()){
				//Display Full Heart
				Texture::draw(Resources::uiHeartFull, 10 + i * 36, 10);
			} else{
				//Display Empty Heart
				Texture::draw(Resources::uiHeartEmpty, 10 + i * 36, 10);
			}

		}

		//Level Number
		std::string levelText = "Level " + std::to_string(World::getLevelNumber());
		Text::drawText(levelText, 1240 - 10, 4, Texture::colorSDL(255, 255, 255), Text::fontBold[3], 2);

		//Controls
		if (World::getLevelNumber() == 1 && controlFade > 0){
			Texture::draw(Resources::uiControls, 0, 0);
			controlFade--;
		}



		//Game Over
		if (Player::getHealth() == 0){
			Texture::draw(Resources::uiGameOver, 0, 0);
		} else if (World::gameFinished()){
			Texture::draw(Resources::uiYouWon, 0, 0);
		} else if (World::levelFinished()){
			Texture::draw(Resources::uiNextLevel, 0, 0);
		}
	} else{ // Main Menu

		//Background
		Texture::draw(Resources::factoryBackground06, 0, 0);
		Texture::draw(Resources::factoryBackground09, 640, 0);

		//Player
		Texture::draw(Resources::playerIdle01, 200 , 720 - 156 - 120, 1.0);
		Texture::draw(Resources::weaponRifle, 200, 720 - 156 - 120, 1.0);

		//Robots
		for (int i = 0; i < 5; i++){
			Texture::draw(Resources::enemyRobot, 450 + (i*110), 450 + robotHight + i, 1.0);
		}

		if (robotHight > -10 && robotFloatDirection == 0){
			robotHight -= 0.2;
		} else{
			robotFloatDirection = 1;
		}

		if (robotHight < 10 && robotFloatDirection == 1){
			robotHight += 1.0;
		} else{
			robotFloatDirection = 0;
		}

		//Logo
		Texture::draw(Resources::uiLogo, 570, 40);

		//Press Space
		Text::drawText("Press Space To Begin...", 1240 - 20, 670, Texture::colorSDL(255, 255, 255), Text::fontBold[3], 2);

		//Author
		Text::drawText("Created By Oliver Hirschfield. Twitter: @TheHirschfield", 10, 690, Texture::colorSDL(255, 255, 255), Text::fontLight[1], 0);


	}
}

void Interface::controlUI() {
	if (Controls::currentKeyStates[SDL_SCANCODE_SPACE] && menuTimeout == 0){
		Engine::changeState(STATE_LOADING);
	}

	if (menuTimeout > 0){
		menuTimeout--;
	}
}

void Interface::setMenuTimeout(int t) {
	menuTimeout = t;
}




