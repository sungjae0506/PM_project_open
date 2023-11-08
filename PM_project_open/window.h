#pragma once
#include <string>
#include "GL/freeglut.h"
using namespace std;

void windowResize(int w, int h);
void windowDisplay();
void windowIdle();

class Window
{
public:
	Window(int* argc, char** argv, int x, int y, int w, int h, string name);
	//vector<double> getWindowSize(void);
};