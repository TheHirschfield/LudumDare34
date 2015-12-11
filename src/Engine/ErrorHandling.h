
#include <iostream>
#include <stdio.h>
#include <string>

enum error_code_type { ERROR_47301 = 47301, ERROR_47302 = 47302, ERROR_47400 = 47400, ERROR_47402 = 47402, ERROR_47403 = 47403, ERROR_47404 = 47404, ERROR_47405 = 47405 };

class ErrorHandling{

public:
	//Basic Report Function
	static void report(int code);

};
