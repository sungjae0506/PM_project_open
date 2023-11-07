#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "object.h"
#include "range.h"
using namespace std;

vector<vector<int>> readMap(string file);
Point indexToPoint(int i, int j, int h, int w, const Range& r);
Lines vectorToLines(vector<vector<int>>& arr, const Range& r);