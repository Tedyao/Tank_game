#pragma once
#include "Class_Unit.h"
#include "Class_Player.h"
class Effects
	:public Class_Unit
{
private:
	DWORD effectTimer;
	DWORD lastTime;
	Effect effect;
public:
	Effects();
	~Effects();
	Effect getEffect() const;
	DWORD getLastTime() const;
	void setEffect(Effect effect);
	void setLastTime(DWORD time);
	void apply(const Class_Player& player);
	
};

inline Effect Effects::getEffect()const
{
	return effect;
}
inline DWORD Effects::getLastTime() const
{
	return lastTime;
}

inline void Effects::setEffect(Effect effect)
{
	this->effect = effect;
}

inline void Effects::setLastTime(DWORD time)
{
	this->lastTime = time;
}

