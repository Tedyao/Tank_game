#include "Class_Unit.h"

#pragma once
class Boom
	:public Class_Unit
{
private:
	static IMAGE boom[5];
	static IMAGE boom_hide[5];
	DWORD boomTimer;
	int phase;
public:
	Boom(int m_row, int m_Col);
	~Boom();
	void load();
	void show();
	int getPhase() const;

};

inline int Boom::getPhase() const
{
	return phase;
}

