#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <SDL.h>
#include <SDL_image.h>
#include <GL\glew.h>

#include <SDL_opengl.h>

#include <stdlib.h>
#include <stdio.h>
#include <glut.h>

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

//Texture Storage Struct
struct GSLTexture {
	unsigned int id = 0;
	int w = 0;
	int h = 0;
};

//Color Storage Struct
struct GSLColor {

	GSLColor(std::string, float, float, float, float);
	GSLColor() : code(""), r(0), g(0), b(0), a(0) {};

	std::string code = "";
	float r = 0.0;
	float g = 0.0;
	float b = 0.0;
	float a = 0.0;

};

class Texture{
public:
	
	//Load New Texture
	static GSLTexture load(const char* filename);

	static bool addBaseTextures();

	//Check if Server is Valid
	static bool isValid(GSLTexture tex);

	//Color Creation Methods
	static GSLColor colorGL(float r, float g, float b);
	static GSLColor colorSDL(int r, int g, int b);

	//Draw Elements
	static void draw(GSLTexture tex, int posX, int posY, float scale = 1.0);
	static void drawBackground(float r = 0.0, float g = 0.0, float b = 0.0, GSLTexture tex = Texture::blank);

	//Black Default Texture
	static GSLTexture blank;

	//Fade Textures
	static GSLTexture fade80;

};

class Color {
public:

	static GSLColor getColor(std::string col);

	static bool loadSchema();

private:

	static std::vector<GSLColor> colors;

};