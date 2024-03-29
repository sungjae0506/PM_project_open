#include "window.h"
#include <vector>
#include <ctime>
#include <stdio.h>

using namespace std;

static int windowWidth = 0;
static int windowHeight = 0;
static Transform mouseTransform;

static double FPS = 60.0;
static clock_t startClock = clock(), endClock;

static double idlePerSecond = 120.0;
static clock_t idleStartClock = clock(), idleEndClock;

static vector<Page> pages;
static Page currentPage;

void windowResize(int w, int h)
{
	windowWidth = w;
	windowHeight = h;
	mouseTransform(Range(Point(0, windowHeight), Point(windowWidth, 0)), currentPage.range);
}	

void windowDisplay()
{
	Range pageRange = currentPage.range;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(pageRange.point0.x, pageRange.point1.x, pageRange.point0.y, pageRange.point1.y, -100.0, 100.0);
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	currentPage.draw();

	glutSwapBuffers();
}

void windowIdle() {
	endClock = clock();
	if (endClock - startClock > 1000.0 / FPS)
	{
		startClock = endClock;
		glutPostRedisplay();
	}

	idleEndClock = clock();
	if (idleEndClock - idleStartClock > 1000.0 / idlePerSecond)
	{
		idleStartClock = idleEndClock;
		currentPage.idleEvent(IdleRunning);
	}
}

void windowKeyboard(unsigned char key, int x, int y)
{
	char c[2] = { 0 };
	c[0] = key;
	currentPage.keyboardEvent(KeyboardDown, string(c), mouseTransform(Point(x, y)));
}

void windowKeyboardUp(unsigned char key, int x, int y)
{
	char c[2] = { 0 };
	c[0] = key;
	currentPage.keyboardEvent(KeyboardUp, string(c), mouseTransform(Point(x, y)));
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
	currentPage.keyboardEvent(KeyboardDown, s, mouseTransform(Point(x, y)));
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
	currentPage.keyboardEvent(KeyboardUp, s, mouseTransform(Point(x, y)));
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
	currentPage.mouseEvent(e, s, mouseTransform(Point(x, y)));
}

void windowMotion(int x, int y)
{
	currentPage.mouseEvent(MouseMotion, "NONE", mouseTransform(Point(x, y)));
}

void windowPassiveMotion(int x, int y)
{
	currentPage.mouseEvent(MousePassiveMotion, "NONE", mouseTransform(Point(x, y)));
}

Window::Window()
{
}

Window::Window(string name, int* argc, char** argv, int x, int y, int w, int h)
{
	windowWidth = w;
	windowHeight = h;
	windowName = name;

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

	glutMouseFunc(windowMouse);
	glutMotionFunc(windowMotion);
	glutPassiveMotionFunc(windowPassiveMotion);
}

Window& Window::operator() (string name, int* argc, char** argv, int x, int y, int w, int h)
{
	windowWidth = w;
	windowHeight = h;
	windowName = name;

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

	glutMouseFunc(windowMouse);
	glutMotionFunc(windowMotion);
	glutPassiveMotionFunc(windowPassiveMotion);

	return *this;
}

Window& Window::addPage(const Page& p)
{
	pages.push_back(p);
	return *this;
}

Window& Window::addPages(vector<Page> ps)
{
	for (auto p : ps)
		pages.push_back(p);
	return *this;
}

void Window::setPage(Page p)
{
	currentPage.idleEvent(IdleEnd);
	currentPage = p;
	mouseTransform(Range(Point(0, windowHeight), Point(windowWidth, 0)), currentPage.range);
	currentPage.idleEvent(IdleBegin);
}

void Window::setPage(string pageName)
{
	currentPage.idleEvent(IdleEnd);
	for (auto p : pages)
		if (p.pageName == pageName)
			currentPage = p;
	mouseTransform(Range(Point(0, windowHeight), Point(windowWidth, 0)), currentPage.range);
	currentPage.idleEvent(IdleBegin);
}

void Window::mainLoop(string pageName)
{
	setPage(pageName);
	glutMainLoop();
}

