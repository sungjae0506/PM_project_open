#pragma once
#include <string>
#include <vector>
#include "event.h"
#include "range.h"
#include "object.h"
#include "canvas.h"
#include "image.h"
using namespace std;

class Page
{
public:
	string pageName;
	Range range;

	vector<Canvas> canvases;
	vector<Image> images;

	Page();
	Page(string name, const Range r);
	Page& operator() (string name, const Range r);
	void keyboardEvent(KeyboardEvent event, string key, Point p);
	void mouseEvent(MouseEvent event, string button, Point p);
	void draw();

	Page& addCanvas(const Canvas &c);
	Page& addCanvases(vector<Canvas> cs);

	Page& addImage(const Image &i);
	Page& addImages(vector<Image> is);
};