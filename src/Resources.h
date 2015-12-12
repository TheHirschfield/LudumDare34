#include "Engine\Texture.h"

class Resources{
public:

	/* Actual Files In Storage */
	//Background
	static GSLTexture factoryBackground01;

	//Player
	static GSLTexture playerIdle01;

	//UI
	static GSLTexture uiHeartFull;
	static GSLTexture uiHeartEmpty;

	/* Load Files Method */
	static void load();


};