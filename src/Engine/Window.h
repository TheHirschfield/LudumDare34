
#include <iostream>
#include <stdio.h>
#include <string>


enum windows_t {
	WINDOW_DEFAULT, WINDOW_SYS_400, WINDOW_SYS_200
};

class Window{

public:

	static int currentLayer;

	static void loadTypes();
	static void draw(int type, std::string title, int x, int y);

};