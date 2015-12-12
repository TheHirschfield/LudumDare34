/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Effects.h"
#include "Resources.h"

#include "Engine\Texture.h"

std::vector<explosion> Effects::source;
int Effects::hurtEffect = 0;


void Effects::add(int x, int y) {

	explosion temp;

	temp.posX = x;
	temp.posY = y;
	temp.timeLeft = 15;

	source.push_back(temp);

}


void Effects::render() {

	for (int i = 0; i < source.size(); i++){
		if (source[i].timeLeft > 0){
			Texture::draw(Resources::effectExplode, source[i].posX, source[i].posY, 1.0);
			source[i].timeLeft--;
		}
	}

	if (hurtEffect > 0){
		hurtEffect--;
	}
	
}

int Effects::getHurtTimer() {
	return hurtEffect;
}

void Effects::setHurtTimer() {
	hurtEffect = 15;
}
