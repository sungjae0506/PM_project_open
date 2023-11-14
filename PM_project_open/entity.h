#pragma once
#include <string>
#include "object.h"
#include "map"
using namespace std;

class Entity
{
public:
	Point pos;
	Point vel;
	Point acc;

	string name;
	string type;
	string state;
	
	virtual void setPos(const Point& p) = 0;
	virtual void setVel(const Point& p) = 0;
	virtual void setAcc(const Point& p) = 0;

	virtual void draw(void) = 0;
	virtual void move(void) = 0;
	virtual void collisionDetection(const Entity* e) = 0;
	//virtual void collisionDetection(const Map* m) = 0;
};