/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Lasers.h"
#include "Resources.h"

#include "Engine\Texture.h"

std::vector<bullet> Lasers::currentBullets;

void Lasers::add(int s) {

	bullet temp;

	temp.posX = 120.0;
	temp.speed = s;
	temp.alive = true;

	currentBullets.push_back(temp);

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
			Texture::draw(Resources::bulletRed, currentBullets[i].posX, 490);
		}
	}
}

void Lasers::destoryAll() {
	currentBullets.clear();
}