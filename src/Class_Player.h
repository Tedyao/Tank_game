#pragma once
#include "Class_Tank.h"
#include "GameSettings.h"
class Class_Player
	:public Class_Tank
{
protected:
	DWORD timer;
	int counter;
	static IMAGE img[ArmorCount][DirectionCount][2];
	static IMAGE img_hide[ArmorCount][DirectionCount];
	virtual void load();

public:
	Class_Player(int mRow = 2, int mCol = 2, UnitType type = P1, Armor armorLevel = NORMAL, Direction direction = UP, int life = playerMedianLife, DWORD shootInterval=100, int speed = fastSpeed);
	virtual void show();
};

