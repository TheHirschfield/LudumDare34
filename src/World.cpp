/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/


#include "World.h"
#include "Resources.h"
#include "Player.h"
#include "Pits.h"

#include "Engine\Texture.h"

int World::levelNumber = 0;
level World::levelData;
float World::distance = 0.0;

bool World::endLevel = false;


level World::create(int l, float s, std::vector<int> d, std::vector<int> o) {

	level temp;

	temp.length = l;
	temp.speed = s;

	temp.data = d;
	temp.objects = o;

	return temp;
}

std::vector<int> World::readLevel(std::string file) {

	std::string filename = "Assets/Levels/" + file + "/Tiles.txt";

	//Open File
	std::ifstream f(filename);

	std::string input;
	std::vector<int> temp;

	int readingMode = 0;

	//Reads Line By Line
	while (std::getline(f, input)){

		if (readingMode == 0){
			temp.push_back(std::stoi(input));
		}
	}

	f.close();

	return temp;
}

std::vector<int> World::readObjects(std::string file) {

	std::string filename = "Assets/Levels/" + file + "/Objects.txt";

	//Open File
	std::ifstream f(filename);

	std::string input;
	std::vector<int> temp;

	int readingMode = 0;

	//Reads Line By Line
	while (std::getline(f, input)){

		if (readingMode == 0){
			temp.push_back(std::stoi(input));
		}
	}

	f.close();

	return temp;
}

bool World::set(int l) {

	levelNumber = l;

	endLevel = false;

	switch (l){
	case 1:
		levelData = create(20, 5, readLevel("1"), readObjects("1"));
		break;
	default:
		return 0;
		break;
	}
	levelNumber = l;


	return 1;
}

void World::explore() {
	
	//Move Tileset
	if (distance < ((levelData.data.size()-2) * 620)){
		distance += levelData.speed;
	} else if (endLevel == false){
		Player::setMoving(true);
		endLevel = true;
	}

	//Object Collision
	for (int i = 0; i < levelData.data.size(); i++){

		//Pitfall Collision
		if (levelData.objects[i] == 1){
			//if (distance >(640 * (i-1)) - 16 && distance < (640 * (i-1)) + 40 - 32){
			if (distance >(620 * i) - 380 && distance < (620 * i) - 350){
				if (!Player::getJumping()){
					Player::damageHealth();
					std::cout << "Damage at " << i << "!\n";
				}
			}
		}
	}
}


void World::render() {

	//RENDERING
	for (int i = 0; i < levelData.data.size(); i++){
		//Tile Rendering
		switch (levelData.data[i]){
		case 1:
			Texture::draw(Resources::factoryBackground01, 620 * i - distance, 0);
			break;
		case 2:
			Texture::draw(Resources::factoryBackground02, 620 * i - distance, 0);
			break;
		}
		
		//Object Rendering

		switch (levelData.objects[i]){
		case 1:
			Pits::render(i, distance);
			break;
		}
			
	}
	 

}