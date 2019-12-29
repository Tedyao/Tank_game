#pragma once

#include "Class_Player.h"
#include <random>
#include <vector>
#include <cstdlib>
class Class_Bullet;
struct sm
{
	boolean seen;
	boolean moveable;
};

class ComputerPlayer
	:public Class_Player
{
private:
	static IMAGE pri_img[ArmorCount][DirectionCount][2];
	static IMAGE pri_img_hide[ArmorCount][DirectionCount];
public:
	std::default_random_engine e;
	std::uniform_int_distribution<unsigned> randomDirection;
	std::uniform_int_distribution<unsigned> randomChoice;
	~ComputerPlayer();
	sm nextStep(const Class_Map& map, const Class_Unit& player, const Class_Player& commander);
	boolean isAlive();
	sm seen_movable(const Class_Unit& player, const Class_Map& map, Direction direction) const;
	virtual void load();
	virtual void show();
	ComputerPlayer(int m_Row, int m_Col, UnitType type, Armor armor, Direction direction, int shootInterval, int speed);

};

