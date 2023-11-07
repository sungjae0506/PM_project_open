#include "range.h"

Range::Range()
{
}
Range::Range(double x0, double y0, double x1, double y1)
{
	point0.x = x0;
	point0.y = y0;
	point1.x = x1;
	point1.y = y1;
}
Range::Range(const Point& p0, const Point& p1)
{
	point0 = p0;
	point1 = p1;
}
Range::Range(const Range& r)
{
	point0 = r.point0;
	point1 = r.point1;
}
Range& Range::operator=(const Range& r)
{
	point0 = r.point0;
	point1 = r.point1;
	return *this;
}
Range& Range::operator()(double x0, double y0, double x1, double y1)
{
	point0.x = x0;
	point0.y = y0;
	point1.x = x1;
	point1.y = y1;
	return *this;
}
Range& Range::operator()(const Point& p0, const Point& p1)
{
	point0 = p0;
	point1 = p1;
	return *this;
}
Range& Range::operator()(const Range& r)
{
	point0 = r.point0;
	point1 = r.point1;
	return *this;
}
Range Range::operator+(const Point& p) const
{
	return Range(point0 + p, point1 + p);
}
Range& Range::operator+=(const Point& p)
{
	return (*this) = (*this) + p;
}