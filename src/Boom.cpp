#include "Boom.h"

IMAGE Boom::boom[5];
IMAGE Boom::boom_hide[5];

Boom::Boom(int m_row, int m_col, int boomSize)
	:Class_Unit(m_row, m_col, BOOM), boomTimer(timeGetTime()), phase(0), boomSize(boomSize)
{
	load();
}

void Boom::load()
{
	for (int i = 0; i < 5; i++)
	{
		loadimage(&boom[i], Boom_FileName[i], unit_px, unit_px);
		loadimage(&boom_hide[i], BoomHide_FileName[i], unit_px, unit_px);
	}
}

Boom::~Boom()
{

}

void Boom::show()
{
	if (timeGetTime() - boomTimer > 15)
	{
		boomTimer = timeGetTime();
		putimage(getX(), getY(), &boom_hide[getPhase()], SRCAND);
		putimage(getX(), getY(), &boom[getPhase()], SRCPAINT);
		phase++;
	}
}

