#include <iostream>
#include <GL/freeglut.h>
#include <FreeImage.h>
#include "image_loader.h"
#include "texture.h"
#include "object.h"
#include "read_map.h"
#include "player.h"

using namespace std;
#define WIDTH 320
#define HEIGHT 320

ImageLoader imageLoader;
Texture snu;

vector<vector<int>> v;
Lines test;

void drawSquareWithTexture() {

	//snu.drawRect(-100, -100, 100, 100);
	test.print();
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
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(WIDTH, HEIGHT);

	glutCreateWindow("Texture mapping");

	snu("image/snu.png");

	
	v = readMap("map.txt");
	test = vectorToLines(v, -100, -100, 100, 100);

	

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}