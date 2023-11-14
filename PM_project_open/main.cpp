#include <iostream>
#include <GL/freeglut.h>
#include <FreeImage.h>
#include <ctime>
#include "image_loader.h"
#include "image.h"
#include "object.h"
#include "map.h"
#include "player.h"
#include "window.h"

using namespace std;
#define WIDTH 320
#define HEIGHT 320



static clock_t startClock = clock(), endClock;

//Image snu;
Image snu;


vector<vector<int>> v;

Map game_map;

void drawSquareWithTexture() {

	//glTranslatef(50, 50, 0);
	//glScissor(0, 0, 100, 100);
	//glEnable(GL_SCISSOR_TEST);
	snu.draw();
	game_map.platform.print();
	//glTranslatef(50, 50, 0);
	//game_map.platform.print();
	//game_map.platform.print();
	//glDisable(GL_SCISSOR_TEST);
	
	// ���⿡ map.draw() ����� �׷����� ��.
}
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, WIDTH, 0.0, HEIGHT, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawSquareWithTexture();

	//glutSwapBuffers();
	glFinish();
}

void Idle() {
	endClock = clock();
	if (endClock - startClock > 1000.0 / 60.0)
	{
		startClock = endClock;
		glutPostRedisplay();
	}
}

int main(int argc, char** argv) {
	
	Window window(&argc, argv, 300, 300, WIDTH, HEIGHT, Range(0, 0, 320, 320), "Texture mapping");

	game_map.readMap("map.txt");

	//glutDisplayFunc(display);
	//glutIdleFunc(Idle);
	//window.displayFunc();
	glutMainLoop();
	return 0;
}