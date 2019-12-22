#include "Class_Unit.h"


Class_Unit::Class_Unit(int mRow, int mCol, UnitType type)
	:mRow(mCol), mCol(mCol), uRow(2 * mRow), uCol(2 * mCol), x(map_px * mCol), y(map_px * mRow), type(type)
{

}

Class_Unit::~Class_Unit()
{

}