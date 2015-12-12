#include <iostream>
#include <string>
#include <vector>
#include <fstream>


struct explosion{

	int posX;
	int posY;

	int timeLeft;

};

class Effects{


public:

	static void add(int x, int y);
	static void render();

	static int getHurtTimer();
	static void setHurtTimer();


private:

	static std::vector<explosion> source;

	static int hurtEffect;

};