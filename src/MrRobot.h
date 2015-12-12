#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Robot{

	int health;
	int damage;

	int posX, posY;

};

class MrRobot{

public:

	static void add(int posX);

	static void render(int distance);
	static void run(int distance);

	static void killAll();

private:

	static std::vector<Robot> entities;

};


