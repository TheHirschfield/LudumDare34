
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct level{

	int length;
	float speed;
	std::vector<int> data;
	std::vector<int> objects;
	std::vector<int> enemies;

};

class World{

public:

	static level create(int l, float s, std::vector<int> d, std::vector<int> o, std::vector<int> e);

	static std::vector<int> readLevel(std::string file);
	static std::vector<int> readObjects(std::string file);
	static std::vector<int> readEnemies(std::string file);

	static bool set(int l);

	static void explore();
	static void render();

	static bool levelFinished();
	static bool gameFinished();

	static int getLevelNumber();

	static int getEnemiesSpawned();

private:

	static int levelNumber;
	static level levelData;
	static float distance;

	static bool endLevel;
	static bool gameWon;

};