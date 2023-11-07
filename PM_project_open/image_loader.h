#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <GL/freeglut.h>
#include <FreeImage.h>
using namespace std;

class ImageLoader
{
private:
	unordered_map<string, int> u_map;
public:
	ImageLoader();
	FIBITMAP* createBitMap(string filename);
	void load(string path, string name);
	void bind(string name);
};