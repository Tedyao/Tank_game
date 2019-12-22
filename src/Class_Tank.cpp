#include "Class_Tank.h"
#include "GameSettings.h"


Class_Tank::Class_Tank(int mRow, int mCol, UnitType type, Armor armorLevel, Direction direction, int life, DWORD shootInterval, int speed)
	:Class_Unit(mRow, mCol, type), direction(direction), armorLevel(armorLevel), shootTime(timeGetTime()), life(life), bullet_interval(shootInterval), speed(speed)
{

}

Class_Bullet* Class_Tank::shoot()
{
	if (timeGetTime() - shootTime < getShootInterval()) return nullptr;
	Direction direction = getDirection();
	int row = 0;
	int col = 0;
	switch (direction)
	{
	case UP:
		row = get_mRow();
		col = get_mCol() + 1;
		break;
	case LEFT:
		row = get_mRow() + 1;
		col = get_mCol();
		break;
	case DOWN:
		row = get_mRow() + 2;
		col = get_mCol() + 1;
		break;
	case RIGHT:
		row = get_mRow() + 1;
		col = get_mCol() + 2;
		break;
	default:
		break;
	}
	
	Class_Bullet* bullet = new Class_Bullet(row, col, BULLET, direction, getType());
	shootTime = timeGetTime();
	return bullet;
}

