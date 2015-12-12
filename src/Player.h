
#include <time.h>
#include <iostream>
#include <string>

#include <iostream>

class Player{

public:

	//Reset Player Data
	static void reset();

	//Do Stuff
	static void render();
	static void control();
	static void move();

	//Access Methods
	static int getHealth();

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
