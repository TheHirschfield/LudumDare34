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
#include "Engine\Texture.h"
#include "Engine\Text.h"

void Interface::renderUI() {

	//Health
	for (int i = 0; i < 3; i++){
		if (i < Player::getHealth()){
			//Display Full Heart
			Texture::draw(Resources::uiHeartFull, 10 + i*36, 10);
		} else{
			//Display Empty Heart
			Texture::draw(Resources::uiHeartEmpty, 10 + i * 36, 10);
		}

	}

	//Level Number
	std::string levelText = "Level " + std::to_string(World::getLevelNumber());
	Text::drawText(levelText, 1240 - 10, 4, Texture::colorSDL(255, 255, 255), Text::fontBold[3], 2);


	//Game Over
	if (Player::getHealth() == 0){
		Texture::draw(Resources::uiGameOver, 0, 0);
	} else if (World::gameFinished()){
		Texture::draw(Resources::uiYouWon, 0, 0);
	} else if (World::levelFinished()){
		Texture::draw(Resources::uiNextLevel, 0, 0);
	}




}




