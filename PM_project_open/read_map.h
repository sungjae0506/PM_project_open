#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "object.h"
using namespace std;

vector<vector<int>> readMap(string file);

Lines vectorToLines(vector<vector<int>>& arr, double x1, double y1, double x2, double y2);