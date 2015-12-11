#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

#include <GL\glew.h>
#include <SDL_opengl.h>

#include "Texture.h"

#include <iostream>
#include <string>
#include <vector>

enum font_size_t { font_size_12, font_size_16, font_size_18, font_size_24 };

class Text
{
public:
	
	static std::vector<TTF_Font*> fontLight;
	static std::vector<TTF_Font*> fontRegular;
	static std::vector<TTF_Font*> fontBold;

	static int loadFonts();
	static void drawText(std::string text, int posX, int posY, GSLColor color = {"", 0, 0, 0, 0 }, TTF_Font* font = fontLight[0], int alignment = 0);
};

