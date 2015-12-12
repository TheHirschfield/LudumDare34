/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/


#include "World.h"
#include "Resources.h"
#include "Player.h"
#include "MrRobot.h"
#include "Pits.h"

#include "Engine\Texture.h"

int World::levelNumber = 0;
level World::levelData;
float World::distance = 0.0;

int distanceTraveled = 1;

bool World::endLevel = false;


level World::create(int l, float s, std::vector<int> d, std::vector<int> o, std::vector<int> e) {

	level temp;

	temp.length = l;
	temp.speed = s;

	temp.data = d;
	temp.objects = o;
	temp.enemies = e;

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

std::vector<int> World::readEnemies(std::string file) {

	std::string filename = "Assets/Levels/" + file + "/Enemies.txt";

	//Open File
	std::ifstream f(filename);

	std::string input;
	std::vector<int> temp;

	int lineCount = 1;

	//Reads Line By Line
	while (std::getline(f, input)){
		if (input[0] == '1'){
			temp.push_back(std::stoi(input));
			MrRobot::add(lineCount * 620);
		}
		lineCount++;
	}

	f.close();

	return temp;
}


bool World::set(int l) {

	//Reset Player Info
	Player::reset();

	levelNumber = l;

	endLevel = false;

	switch (l){
	case 1:
		levelData = create(20, 5, readLevel("1"), readObjects("1"), readEnemies("1"));
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

		distanceTraveled = distance / 1280;

	} else if (endLevel == false){
		Player::setMoving(true);
		endLevel = true;
	}

	//Object Collision
	for (int i = 0; i < levelData.data.size(); i++){

		//Pitfall Collision
		if (levelData.objects[i] == 1){
			//if (distance >(640 * (i-1)) - 16 && distance < (640 * (i-1)) + 40 - 32){
			if (distance > (620 * i) + 180 && distance < (620 * i) + 210){
				if (!Player::getJumping()){
					Player::damageHealth();
					std::cout << "Damage at " << Player::getHealth() << "!\n";
				}
			}
		}
	}

	//Enemy Spawn
	MrRobot::run(distance);

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
		

		//Robot Rendering
		MrRobot::render(distance);

	}
	
}

int World::getEnemiesSpawned() {

	//Temp Variable
	int total = 0;

	//Adding For Loop
	for(int i = 0; i < distanceTraveled; i++){
 		if (levelData.enemies[i] != 0){
			total++;
		}
	}

	//Return
	return total;
}