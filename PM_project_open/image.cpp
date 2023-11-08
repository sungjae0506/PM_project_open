#include "image.h"
#include "image_loader.h"
#include <iostream>
using namespace std;

static ImageLoader imageLoader;

Image::Image() 
{
}

Image::Image(string file, const Range &r)
{
	name = file;
	imageLoader.load(file, file);
	imageLoaderPointer = &imageLoader;
	range = r;
}

void Image::operator() (string file, const Range &r)
{
	name = file;
	imageLoader.load(file, file);
	imageLoaderPointer = &imageLoader;
	range = r;
}

Image Image::operator+ (const Point& p)
{
	return Image(name, Range(range.point0 + p, range.point1 + p));
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