#include "cell.h"

Cell::Cell(int _x, int _y) : x(_x), y(_y), state(){}

State2D& Cell::getState()
{
	return state;
}

int Cell::getX()
{
	return x;
}

int Cell::getY()
{
	return y;
}

/*
void Cell::applyRule()
{
	rule.apply(state);
}
*/