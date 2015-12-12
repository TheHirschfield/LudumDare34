
#include "Resources.h"

//Declare Resources
GSLTexture Resources::factoryBackground01;
GSLTexture Resources::playerIdle01;

GSLTexture Resources::uiHeartFull;
GSLTexture Resources::uiHeartEmpty;



//Load Resources
void Resources::load() {

	//Backgrounds
	factoryBackground01 = Texture::load("Assets/Sprites/Backgrounds/FactoryBackground01.png");
	
	//Player
	playerIdle01 = Texture::load("Assets/Sprites/Player/PlayerIdle.png");

	//UI
	uiHeartFull = Texture::load("Assets/UI/HeartFull.png");
	uiHeartEmpty = Texture::load("Assets/UI/HeartEmpty.png");



}