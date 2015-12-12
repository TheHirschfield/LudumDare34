/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Interface.h"
#include "Resources.h"
#include "Player.h"

//Engine includes
#include "Engine\Texture.h"

void Interface::renderUI() {

	//Health
	for (int i = 0; i < 10; i++){
		if (i < Player::getHealth()){
			//Display Full Heart
			Texture::draw(Resources::uiHeartFull, 10 + i*36, 10);
		} else{
			//Display Empty Heart
			Texture::draw(Resources::uiHeartEmpty, 10 + i * 36, 10);
		}

	}

	//Game Over
	if (Player::getHealth() == 0){
		Texture::draw(Resources::uiGameOver, 0, 0);
	}
}




