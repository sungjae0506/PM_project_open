#include "window.h"
#include <vector>
#include <ctime>
#include <stdio.h>


using namespace std;

static int windowWidth = 0;
static int windowHeight = 0;
static Range windowCoord;
static Transform mouseTransform;

static double FPS = 60.0;
static clock_t startClock = clock(), endClock;

static vector<Page*> pages;
static Page* currentPagePointer;

vector<void(*)(void)> displayFuncVec;
vector<void(*)(void)> idleFuncVec;
vector<pair<pair<clock_t, clock_t>, double>> idleClockVec;

// test
Image SNU;


void windowResize(int w, int h)
{
	windowWidth = w;
	windowHeight = h;
	mouseTransform(Range(Point(0, windowHeight), Point(windowWidth, 0)), windowCoord);
	//printf("%d %d\n", w, h);
}

void windowDisplay()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(windowCoord.point0.x, windowCoord.point1.x, windowCoord.point0.y, windowCoord.point1.y, -100.0, 100.0);
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//printf("ok\n");
	
	SNU("image/snu.png", Range(0, 0, 100, 100));
	SNU.draw();

	glutSwapBuffers();
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

void windowKeyboard(unsigned char key, int x, int y)
{
	char c[2] = { 0 };
	c[0] = key;
	currentPagePointer->keyboardEvent(KeyboardDown, string(c), mouseTransform(Point(x, y)));
	//printf("%d %d\n", x, y);
}

void windowKeyboardUp(unsigned char key, int x, int y)
{
	char c[2] = { 0 };
	c[0] = key;
	currentPagePointer->keyboardEvent(KeyboardUp, string(c), mouseTransform(Point(x, y)));
}

void windowSpecial(int key, int x, int y)
{
	string s;
	switch (key)
	{
	case GLUT_KEY_F1:
		s = "F1";
		break;
	case GLUT_KEY_F2:
		s = "F2";
		break;
	case GLUT_KEY_F3:
		s = "F3";
		break;
	case GLUT_KEY_F4:
		s = "F4";
		break;

	case GLUT_KEY_F5:
		s = "F5";
		break;
	case GLUT_KEY_F6:
		s = "F6";
		break;
	case GLUT_KEY_F7:
		s = "F7";
		break;
	case GLUT_KEY_F8:
		s = "F8";
		break;

	case GLUT_KEY_F9:
		s = "F9";
		break;
	case GLUT_KEY_F10:
		s = "F10";
		break;
	case GLUT_KEY_F11:
		s = "F11";
		break;
	case GLUT_KEY_F12:
		s = "F12";
		break;

	case GLUT_KEY_LEFT:
		s = "LEFT";
		break;
	case GLUT_KEY_RIGHT:
		s = "RIGHT";
		break;
	case GLUT_KEY_UP:
		s = "UP";
		break;
	case GLUT_KEY_DOWN:
		s = "DOWN";
		break;

	case GLUT_KEY_PAGE_UP:
		s = "PAGE_UP";
		break;
	case GLUT_KEY_PAGE_DOWN:
		s = "PAGE_DOWN";
		break;
	case GLUT_KEY_HOME:
		s = "HOME";
		break;
	case GLUT_KEY_END:
		s = "END";
		break;

	case GLUT_KEY_INSERT:
		s = "INSERT";
		break;
	default:
		break;
	}
	currentPagePointer->keyboardEvent(KeyboardDown, s, mouseTransform(Point(x, y)));
}

void windowSpecialUp(int key, int x, int y)
{
	string s;
	switch (key)
	{
	case GLUT_KEY_F1:
		s = "F1";
		break;
	case GLUT_KEY_F2:
		s = "F2";
		break;
	case GLUT_KEY_F3:
		s = "F3";
		break;
	case GLUT_KEY_F4:
		s = "F4";
		break;

	case GLUT_KEY_F5:
		s = "F5";
		break;
	case GLUT_KEY_F6:
		s = "F6";
		break;
	case GLUT_KEY_F7:
		s = "F7";
		break;
	case GLUT_KEY_F8:
		s = "F8";
		break;

	case GLUT_KEY_F9:
		s = "F9";
		break;
	case GLUT_KEY_F10:
		s = "F10";
		break;
	case GLUT_KEY_F11:
		s = "F11";
		break;
	case GLUT_KEY_F12:
		s = "F12";
		break;

	case GLUT_KEY_LEFT:
		s = "LEFT";
		break;
	case GLUT_KEY_RIGHT:
		s = "RIGHT";
		break;
	case GLUT_KEY_UP:
		s = "UP";
		break;
	case GLUT_KEY_DOWN:
		s = "DOWN";
		break;

	case GLUT_KEY_PAGE_UP:
		s = "PAGE_UP";
		break;
	case GLUT_KEY_PAGE_DOWN:
		s = "PAGE_DOWN";
		break;
	case GLUT_KEY_HOME:
		s = "HOME";
		break;
	case GLUT_KEY_END:
		s = "END";
		break;

	case GLUT_KEY_INSERT:
		s = "INSERT";
		break;
	default:
		break;
	}
	currentPagePointer->keyboardEvent(KeyboardUp, s, mouseTransform(Point(x, y)));
}

void windowMouse(int button, int state, int x, int y)
{
	MouseEvent e;
	string s;
	switch (state)
	{
	case GLUT_DOWN:
		e = MouseDown;
		break;
	case GLUT_UP:
		e = MouseUp;
		break;
	}
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		s = "LEFT";
		break;
	case GLUT_MIDDLE_BUTTON:
		s = "MIDDLE";
		break;
	case GLUT_RIGHT_BUTTON:
		s = "RIGHT";
		break;
	default:
		break;
	}
	currentPagePointer->mouseEvent(e, s, mouseTransform(Point(x, y)));
}

void windowMotion(int x, int y)
{
	currentPagePointer->mouseEvent(MouseMotion, "NONE", mouseTransform(Point(x, y)));
}

void windowPassiveMotion(int x, int y)
{
	currentPagePointer->mouseEvent(MousePassiveMotion, "NONE", mouseTransform(Point(x, y)));
}

Window::Window(int* argc, char** argv, int x, int y, int w, int h, Range coord, string name)
{
	windowWidth = w;
	windowHeight = h;
	windowCoord = coord;
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(x, y);
	glutInitWindowSize(w, h);
	glutCreateWindow(name.c_str());

	glutReshapeFunc(windowResize);
	glutDisplayFunc(windowDisplay);
	glutIdleFunc(windowIdle);

	glutKeyboardFunc(windowKeyboard);
	glutKeyboardUpFunc(windowKeyboardUp);
	glutSpecialFunc(windowSpecial);
	glutSpecialUpFunc(windowSpecialUp);
}


