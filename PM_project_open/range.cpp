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

Transform::Transform()
{
}
Transform::Transform(const Range& r0, const Range& r1)
{
	range0 = r0;
	range1 = r1;
}
Transform::Transform(const Transform& t)
{
	range0 = t.range0;
	range1 = t.range1;
}
Transform& Transform::operator()(const Range& r0, const Range& r1)
{
	range0 = r0;
	range1 = r1;
	return *this;
}
Point Transform::operator()(const Point& p)
{
	Point temp = (p - range0.point0);
	temp.x /= (range0.point1.x - range0.point0.x);
	temp.y /= (range0.point1.y - range0.point0.y);
	temp.x *= (range1.point1.x - range1.point0.x);
	temp.y *= (range1.point1.y - range1.point0.y);
	return temp + range1.point0;
}