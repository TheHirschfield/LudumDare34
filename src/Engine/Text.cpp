/*
PROJECT: Areigna Client
CREATED: 23rd September 2015
AUTHORS: Oliver Hirschfield
*/

#include "Text.h"

//Fonts
std::vector<TTF_Font*> Text::fontLight;
std::vector<TTF_Font*> Text::fontRegular;
std::vector<TTF_Font*> Text::fontBold;

//Text Colors (B,G,R)
static SDL_Color COLOR_WHITE = { 255, 255, 255 };
static SDL_Color COLOR_LIGHTGREY = { 100, 100, 100 };

static SDL_Color COLOR_RED = { 0, 7, 195 };
static SDL_Color COLOR_GREEN = { 29, 118, 56 };
static SDL_Color COLOR_YELLOW = { 55, 157, 233 };
static SDL_Color COLOR_ALPHA = { 255, 0, 255, 0 };

int Text::loadFonts() {

	//Initialise TTF
	TTF_Init();

	//Light Font
	fontLight.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Light.ttf", 12));
	fontLight.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Light.ttf", 16));
	fontLight.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Light.ttf", 18));
	fontLight.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Light.ttf", 24));

	//Regular Font
	fontRegular.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Regular.ttf", 12));
	fontRegular.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Regular.ttf", 16));
	fontRegular.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Regular.ttf", 18));
	fontRegular.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Regular.ttf", 24));

	//Bold Font
	fontBold.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Semibold.ttf", 12));
	fontBold.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Semibold.ttf", 16));
	fontBold.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Semibold.ttf", 18));
	fontBold.push_back(TTF_OpenFont("Assets/UI/Fonts/OpenSans-Semibold.ttf", 24));

	return 0;
}

void Text::drawText(std::string text, int posX, int posY, GSLColor color, TTF_Font* font, int alignment) {

	//GL Enables
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);


	//Text Texture Creation Variables
	SDL_Surface *initial;
	SDL_Surface *intermediary;
	SDL_Rect rect;
	int w, h;
	unsigned int id;

	// Make Color
	SDL_Color  textColor = { (int)color.b, (int)color.g, (int)color.r };

	//Convert String to Char
	char* textRender = (char*)text.c_str();

	//Render Text
	initial = TTF_RenderText_Blended(font, textRender, textColor);

	//Make Texture Size A Power of 2
	w = (int)(pow(2, ceil(log(initial->w) / log(2))) + 0.5);
	h = (int)(pow(2, ceil(log(initial->h) / log(2))) + 0.5);

	//Convert Text to Usable Texture
	intermediary = SDL_CreateRGBSurface(0, initial->w, initial->h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

	//Combine Surfaces Together
	SDL_BlitSurface(initial, 0, intermediary, 0);

	//Create OpenGL Texture
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, 4, initial->w, initial->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, intermediary->pixels);

	glPushMatrix();

	//Place UI Element
	glTranslatef(posX + initial->w / 2, posY + initial->h / 2, 0);

	//Set Alignment
	if (alignment == 2){
		glTranslatef(-initial->w, 0, 0);
	} else if (alignment == 1){
		glTranslatef(-(initial->w / 2), 0, 0);
	}

	//Color
	glColor4f(1.0, 1.0, 1.0, 0.0);

	//Render Text
	glBindTexture(GL_TEXTURE_2D, id);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-initial->w / 2, 0 - initial->h / 2); // Top Left
	glTexCoord2f(1, 0);	glVertex2f(initial->w / 2, -initial->h / 2); // Top Right
	glTexCoord2f(1, 1); glVertex2f(initial->w / 2, initial->h / 2); // Bottom Right
	glTexCoord2f(0, 1);	glVertex2f(-initial->w / 2, initial->h / 2); // Bottom Left
	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	//Clean Up
	SDL_FreeSurface(initial);
	SDL_FreeSurface(intermediary);
	glDeleteTextures(1, &id);
	glColor4f(1.0, 1.0, 1.0, 1.0);
}