
#include <iostream>

class Player{

public:

	static void render();
	static void control();

private:

	//Stats
	static int health;
	static int power;

	//Positions
	static float posX, posY;

};
