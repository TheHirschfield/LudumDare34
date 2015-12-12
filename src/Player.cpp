#include "Player.h"
#include "Resources.h"

#include "Engine\Texture.h"

//Stats
int Player::health;
int Player::power;

//Positions
float Player::posX, Player::posY;

void Player::render() {

	Texture::draw(Resources::playerIdle01, 100, 480);
	
}
