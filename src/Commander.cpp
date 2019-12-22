#include "Commander.h"

Commander::Commander()
	:Class_Player(26, 14, COMMANDER, NORMAL, UP, 10, 100, 6), status(0)
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