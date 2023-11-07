#pragma once
#include <GL/freeglut.h>
#include <FreeImage.h>
#include "image_loader.h"

class Texture
{
public:
	string textureName;
	ImageLoader* imageLoaderPointer;
	Texture();
	Texture(ImageLoader &imageLoader, string file, string name = "");
	Texture(string file, string name = "");
	void operator() (ImageLoader &imageLoader, string file, string name = "");
	void operator() (string file, string name = "");
	void drawRect(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
};