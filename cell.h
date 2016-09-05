#ifndef __CELL_CLASS
#define __CELL_CLASS
#include "state2d.h"
//#include "rule.h"

class Cell
{
	int x, y;
	State2D state;
	//Rule cellrule;
	
	Cell(int _x, int _y);
	State2D& getState();
	int getX();
	int getY();
	//void applyRule();
}

#endif