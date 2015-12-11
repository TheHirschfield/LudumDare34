/*
PROJECT: Areigna Client
CREATED: 6th August 2015
AUTHORS: Oliver Hirschfield
*/

#include "Audio.h"

//Volumes
int Audio::generalVolume;
int Audio::musicVolume;

bool Audio::initAudio() {

	Mix_Init(MIX_INIT_OGG);

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
		std::cout << "Could Not Initalise Audio System" << std::endl;
		return false;
	} else{
		std::cout << "Initalised Audio System" << std::endl;
	}

	//Get From Options
	generalVolume = 10;
	musicVolume = 10;

	//Set Effect Volume
	Mix_Volume(-1, generalVolume * 12);

	//Set Music Volume
	Mix_VolumeMusic((int)((musicVolume * 12) * ((float)generalVolume / 10.f)));

	return true;
}

void Audio::playEffect(std::string file) {
	
	Mix_Chunk* effect;
	effect = Mix_LoadWAV(file.c_str());
	Mix_Volume(-1, generalVolume * 12);
	Mix_PlayChannel(-1, effect, 0);
}

void Audio::playMusic(std::string file) {
	if (Mix_PlayingMusic() == 0)
	{
		Mix_Music* effect;
		effect = Mix_LoadMUS(file.c_str());
		Mix_PlayMusic(effect, -1);

		Mix_VolumeMusic((int)((musicVolume * 12) * ((float)generalVolume / 10.f)));
	}
}