/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Pits.h"
#include "Resources.h"

#include "Engine\Texture.h"

void Pits::render(int size, int x, int distance) {

	switch (size){
	case 1:
		Texture::draw(Resources::pitFall, (640 * x) - distance, 0);
		break;
	case 2:
		Texture::draw(Resources::pitFallMed, (640 * x) - distance, 0);
		break;
	case 3:
		Texture::draw(Resources::pitFallLarge, (640 * x) - distance, 0);
		break;
	}

}