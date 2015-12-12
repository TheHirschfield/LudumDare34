
#include "World.h"
#include "Resources.h"

#include "Engine\Texture.h"

int World::levelNumber = 0;

level World::levelData;

float World::distance = 0.0;


level World::create(int l, float s, std::vector<int> d) {

	level temp;

	temp.length = l;
	temp.speed = s;

	temp.data = d;

	return temp;
}

std::vector<int> World::readLevel(std::string file) {

	//Open File
	std::ifstream f(file);

	std::string input;
	std::vector<int> temp;

	//Reads Line By Line
	while (std::getline(f, input)){
		temp.push_back(std::stoi(input));
	}

	f.close();

	return temp;
}

bool World::set(int l) {

	levelNumber = l;

	switch (l){
	case 1:
		levelData = create(20, 10, readLevel("Assets/Levels/Level1.txt"));
		break;
	default:
		return 0;
		break;
	}
	levelNumber = l;


	return 1;
}

void World::explore() {

	distance += levelData.speed;

	if(

}


void World::render() {

	for (int i = 0; i < levelData.data.size(); i++){

		switch (levelData.data[i]){
		case 1:
			Texture::draw(Resources::factoryBackground01, 620 * i - distance, 0);
			break;
		case 2:
			Texture::draw(Resources::factoryBackground02, 620 * i - distance, 0);
			break;
		}
	
	}
	 

}