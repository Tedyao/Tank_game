#include "Class_Bullet.h"

Class_Bullet::Class_Bullet(int mRow, int mCol, UnitType type, Direction direction, UnitType owner)
	:Class_Unit(mRow, mCol, type), direction(direction), owner(owner)
{
	load();
}


void Class_Bullet::show()
{
	putimage(getX(), getY(), &bullets_hide[getDirection()], SRCAND);
	putimage(getX(), getY(), &bullets[getDirection()], SRCPAINT);
}

void Class_Bullet::load()
{
	static bool load = false;
	if (!load)
	{
		for (size_t i = 0; i < 4; i++)
		{
			loadimage(&bullets[i], Bullet_FileName[i], map_px / 2, map_px / 2);
			loadimage(&bullets_hide[i], BulletHide_FileName[i], map_px / 2, map_px / 2);

		}
	}
}

