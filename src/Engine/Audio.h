#pragma once

#include <SDL_mixer.h>

#include <iostream>
#include <string>

class Audio
{
public:
	
	static bool initAudio();

	static void playEffect(std::string file);
	static void playMusic(std::string file);

private:
	static int generalVolume;
	static int musicVolume;
};

