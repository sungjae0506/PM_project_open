#pragma once
#include <string>
#include "GL/freeglut.h"
#include "page.h"
#include "event.h"
#include "range.h"
#include "image.h"
using namespace std;

void windowResize(int w, int h);
void windowDisplay();
void windowIdle();

void windowKeyboard(unsigned char key, int x, int y);
void windowKeyboardUp(unsigned char key, int x, int y);
void windowSpecial(int key, int x, int y);
void windowSpecialUp(int key, int x, int y);

void windowMouse(int button, int state, int x, int y);
void windowMotion();
void windowPassiveMotion();

class Window
{
private:
	string currentPage;
public:

	Window(int* argc, char** argv, int x, int y, int w, int h, Range coord, string name);
	void addPage(Page& p);
	void setPage(Page& p);
	void setPage(string pageName);
	//void displayFunc();
	//vector<double> getWindowSize(void);

};