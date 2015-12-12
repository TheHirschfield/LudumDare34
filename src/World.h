
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct level{

	int length;
	float speed;
	std::vector<int> data;
	std::vector<int> objects;
};

class World{

public:

	static level create(int l, float s, std::vector<int> d, std::vector<int> o);

	static std::vector<int> readLevel(std::string file);
	static std::vector<int> readObjects(std::string file);


	static bool set(int l);

	static void explore();
	static void render();

private:

	static int levelNumber;
	static level levelData;
	static float distance;

	static bool endLevel;


};