#pragma once
#include "GameSettings.h"

class Class_Unit
{
private:
	int x, y; // The true coordinate of an item x = map_px * mRow; y = map_px * m_Col
	int mRow, mCol; //The map row and col number
	int uRow, uCol; //The item row and col number: uRow = 2 * mRow, uCol = 2 * mCol
	UnitType type; //The type of this unit

public:
	Class_Unit(int mRow, int mCol, UnitType type);
	virtual ~Class_Unit();

	// get series
	int get_mRow() const;
	int get_mCol() const;
	int get_uRow() const;
	int get_uCol() const;
	int getX() const;
	int getY() const;
	// set series
	void set_mRow(int row);
	void set_mCol(int col);
	void set_uRow(int row);
	void set_uCol(int col);
	void setX(int x);
	void setY(int y);


	UnitType getType() const;

	virtual void show() = 0;
};


// the definition of get series functions

inline UnitType Class_Unit::getType() const
{
	return this->type;
}


inline int Class_Unit::get_mCol() const 
{
	return mCol;
}

inline int Class_Unit::get_mRow() const 
{
	return mRow;
}

inline int Class_Unit::get_uCol() const 
{
	return uCol;
}

inline int Class_Unit::get_uRow() const 
{
	return uRow;
}

inline int Class_Unit::getX() const 
{
	return x;
}

inline int Class_Unit::getY() const 
{
	return y;
}

// the definition of set series functions

inline void Class_Unit::set_mRow(int row)
{
	mRow = row;
}

inline void Class_Unit::set_mCol(int col)
{
	mCol = col;
}

inline void Class_Unit::set_uRow(int row)
{
	uRow = row;
}

inline void Class_Unit::set_uCol(int col)
{
	uCol = col;
}

inline void Class_Unit::setX(int x)
{
	this->x = x;
}

inline void Class_Unit::setY(int y)
{
	this->y = y;
}