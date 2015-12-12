/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/


#include "Resources.h"

//Declare Resources
GSLTexture Resources::factoryBackground01;
GSLTexture Resources::factoryBackground02;

GSLTexture Resources::pitFall;

GSLTexture Resources::bulletRed;

GSLTexture Resources::enemyRobot;

GSLTexture Resources::playerIdle01;

GSLTexture Resources::weaponRifle;

GSLTexture Resources::uiHeartFull;
GSLTexture Resources::uiHeartEmpty;
GSLTexture Resources::uiGameOver;


//Load Resources
void Resources::load() {

	//Backgrounds
	factoryBackground01 = Texture::load("Assets/Sprites/Backgrounds/FactoryBackground01.png");
	factoryBackground02 = Texture::load("Assets/Sprites/Backgrounds/FactoryBackground02.png");

	//Objects
	pitFall = Texture::load("Assets/Sprites/Objects/Pitfall.png");

	//Entities
	bulletRed = Texture::load("Assets/Sprites/Entities/BulletRed.png");

	//Enemies
	enemyRobot = Texture::load("Assets/Sprites/Entities/Robot1.png");

	//Player
	playerIdle01 = Texture::load("Assets/Sprites/Player/PlayerIdle.png");

	//Weapon
	weaponRifle = Texture::load("Assets/Sprites/Player/Weapons/Gun1.png");

	//UI
	uiHeartFull = Texture::load("Assets/UI/HeartFull.png");
	uiHeartEmpty = Texture::load("Assets/UI/HeartEmpty.png");
	uiGameOver = Texture::load("Assets/UI/GameOver.png");




}