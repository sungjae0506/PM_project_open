#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "object.h"
#include "range.h"
#include "image.h"
using namespace std;


Point indexToPoint(int i, int j, int h, int w, const Range& r);
Lines vectorToLines(vector<vector<int>>& arr, const Range& r);

class Map
{
public:
	vector<vector<int>> tileVector;
	Map();
	void readMap(string file);
	void draw(Image tile1, Image tile2);
};