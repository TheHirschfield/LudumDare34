
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct bullet{
	float posX;
	float speed;
	bool alive;
};


class Lasers{

public:
	
	static void add(int s);
	static void move();
	static void render();

	static void destoryAll();

private:

	static std::vector<bullet> currentBullets;

};