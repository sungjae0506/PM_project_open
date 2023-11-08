#include <iostream>
#include <GL/freeglut.h>
#include <FreeImage.h>
#include "image_loader.h"
#include "image.h"
#include "object.h"
#include "map.h"
#include "player.h"
#include "window.h"

using namespace std;
#define WIDTH 320
#define HEIGHT 320

Image snu;

vector<vector<int>> v;

Map map;

void drawSquareWithTexture() {

	map.platform.print();
	// 여기에 map.draw() 실행시 그려져야 함.
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
	glFinish();
}

int main(int argc, char** argv) {
	
	Window window(&argc, argv, 300, 300, WIDTH, HEIGHT, "Texture mapping");

	map.readMap("map.txt");
	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}