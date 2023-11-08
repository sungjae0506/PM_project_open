#pragma once
#include <GL/freeglut.h>
#include <FreeImage.h>
#include "image_loader.h"
#include "range.h"

class Image
{
public:
	string name;
	ImageLoader* imageLoaderPointer;
	Range range;
	Image();
	Image(string file, const Range &r);
	void operator() (string file, const Range &r);
	Image operator+ (const Point& p);
	void draw();
};