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

	//Player
	static GSLTexture playerIdle01;

	//UI
	static GSLTexture uiHeartFull;
	static GSLTexture uiHeartEmpty;

	/* Load Files Method */
	static void load();


};