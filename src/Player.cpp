#include "Player.h"
#include "Resources.h"

#include "Engine\Texture.h"
#include "Engine\Controls.h"

//Stats
int Player::health;
int Player::power;

//Positions
float Player::posX, Player::posY;

void Player::control () {

	//Jumping
	if (Controls::currentKeyStates[SDL_SCANCODE_SPACE]){
		std::cout << "Jump. \n";
	}

	//Shooting
	if (Controls::isMouseButtonDown(1)){
		std::cout << "Shoot. \n";
	}

}

void Player::render() {

	Texture::draw(Resources::playerIdle01, 100 + posX, 480 + posY);
	
}
