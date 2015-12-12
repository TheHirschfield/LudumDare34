/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Player.h"
#include "Resources.h"
#include "Lasers.h"

#include "Engine\Texture.h"
#include "Engine\Controls.h"
#include "Engine\Timers.h"

//Stats
int Player::health = 10;
int Player::power = 5;

//Actions
bool Player::isJumping;
bool Player::isMoving;

//Positions
float Player::posX, Player::posY;

int jumpCounter;
time_t jumpStartTime;

int shootCooldown;

void Player::reset() {

	//Stats
	health = 10;
	power = 5;

	//Mechanics
	isJumping = false;
	isMoving = false;

	//Positions
	posX = 0, posY = 0;

}


void Player::control() {

	//Jumping
	if (Controls::currentKeyStates[SDL_SCANCODE_SPACE] && !isJumping){
		isJumping = true;
		jumpStartTime = Timers::getTime();
		std::cout << "Jump. \n";
	}

	//Shooting
	if (Controls::isMouseButtonDown(1) && shootCooldown == 0){
		Lasers::add(16);
		shootCooldown = 15;
		std::cout << "Shoot.\n";
	}
	

	if (shootCooldown > 0){
		shootCooldown--;
	}
}

void Player::move() {

	//Jumping
	if (isJumping){

		if (jumpCounter < 25){
			posY -= 5.0;
			jumpCounter++;
		} else if (posY < 0){

			posY += 4.0;
		} else{
			posY = 0;
			jumpCounter = 0;
			isJumping = false;
		}
	}

	//Moving Off Screen
	if (isMoving){
		if (posX < 1000){
			posX += 8.0;
		}
	}

}

void Player::render() {

	Texture::draw(Resources::playerIdle01, 100 + posX, 720 - 156 - 120 + posY, 1.0);

}


int Player::getHealth() {
	return health;
}

void Player::damageHealth() {
	if (health > 0){
		health--;
	}
}

bool Player::getJumping() {
	return isJumping;
}

void Player::setMoving(bool go) {
	isMoving = go;
}