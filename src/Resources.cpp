
#include "Resources.h"

//Declare Resources
GSLTexture Resources::factoryBackground01;
GSLTexture Resources::playerIdle01;
GSLTexture Resources::MenuButton01;


//Load Resources
void Resources::load() {

	//Backgrounds
	factoryBackground01 = Texture::load("Assets/Sprites/Backgrounds/FactoryBackground01.png");
	
	//Player
	playerIdle01 = Texture::load("Assets/Sprites/Player/PlayerIdle.png");


	//UI
	MenuButton01 = Texture::load("Assets/UI/MenuBarBlank.png");


}