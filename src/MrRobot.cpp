/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "MrRobot.h"
#include "Resources.h"

#include "Engine\Texture.h"

MrRobot::MrRobot() {

	health = 20;
	damage = 1;

	posX = 1000;
	posY = 450;

}


void MrRobot::render() {
	if (health > 0){
		Texture::draw(Resources::enemyRobot, posX, posY, 1.0);
	}
}

