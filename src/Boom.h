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
	int boomSize;
public:
	Boom(int m_row, int m_Col, int boomSize);
	~Boom();
	void load();
	void show();
	int getPhase() const;
	int getBoomSize() const;
	boolean isFinshed() const;

};

inline int Boom::getPhase() const
{
	return phase;
}

inline int Boom::getBoomSize() const
{
	return boomSize;

}

inline boolean Boom::isFinshed() const
{
	return getPhase() >= getBoomSize();
}