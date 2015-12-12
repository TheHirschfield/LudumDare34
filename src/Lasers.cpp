/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Lasers.h"
#include "Resources.h"

#include "Engine\Texture.h"

std::vector<bullet> Lasers::currentBullets;

int nextColor = 1;

void Lasers::add(int s) {

	bullet temp;

	temp.color = nextColor;
	temp.posX = 120.0;
	temp.speed = s;
	temp.alive = true;

	currentBullets.push_back(temp);

	nextColor++;
	if (nextColor > 3){
		nextColor = 1;
	}

	std::cout << "Current Bullet Count: " << currentBullets.size() << "\n";

}

void Lasers::move() {

	for (int i = 0; i < currentBullets.size(); i++){
		if (currentBullets[i].posX < 1200 && currentBullets[i].alive){
			currentBullets[i].posX += currentBullets[i].speed;
		} else if (currentBullets[i].alive){
			currentBullets[i].alive = false;
			std::cout << "Bullet Destoryed: " << currentBullets.size() << "\n";
		}
	}
}

void Lasers::render() {
	
	for (int i = 0; i < currentBullets.size(); i++){
		if (currentBullets[i].alive){
			switch (currentBullets[i].color){
			case 1: //Red
				Texture::draw(Resources::bulletRed, currentBullets[i].posX, 490);
				break;
			case 2: //Blue
				Texture::draw(Resources::bulletBlue, currentBullets[i].posX, 490);
				break;
			case 3: //Green
				Texture::draw(Resources::bulletGreen, currentBullets[i].posX, 490);
				break;

			}
		}
	}
}

void Lasers::destroy(int l) {
	currentBullets[l].alive = false;
	currentBullets[l].posX = 1200;
	std::cout << "Bullet Destoryed: " << l << "\n";

}

void Lasers::destoryAll() {
	currentBullets.clear();
}


int Lasers::getTotal() {
	return currentBullets.size();
}

int Lasers::getBulletLocation(int x) {

	if (x < currentBullets.size()){
		if (currentBullets[x].alive){
			return currentBullets[x].posX;
		}
	}

	return 0;
}