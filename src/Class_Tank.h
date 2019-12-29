#pragma once
#include "GameSettings.h"
#include "Class_Unit.h"
#include <math.h>
#include "Class_Map.h"
#include "Class_Bullet.h"

#include<algorithm>

class Class_Tank
	:public Class_Unit
{
private:
	DWORD shootTime;
	Armor armorLevel;
	Direction direction;
	int speed; // In case we want to add speed difference
	DWORD bullet_interval;
	int life;
public:
	
	Class_Tank(int mRow, int mCol, UnitType type, Armor armor, Direction direction, DWORD shootInterval, int speed);
	~Class_Tank();

	// get functions
	Direction getDirection() const;
	Direction getOpDirection() const;
	int getSpeed() const;
	DWORD getShootInterval() const;
	Armor getArmorLevel() const;
	int getLife() const;
	// set functions
	void setDireciton(Direction direction);
	void setArmorLevel(Armor armor);
	void calibrate();
	void setLife(int life);

	void decreaseLife();
	Class_Bullet* shoot();

	boolean isTouch(const Class_Map& map);
	boolean isTouch(const Class_Map& map, Direction direction);

	void setSpeed(int speed);
	void setShootInterval(DWORD interval);
	virtual void show() = 0;

	// tanks can move
	void move();
	// A tank can shoot bullet.
	
};


inline int Class_Tank::getLife() const
{
	return life;
}

inline void Class_Tank::setLife(int life)
{
	this->life = life;
}

inline void Class_Tank::decreaseLife()
{
	this->life--;
}

inline Direction Class_Tank::getDirection() const
{
	return this->direction;
}

inline Armor Class_Tank::getArmorLevel() const
{
	return this->armorLevel;
}

inline void Class_Tank::setArmorLevel(Armor armor)
{
	this->armorLevel = armor;
}

inline void Class_Tank::setDireciton(Direction direction)
{
	this->direction = direction;
	int posX = getX();
	int posY = getY();
	int u_row = posY / (map_px / 2);
	int u_col = posX / (map_px / 2);
	
	
	if (u_row % 2 == 1)
	{
		if (this->direction == LEFT || this->direction == RIGHT) 
		{
			set_mRow((u_row + 1) / 2);
			set_uRow(u_row + 1);
			setY(get_mRow() * map_px);
		}

	}
	else
	{
		set_mRow(u_row / 2);
	
	}
	
	if (u_col % 2 == 1)
	{
		if (this->direction == UP || this->direction == DOWN) {
			set_mCol((u_col + 1) / 2);
			set_uCol(u_col + 1);
			setX(get_mCol() * map_px);
		}
		if (this->direction == DOWN)
		{

		}
	}
	else {
		set_mCol(u_col / 2);
		
	}
}


inline void Class_Tank::move()
{
	Direction direction = getDirection();
	switch (direction)
	{
	case UP:

		setY(getY() - getSpeed());
		break;
	case LEFT:
		setX(getX() - getSpeed());
		break;

	case DOWN:
		setY(getY() + getSpeed());
		break;

	case RIGHT:
		setX(getX() + getSpeed());
		break;

	default:
		break;
	}
}

inline void Class_Tank::calibrate()
{
	// to be implemented...
	
}

inline Class_Tank::~Class_Tank()
{

}

inline boolean Class_Tank::isTouch(const Class_Map& map, Direction direction)
{
	MapInt check1 = 0, check2 = 0;
	int m_row = get_mRow();
	int m_col = get_mCol();
	switch (direction)
	{
	case UP:
		check1 = map.getVal({ m_row - 1, m_col });
		check2 = map.getVal({ m_row - 1, m_col + 1 });
		break;
	case LEFT:
		check1 = map.getVal({ m_row, m_col - 1 });
		check2 = map.getVal({ m_row + 1, m_col - 1 });
		break;
	case DOWN:
		check1 = map.getVal({ m_row + 2, m_col });
		check2 = map.getVal({ m_row + 2, m_col + 1 });
		break;
	case RIGHT:
		check1 = map.getVal({ m_row, m_col + 2 });
		check2 = map.getVal({ m_row + 1, m_col + 2 });
		break;
	default:
		break;
	}

	return (check1 != EMPTY && check1 != JUNGLE && check1 != ICE) || (check2 != EMPTY && check2 != JUNGLE && check2 != ICE);
}

inline boolean Class_Tank::isTouch(const Class_Map& map)
{
	return isTouch(map, getDirection());
}


inline Direction Class_Tank::getOpDirection() const
{
	Direction direction = getDirection();
	switch (direction)
	{
	case UP:
		return DOWN;
		break;
	case LEFT:
		return RIGHT;
		break;
	case DOWN:
		return UP;
		break;
	case RIGHT:
		return LEFT;
		break;
	default:
		break;
	}
	return direction;
}

inline DWORD Class_Tank::getShootInterval() const
{
	return this->bullet_interval;
}

inline int Class_Tank::getSpeed() const
{
	return speed;
}

inline void Class_Tank::setSpeed(int speed)
{
	speed = speed;
}

inline void Class_Tank::setShootInterval(DWORD interval)
{
	this->bullet_interval = interval;
}