#include "Engine\Texture.h"

class Resources{
public:

	/* Actual Files In Storage */

	//Background
	static GSLTexture nightSky;
	static GSLTexture factoryBackground01;
	static GSLTexture factoryBackground02;
	static GSLTexture factoryBackground03;
	static GSLTexture factoryBackground04;
	static GSLTexture factoryBackground05;
	static GSLTexture factoryBackground06;
	static GSLTexture factoryBackground07;
	static GSLTexture factoryBackground08;
	static GSLTexture factoryBackground09;

	//Objects
	static GSLTexture pitFall;
	static GSLTexture pitFallMed;
	static GSLTexture pitFallLarge;

	//Entities
	static GSLTexture bulletRed;
	static GSLTexture bulletBlue;
	static GSLTexture bulletGreen;

	//Enemies
	static GSLTexture enemyRobot;


	//Player
	static GSLTexture playerIdle01;
	static GSLTexture playerHurt;


	//Weapons
	static GSLTexture weaponRifle;

	//UI
	static GSLTexture uiLogo;
	static GSLTexture uiControls;
	static GSLTexture uiHeartFull;
	static GSLTexture uiHeartEmpty;
	static GSLTexture uiGameOver;
	static GSLTexture uiNextLevel;
	static GSLTexture uiYouWon;

	//Effect
	static GSLTexture effectExplode;


	/* Load Files Method */
	static void load();


};