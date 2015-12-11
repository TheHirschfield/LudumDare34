/*
PROJECT: Areigna Client
CREATED: 6th August 2015
AUTHORS: Oliver Hirschfield
*/

#include "Texture.h"
#include "Graphics.h"

GSLTexture Texture::blank;
GSLTexture Texture::fade80;

std::vector<GSLColor> Color::colors;

/* Our main texture loading function. */
GSLTexture Texture::load(const char* filename) {
	
	GSLTexture tex;

	if (!filename) {
		return tex;
	} else{
		//Load File
		SDL_Surface* img = IMG_Load(filename);

		if (img == NULL) {
			std::cout << "Could Not Load Texture: " << filename << std::endl;
			return tex;
		}

		unsigned int id;

		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, 4, img->w, img->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, img->pixels);

	
		//Set GSLTexture Parameters
		tex.id = id;
		tex.w = img->w;
		tex.h = img->h;
	
		//Free SDL Surface Stuff
		SDL_FreeSurface(img);
		std::cout << "Finished Loading Texture: " << filename << std::endl;

		return tex;
	}
}

/* Load Textures From the Engine Storage. */
bool Texture::addBaseTextures() {

	//Load Premade Textures
	fade80 = load("Assets/UI/Textures/Fades/Grey80.png");

	//Load Color Scheme
	Color::loadSchema();

	return true;
}

/* Checks if the GSLTexture is a valid one. */
bool isValid(GSLTexture tex) {

	if (tex.id == 0){
		return false;
	}
	return true;
}

/* Checks new GSLColor for rendering */
GSLColor Texture::colorGL(float r, float g, float b) {

	GSLColor temp;

	temp.r = (float)(r / 255);
	temp.g = (float)(g / 255);
	temp.b = (float)(b / 255);
	temp.a = 0;


	return temp;
}

GSLColor Texture::colorSDL(int r, int g, int b) {

	GSLColor temp;

	temp.r = (float)(r);
	temp.g = (float)(g);
	temp.b = (float)(b);
	temp.a = 0;


	return temp;
}

/* User Interface element draw method.  */
void Texture::draw(GSLTexture tex, int posX, int posY, float scale) {
	//Set Up Texture
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();

	//Place
	glTranslatef(posX, posY, 0);

	//Module Placement
	glBindTexture(GL_TEXTURE_2D, tex.id);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex2f(0, 0); // Top Left
		glTexCoord2f(1, 0); glVertex2f(0 + (tex.w*scale), 0); // Top Right
		glTexCoord2f(1, 1); glVertex2f(0 + (tex.w*scale), 0 + (tex.h*scale)); // Bottom Right
		glTexCoord2f(0, 1); glVertex2f(0, 0 + (tex.h*scale)); // Bottom Left
	glEnd();

	glPopMatrix();


	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

}

/* User Interface background draw method.  */
void Texture::drawBackground(float r, float g, float b, GSLTexture tex) {

	//Set Up Texture
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	//Module Placement
	glColor3f((GLfloat)(r / 255), (GLfloat)(g / 255), (GLfloat)(b / 255));
	glBegin(GL_QUADS);
	glVertex2f(0, 0); // Top Left
	glVertex2f(0 + Graphics::screenWidth, 0); // Top Right
	glVertex2f(0 + Graphics::screenWidth, 0 + Graphics::screenHeight); // Bottom Right
	glVertex2f(0, 0 + Graphics::screenHeight); // Bottom Left
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
	glPopMatrix();

	glDisable(GL_BLEND);

}

/* Find Color By Name/Code */
GSLColor Color::getColor(std::string col) {

	//Set Up Temp Color
	GSLColor tempColor;

	//Find Color in Vector
	for (int i = 0; i < colors.size(); i++){
		if (colors[i].code == col){
			return colors[i];
		}		
	}

	//If Error Finding Color
	std::cout << "There was an error loading color code: " << col << "." << std::endl;

	return tempColor;
}

/* Save Color Scheme From Data File */
bool Color::loadSchema() {

	//Find File
	const char * file = "Assets/Color/Scheme.data";

	std::string input;
	std::ifstream f(file);

	//Read File
	if (f.is_open()){
		//Read Line By Line
		while (std::getline(f, input)) {

			//Read Line And Save Variables If Not A Comment
			if (input[0] != '#'){

				//Reading Storage Variables
				char name[8];
				int r, g, b;

				//Read Line
				sscanf(input.c_str(), "%s %i %i %i", &name, &r, &g, &b);
				
				//Set Up Temp Color
				GSLColor tempColor = Texture::colorSDL(r, g, b);
				tempColor.code = name;

				//Push Color To Storage
				colors.push_back(tempColor);

				//Notify Console
				std::cout << "Added New Color: " << tempColor.code << "." << std::endl;

			}
		}

		//Close File
		f.close();
		return true;
	}

	return false;
}