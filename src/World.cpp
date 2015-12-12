/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/


#include "World.h"
#include "Resources.h"
#include "Player.h"
#include "MrRobot.h"
#include "Lasers.h"
#include "Effects.h"

#include "Pits.h"

#include "Engine\Engine.h"
#include "Engine\Texture.h"
#include "Engine\Audio.h"
#include "Engine\Controls.h"

int World::levelNumber = 0;
level World::levelData;
float World::distance = 0.0;

int distanceTraveled = 1;

bool World::endLevel = false;
bool World::gameWon = false;
int endLevelTimer = 0;


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
			std::cout << "Added New Robot at: " << lineCount * 620 << "\n";
		}else if (input[0] == '2'){
			temp.push_back(std::stoi(input));
			MrRobot::add(lineCount * 620);
			MrRobot::add(lineCount * 620+100);

			std::cout << "Added 2 New Robots at: " << lineCount * 620 << "\n";
		} else if (input[0] == '3'){
			temp.push_back(std::stoi(input));
			MrRobot::add(lineCount * 620);
			MrRobot::add(lineCount * 620 + 100);
			MrRobot::add(lineCount * 620 + 300);

			std::cout << "Added 3 New Robots at: " << lineCount * 620 << "\n";
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
	endLevelTimer = 0;

	distance = 0.0;
	endLevel = false;

	//Stop Going above Max Level
	if (l > 5){
		l = 5;
	}


	MrRobot::killAll();
	Lasers::destoryAll();

	switch (l){
	case 1:
		levelData = create(15, 7, readLevel("1"), readObjects("1"), readEnemies("1"));
		break;
	case 2:
		levelData = create(20, 8, readLevel("2"), readObjects("2"), readEnemies("2"));
		break;
	case 3:
		levelData = create(30, 10, readLevel("3"), readObjects("3"), readEnemies("3"));
		break;
	case 4:
		levelData = create(30, 13, readLevel("4"), readObjects("4"), readEnemies("4"));
		break;
	case 5:
		levelData = create(30, 15, readLevel("5"), readObjects("5"), readEnemies("5"));
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
	if (distance < ((levelData.data.size()-2) * 640) && Player::getHealth() != 0){
		distance += levelData.speed;

		distanceTraveled = distance / 1280;

	} else if (endLevel == false && Player::getHealth() != 0){
		Player::setMoving(true);
		endLevel = true;

		if (levelNumber == 5){
			gameWon = true;
			Audio::playEffect("Assets/Sounds/Win.wav");
		}

	} else if (Player::getHealth() != 0){
		endLevelTimer++;

		if (endLevelTimer > 120){
			if (levelNumber < 5){
				set(levelNumber + 1);
			}
		}
	}

	//Object Collision
	for (int i = 0; i < levelData.data.size(); i++){

		//Pitfall Collision
		if (levelData.objects[i] == 1){
			//if (distance >(640 * (i-1)) - 16 && distance < (640 * (i-1)) + 40 - 32){
			if (distance > (645 * i) + 140 && distance < (640 * i) + 250){
				if (!Player::getJumping()){
					Player::damageHealth();
					Player::damageHealth();


					if (Player::getHealth() > 0){
						std::cout << "Damage at " << Player::getHealth() << "!\n";
						Player::setDeath(1); //Falling Death
					}
				}
			}
		} else if (levelData.objects[i] == 2){
			if (distance > (640 * i) + 100 && distance < (640 * i) + 240){
				if (!Player::getJumping()){
					Player::damageHealth();
					Player::damageHealth();


					if (Player::getHealth() > 0){
						std::cout << "Damage at " << Player::getHealth() << "!\n";
						Player::setDeath(1); //Falling Death
					}
				}
			}
		} else if (levelData.objects[i] == 3){
			if (distance > (640 * i) + 30 && distance < (640 * i) + 350){
				if (!Player::getJumping()){
					Player::damageHealth();
					Player::damageHealth();

					if (Player::getHealth() > 0){
						std::cout << "Damage at " << Player::getHealth() << "!\n";
						Player::setDeath(1); // Falling Death
					}
				}
			}
		}
	}

	//Enemy Spawn
	MrRobot::run(distance);


	//IF DEAD PRESS SPACE TO RESTART
	if (Controls::currentKeyStates[SDL_SCANCODE_SPACE] && Player::getHealth() == 0){
		World::set(levelNumber);
	}

	//IF WIN GO BACK TO MENU IF SPACE
	if (Controls::currentKeyStates[SDL_SCANCODE_SPACE] && World::gameFinished() && Player::getHealth() > 0){
		Engine::changeState(STATE_MENU);
	}


}


void World::render() {

	//RENDERING
	for (int i = 0; i < levelData.data.size(); i++){
		//Tile Rendering
		if (i * 640 >= distance - 640 && i * 640 <= distance + 1300){
			switch (levelData.data[i]){
			case 1:
				Texture::draw(Resources::factoryBackground01, 640 * i - distance, 0);
				break;
			case 2:
				Texture::draw(Resources::factoryBackground02, 640 * i - distance, 0);
				break;
			case 3:
				Texture::draw(Resources::factoryBackground03, 640 * i - distance, 0);
				break;
			case 4:
				Texture::draw(Resources::factoryBackground04, 640 * i - distance, 0);
				break;
			case 5:
				Texture::draw(Resources::factoryBackground05, 640 * i - distance, 0);
				break;
			case 6:
				Texture::draw(Resources::factoryBackground06, 640 * i - distance, 0);
				break;
			case 7:
				Texture::draw(Resources::factoryBackground07, 640 * i - distance, 0);
				break;
			case 9:
				Texture::draw(Resources::factoryBackground09, 640 * i - distance, 0);
				break;
			}
		}
	}
	

	//Object Rendering
	for (int i = 0; i < levelData.objects.size(); i++){
		if (i * 640 >= distance - 640 && i * 640 <= distance + 1300){
			switch (levelData.objects[i]){
			case 1:
				Pits::render(1, i, distance);
				break;
			case 2:
				Pits::render(2, i, distance);
				break;
			case 3:
				Pits::render(3, i, distance);
				break;
			}
		}
	}

	//Robot Rendering
	MrRobot::render(distance);

	Effects::render();

}

bool World::levelFinished() {
	return endLevel;
}

bool World::gameFinished() {
	return gameWon;
}

int World::getLevelNumber() {
	return levelNumber;
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