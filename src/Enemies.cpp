/*
PROJECT: Ludum Dare
CREATED: 12th December 2015
AUTHORS: Oliver Hirschfield
*/

#include "Enemies.h"

std::vector<enemy> Enemies::entities;


void Enemies::render() {

	for (int i = 0; i < entities.size(); i++){
		
		switch (entities[i].type){
		case 1: //Render Robot
			entities[i].robotInfo.render();
		}
	}
}

void Enemies::add(int type) {
	switch (type){
	case 1: //Robot

		enemy newEntity;
		MrRobot temp;

		newEntity.type = type;
		newEntity.robotInfo = temp;

		entities.push_back(newEntity);
	}
}


void Enemies::destroy(int id) {

}

int Enemies::getEntities() {

	return entities.size();
}

void Enemies::clearAll() {


}