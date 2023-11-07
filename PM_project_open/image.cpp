#include "image.h"
#include "image_loader.h"
#include <iostream>
using namespace std;

ImageLoader textureImageLoader;

Image::Image() 
{
}

Image::Image(string file, const Range &r)
{
	name = file;
	textureImageLoader.load(file, file);
	imageLoaderPointer = &textureImageLoader;
	range = r;
}

void Image::operator() (string file, const Range &r)
{
	name = file;
	textureImageLoader.load(file, file);
	imageLoaderPointer = &textureImageLoader;
	range = r;
}

void Image::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	imageLoaderPointer->bind(name);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(range.point0.x, range.point0.y);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(range.point1.x, range.point0.y);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(range.point1.x, range.point1.y);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(range.point0.x, range.point1.y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}