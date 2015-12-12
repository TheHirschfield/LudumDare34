
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "MrRobot.h"

struct enemy{

	int type;

	MrRobot robotInfo;

};

class Enemies{

public:

	static void render();
	static void add(int type);
	static void destroy(int id);

	static int getEntities();

	static void clearAll();

private:

	static std::vector<enemy> entities;

};


