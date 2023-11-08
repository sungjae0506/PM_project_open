#include <iostream>
#include <GL/freeglut.h>
#include <FreeImage.h>
#include "image_loader.h"
#include "image.h"
#include "object.h"
#include "read_map.h"
#include "player.h"
#include "window.h"

using namespace std;
#define WIDTH 320
#define HEIGHT 320

Image snu;
ImageLoader imageLoader;

vector<vector<int>> v;
Lines test;

void drawSquareWithTexture() {

	snu.draw();
	//test.print();
}
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WIDTH / 2.0, WIDTH / 2.0, -HEIGHT / 2.0, HEIGHT / 2.0, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	drawSquareWithTexture();
	glFinish();
}

int main(int argc, char** argv) {
	
	Window window(&argc, argv, 300, 300, WIDTH, HEIGHT, "Texture mapping");

	snu("image/snu.png", Range(-100, -100, 100, 100));

	
	v = readMap("map.txt");
	test = vectorToLines(v, Range(0, -20, 320, 300));
	//test = vectorToLines(v, Range(-100, -100, 100, 100));

	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}