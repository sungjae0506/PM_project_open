#include "page.h"

Page::Page()
{
}

Page::Page(string name, const Range r)
{
	pageName = name;
	range = r;
}

Page& Page::operator() (string name, const Range r)
{
	pageName = name;
	range = r;
	return *this;
}

void Page::keyboardEvent(KeyboardEvent e, string key, Point p)
{
	for (auto& i : canvases)
		i.keyboardEvent(e, key, p);
}

void Page::mouseEvent(MouseEvent e, string button, Point p)
{
	for (auto& i : canvases)
		i.mouseEvent(e, button, p);
}

void Page::idleEvent(IdleEvent e)
{
	for (auto& i : canvases)
		i.idleEvent(e);
}

void Page::draw()
{
	for (auto& i : canvases)
		i.draw();
	for (auto& i : images)
		i.draw();
}

Page& Page::addCanvas(const Canvas& c)
{
	canvases.push_back(c);
	return *this;
}

Page& Page::addCanvases(vector<Canvas> cs)
{
	for (auto& c : cs)
		canvases.push_back(c);
	return *this;
}

Page& Page::addImage(const Image& i)
{
	images.push_back(i);
	return *this;
}

Page& Page::addImages(vector<Image> is)
{
	for (auto& i : is)
		images.push_back(i);
	return *this;
}