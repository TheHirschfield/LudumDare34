
#include <iostream>


class Interface{

public:

	static void renderUI();
	static void controlUI();

	static void setMenuTimeout(int t);

private:
	static int menuTimeout;
};