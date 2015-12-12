/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Pits.h"
#include "Resources.h"

#include "Engine\Texture.h"

void Pits::render(int x, int distance) {

	Texture::draw(Resources::pitFall, (620 * x) - distance, 720-214);

}