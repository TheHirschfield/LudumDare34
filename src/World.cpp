
#include "World.h"
#include "Resources.h"

#include "Engine\Texture.h"

int World::level = 0 ;
int World::length = 0;
float World::speed;


float World::distance = 0.0;


bool World::set(int l) {

	level = l;

	switch (l){
	case 1:
		length = 20;
		speed = 10;
		break;
	default:
		return 0;
		break;
	}
	level = l;


	return 1;
}

void World::explore() {

	distance += speed;

}


void World::render() {

	for (int i = 0; i < length; i++){

		Texture::draw(Resources::factoryBackground01, 620 * i - distance, 0);
	}
	 

}