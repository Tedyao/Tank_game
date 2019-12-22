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
public:
	std::default_random_engine e;
	std::uniform_int_distribution<unsigned> randomDirection;
	std::uniform_int_distribution<unsigned> randomChoice;
	~ComputerPlayer();
	sm nextStep(const Class_Map& map, const Class_Player& player);
	boolean isAlive();
	sm seen_movable(const Class_Player& player, const Class_Map& map, Direction direction) const;
	virtual void load();
	ComputerPlayer(int m_Row, int m_Col, UnitType type, Armor armor, Direction direction);

};

