#include "Commander.h"

Commander::Commander(int life, int shootInterval, int speed)
	:Class_Player(26, 14, COMMANDER, NORMAL, UP, shootInterval, speed), status(0)
{
	load();
}


Commander::~Commander()
{

}

void Commander::load()
{
	for (int i = 0; i < 2; i++) {
		loadimage(&this->commander[i], Commander_FileName[i], unit_px, unit_px);
		loadimage(&this->commander_hide[i], CommanderHide_FileName[i], unit_px, unit_px);
	}
}

void Commander::show()
{
	int x = getX();
	int y = getY();
	putimage(x, y, &this->commander_hide[getStatus()], SRCAND);
	putimage(x, y, &this->commander[getStatus()], SRCPAINT);
}