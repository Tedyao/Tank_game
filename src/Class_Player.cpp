#include "Class_Player.h"
#include "GameSettings.h"

IMAGE Class_Player::img[ArmorCount][DirectionCount][2];
IMAGE Class_Player::img_hide[ArmorCount][DirectionCount];


Class_Player::Class_Player(int mRow, int mCol, UnitType type, Armor armorLevel, Direction direction, DWORD shootInterval, int speed)
	:Class_Tank(mRow, mCol, type, armorLevel, direction, shootInterval, speed)
{
	timer = timeGetTime();
	counter = 0;
	load();
	switch (armorLevel)
	{
	case DEAD:
		setLife(0);
		break;
	case NORMAL:
		setLife(playerLowLife);
		break;
	case LIGHT:
		setLife(playerMedianLife);
		break;
	case STRONG:
		setLife(playerHighLife);
		break;
	case HEAVY:
		setLife(playerSuperLife);
		break;
	default:
		break;
	}
}


void Class_Player::show()
{
	int x = getX();
	int y = getY();
	if (timeGetTime() - timer > 100)
	{
		timer = timeGetTime();
		counter = (counter + 1) % 2;
	}
	putimage(x, y, &this->img_hide[this->getArmorLevel()][this->getDirection()], SRCAND);
	putimage(x, y, &this->img[this->getArmorLevel()][this->getDirection()][counter], SRCPAINT);
}

void Class_Player::load()
{
	for (int i = 0; i < ArmorCount; i++)
	{
		for (int j = 0; j < DirectionCount; j++)
		{
			for (size_t k = 0; k < 2; k++)
			{
				loadimage(&this->img[i][j][k], P1_FileName[i][j][k], unit_px, unit_px);
			}

		}
	}

	for (int i = 0; i < ArmorCount; i++)
	{
		for (int j = 0; j < DirectionCount; j++)
		{
			loadimage(&this->img_hide[i][j], PlayerHide_FileName[i][j], unit_px, unit_px);


		}
	}
}