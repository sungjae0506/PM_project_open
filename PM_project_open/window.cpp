#include "window.h"
#include "range.h"
#include <vector>
#include <ctime>
#include <stdio.h>


using namespace std;

static int WIDTH = 0;
static int HEIGHT = 0;

static double FPS = 60.0;
clock_t startClock = clock(), endClock;

vector<void(*)(void)> displayFuncVec;
vector<void(*)(void)> idleFuncVec;
vector<pair<pair<clock_t, clock_t>, double>> idleClockVec;

void windowResize(int w, int h)
{
	WIDTH = w;
	HEIGHT = h;
	//printf("%d %d\n", w, h);
}

void windowDisplay()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, WIDTH, 0.0, HEIGHT, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	for (auto func : displayFuncVec)
		func();
	glFinish();
}

void windowIdle() {
	endClock = clock();
	if (endClock - startClock > 1000.0 / FPS)
	{
		startClock = endClock;
		glutPostRedisplay();
	}
	for (int i = 0; i < idleFuncVec.size(); ++i)
	{
		idleClockVec[i].second = clock();
		if (idleClockVec[i].first.second - idleClockVec[i].first.first > 1000.0 / idleClockVec[i].second)
		{
			idleClockVec[i].first.first = idleClockVec[i].first.second;
			idleFuncVec[i]();
		}
	}
}

void dis()
{

}


Window::Window(int* argc, char** argv, int x, int y, int w, int h, string name)
{
	WIDTH = w;
	HEIGHT = h;
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(x, y);
	glutInitWindowSize(w, h);
	glutCreateWindow(name.c_str());
	glutReshapeFunc(windowResize);
	glutDisplayFunc(windowDisplay);
	glutIdleFunc(windowIdle);
	
}


