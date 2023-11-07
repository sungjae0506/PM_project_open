#pragma once
#include "object.h"

class Range
{
public:
	Point point0, point1;
	Range();
	Range(double x0, double y0, double x1, double y1);
	Range(const Point& p0, const Point& p1);
	Range(const Range& r);
	Range& operator=(const Range& r);
	Range& operator()(double x0, double y0, double x1, double y1);
	Range& operator()(const Point& p0, const Point& p1);
	Range& operator()(const Range& r);
	Range operator+(const Point& p) const;
	Range& operator+=(const Point& p);
};