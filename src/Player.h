
#include <time.h>
#include <iostream>
#include <string>

#include <iostream>

class Player{

public:

	static void render();
	static void control();
	static void move();

private:

	//Stats
	static int health;
	static int power;

	//Actions
	static bool isJumping;
	static bool isMoving;

	//Positions
	static float posX, posY;

};
