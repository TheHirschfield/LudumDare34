#include "Player.h"
#include "Resources.h"

#include "Engine\Texture.h"
#include "Engine\Controls.h"
#include "Engine\Timers.h"

//Stats
int Player::health;
int Player::power;

//Actions
bool Player::isJumping;
bool Player::isMoving;

//Positions
float Player::posX, Player::posY;

time_t jumpStartTime;


void Player::control() {

	//Jumping
	if (Controls::currentKeyStates[SDL_SCANCODE_SPACE] && !isJumping){
		isJumping = true;
		jumpStartTime = Timers::getTime();
		std::cout << "Jump. \n";
	}

	//Shooting
	if (Controls::isMouseButtonDown(1)){
		std::cout << "Shoot. \n";
	}

}

void Player::move() {

	//Jumping
	if (isJumping){

		if (Timers::compare(jumpStartTime, Timers::getTime()) < 1){
			posY -= 4.0;
		} else if (posY < 0){
			posY += 4.0;
		} else{
			isJumping = false;
		}
		std::cout << Timers::compare(jumpStartTime, Timers::getTime()) << "\n";
	}

	//Moving Off Screen
	if (isMoving){
		if (posX < 720){
			posX += 4.0;
		}
	}

}

void Player::render() {

	Texture::draw(Resources::playerIdle01, 100 + posX, 480 + posY);
	
}
