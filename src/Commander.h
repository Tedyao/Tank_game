#pragma once
#include "Class_Player.h"
class Commander
	:public Class_Player
{
private:
	int status;
	IMAGE commander[2];
	IMAGE commander_hide[2];
public:
	Commander(int life, int shootInterval, int speed);
	~Commander();
	void load();
	void show();
	int getStatus() const;
	void setStatus(int status);
};


inline int Commander::getStatus() const
{
	return status;
}

inline void Commander::setStatus(int status)
{
	this->status = status;
}
