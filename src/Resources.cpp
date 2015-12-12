
#include "Resources.h"

//Declare Resources
GSLTexture Resources::factoryBackground01;

GSLTexture Resources::MenuButton01;


//Load Resources
void Resources::load() {

	factoryBackground01 = Texture::load("Assets/Sprites/Backgrounds/FactoryBackground01.png");
	MenuButton01 = Texture::load("Assets/UI/MenuBarBlank.png");


}