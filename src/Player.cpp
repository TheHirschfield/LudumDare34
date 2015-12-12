/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Player.h"
#include "Resources.h"
#include "Lasers.h"
#include "Effects.h"

#include "Engine\Texture.h"
#include "Engine\Audio.h"
#include "Engine\Controls.h"
#include "Engine\Timers.h"

//Stats
int Player::health = 3;
int Player::power = 1;

//Actions
bool Player::isJumping;
bool Player::isMoving;

//Positions
float Player::posX, Player::posY;

int Player::deathType = 0;

int jumpCounter;
time_t jumpStartTime;

int shootCooldown;

void Player::reset() {

	//Stats
	health = 3;
	power = 1;

	//Mechanics
	isJumping = false;
	isMoving = false;

	jumpCounter = 0;

	//Positions
	posX = 0, posY = 0;

	Audio::playEffect("Assets/Sounds/Port.wav");
}


void Player::control() {

	//Jumping
	if (Controls::currentKeyStates[SDL_SCANCODE_SPACE] && !isJumping && Player::getHealth() > 0){
		isJumping = true;
		jumpStartTime = Timers::getTime();
		std::cout << "Jump. \n";
	}

	//Shooting
	if (Controls::isMouseButtonDown(1) && shootCooldown == 0 && Player::getHealth() > 0){
		if (!isJumping && !isMoving){
			Lasers::add(16);
			shootCooldown = 15;
			Audio::playEffect("Assets/Sounds/Rifle.wav");
			std::cout << "Shoot.\n";
		}
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
		if (posX < 1200){
			posX += 8.0;
		}
	}

	if (health <= 0){
		switch (deathType){
		case 1:
			if (posY == 0){
				Audio::playEffect("Assets/Sounds/Scream.wav");
			}
			if (posY < 720){
				posY += 8;
			}
			break;
		}
	}

}

void Player::render() {

	//Render Player
	if (Effects::getHurtTimer() ==  0){
		Texture::draw(Resources::playerIdle01, 100 + posX, 720 - 156 - 120 + posY, 1.0);
	} else{
		Texture::draw(Resources::playerHurt, 100 + posX, 720 - 156 - 120 + posY, 1.0);

	}
	//Render Weapon
	if (power == 1){ //Normal Laser Rifle
		Texture::draw(Resources::weaponRifle, 100 + posX, 720 - 156 - 120 + posY, 1.0);

	}


}

int Player::getHealth() {
	return health;
}

void Player::damageHealth() {
	if (health > 0){
		health--;
	}
}

void Player::setDeath(int type) {
	deathType = type;
}

int Player::getDeath() {
	return deathType;
}

bool Player::getJumping() {
	return isJumping;
}

void Player::setMoving(bool go) {
	isMoving = go;
}