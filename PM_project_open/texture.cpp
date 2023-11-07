#include "texture.h"
#include "image_loader.h"
#include <iostream>
using namespace std;

ImageLoader textureImageLoader;

Texture::Texture() 
{
}

Texture::Texture(ImageLoader &imageLoader, string file, string name)
{
	if (name == "")
		textureName = file;
	else
		textureName = name;
	imageLoader.load(file, textureName);
	imageLoaderPointer = &imageLoader;
}

Texture::Texture(string file, string name)
{
	if (name == "")
		textureName = file;
	else
		textureName = name;
	textureImageLoader.load(file, textureName);
	imageLoaderPointer = &textureImageLoader;
}

void Texture::operator() (ImageLoader &imageLoader, string file, string name)
{
	if (name == "")
		textureName = file;
	else
		textureName = name;
	imageLoader.load(file, textureName);
	imageLoaderPointer = &imageLoader;
}

void Texture::operator() (string file, string name)
{
	if (name == "")
		textureName = file;
	else
		textureName = name;
	textureImageLoader.load(file, textureName);
	imageLoaderPointer = &textureImageLoader;
}

void Texture::drawRect(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	imageLoaderPointer->bind(textureName);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(x1, y1);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(x2, y1);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(x2, y2);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(x1, y2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}