#pragma once

#include "Class_Unit.h"
#include "Class_Map.h"


class Class_Bullet
	:public Class_Unit
{
private:
	UnitType owner;
	int speed = map_px / 2;
	static IMAGE bullets[4];
	static IMAGE bullets_hide[4];
	Direction direction;
public:
	
	Class_Bullet(int mRow, int mCol, UnitType type, Direction direction, UnitType owner);
	~Class_Bullet();
	void show();
	void load();
	void move();
	void destory(Class_Map& map);
	UnitType getOwner() const;
	boolean bulletTouch(Class_Map& map);
	Direction getDirection();

};

inline Class_Bullet::~Class_Bullet()
{

}

inline Direction Class_Bullet::getDirection()
{
	return this->direction;
}

inline void Class_Bullet::move()
{
	Direction direction = getDirection();
	switch (direction)
	{
	case UP:

		setY(getY() - speed);
		break;
	case LEFT:
		setX(getX() - speed);
		break;

	case DOWN:
		setY(getY() + speed);
		break;

	case RIGHT:
		setX(getX() + speed);
		break;

	default:
		break;
	}
}

inline void Class_Bullet::destory(Class_Map& map)
{

	int m_Col = getX() / map_px;
	int m_Row = getY() / map_px;
	if (map.getVal({ m_Row, m_Col }) != JUNGLE && map.getVal({ m_Row, m_Col }) != ICE && map.getVal({m_Row, m_Col}) != IRON)
	{
		map.setVal({ m_Row, m_Col }, EMPTY);
	}
	

}

inline boolean Class_Bullet::bulletTouch(Class_Map& map)
{
	int m_Col = getX() / map_px;
	int m_Row = getY() / map_px;
	MapInt check1 = map.getVal({ m_Row, m_Col });
	return check1 != EMPTY && check1 != JUNGLE && check1 != ICE && check1 != SEA;

}

inline UnitType Class_Bullet::getOwner() const
{
	return owner;
}