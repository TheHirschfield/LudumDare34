/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/


#include "Resources.h"

//Declare Resources
GSLTexture Resources::factoryBackground01;
GSLTexture Resources::factoryBackground02;
GSLTexture Resources::factoryBackground03;
GSLTexture Resources::factoryBackground04;


GSLTexture Resources::pitFall;
GSLTexture Resources::pitFallMed;
GSLTexture Resources::pitFallLarge;


GSLTexture Resources::bulletRed;
GSLTexture Resources::bulletBlue;
GSLTexture Resources::bulletGreen;


GSLTexture Resources::enemyRobot;

GSLTexture Resources::playerIdle01;

GSLTexture Resources::weaponRifle;

GSLTexture Resources::uiHeartFull;
GSLTexture Resources::uiHeartEmpty;
GSLTexture Resources::uiGameOver;
GSLTexture Resources::uiNextLevel;
GSLTexture Resources::uiYouWon;



//Load Resources
void Resources::load() {

	//Backgrounds
	factoryBackground01 = Texture::load("Assets/Sprites/Backgrounds/FactoryBackground01.png");
	factoryBackground02 = Texture::load("Assets/Sprites/Backgrounds/FactoryBackground02.png");
	factoryBackground03 = Texture::load("Assets/Sprites/Backgrounds/FactoryBackground03.png");
	factoryBackground04 = Texture::load("Assets/Sprites/Backgrounds/FactoryBackground04.png");

	//Objects
	pitFall = Texture::load("Assets/Sprites/Objects/Pitfall.png");
	pitFallMed = Texture::load("Assets/Sprites/Objects/Pitfall2.png");
	pitFallLarge = Texture::load("Assets/Sprites/Objects/Pitfall3.png");

	//Entities
	bulletRed = Texture::load("Assets/Sprites/Entities/BulletRed.png");
	bulletBlue = Texture::load("Assets/Sprites/Entities/BulletBlue.png");
	bulletGreen = Texture::load("Assets/Sprites/Entities/BulletGreen.png");


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
	uiNextLevel = Texture::load("Assets/UI/NextLevel.png");
	uiYouWon = Texture::load("Assets/UI/YouWon.png");




}