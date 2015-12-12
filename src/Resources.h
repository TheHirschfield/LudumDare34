#include "Engine\Texture.h"

class Resources{
public:

	/* Actual Files In Storage */
	//Background
	static GSLTexture factoryBackground01;
	static GSLTexture factoryBackground02;

	//Objects
	static GSLTexture pitFall;

	//Entities
	static GSLTexture bulletRed;

	//Enemies
	static GSLTexture enemyRobot;


	//Player
	static GSLTexture playerIdle01;

	//Weapons
	static GSLTexture weaponRifle;


	//UI
	static GSLTexture uiHeartFull;
	static GSLTexture uiHeartEmpty;
	static GSLTexture uiGameOver;


	/* Load Files Method */
	static void load();


};