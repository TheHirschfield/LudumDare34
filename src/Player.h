
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
	static void damageHealth();

	static void setDeath(int type);
	static int getDeath();


	static bool getJumping();
	static void setMoving(bool go);

private:

	//Stats
	static int health;
	static int power;

	//Actions
	static bool isJumping;
	static bool isMoving;

	//Positions
	static float posX, posY;

	//Death
	static int deathType;

};
