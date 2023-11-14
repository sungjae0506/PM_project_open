#pragma once
#include <string>
#include "event.h"
#include "object.h"
using namespace std;

class Page
{
public:
	Page();
	void keyboardEvent(KeyboardEvent event, string key, Point p);
	void mouseEvent(MouseEvent event, string button, Point p);
};