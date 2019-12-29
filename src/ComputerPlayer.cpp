#include "ComputerPlayer.h"
#include <cmath>
#include <ctime>

IMAGE ComputerPlayer::pri_img[ArmorCount][DirectionCount][2];
IMAGE ComputerPlayer::pri_img_hide[ArmorCount][DirectionCount];

ComputerPlayer::ComputerPlayer(int m_Row, int m_Col, UnitType type, Armor armor, Direction direction, int shootInterval, int speed)
	:Class_Player(m_Row, m_Col, type, armor, direction, shootInterval, speed)
{
	srand((int)time(0));
	load();
	switch (armor)
	{
	case DEAD:
		setLife(0);
		break;
	case NORMAL:
		setLife(lowLife);
		break;
	case LIGHT:
		setLife(medianLife);
		break;
	case STRONG:
		setLife(highLife);
		break;
	case HEAVY:
		setLife(playerLowLife);
		break;
	default:
		break;
	}
}

ComputerPlayer::~ComputerPlayer()
{

}


boolean ComputerPlayer::isAlive()
{
	return getLife() > 0;
}


sm ComputerPlayer::seen_movable(const Class_Unit& player, const Class_Map& map, Direction direction) const
{
	int max_wall = 0;
	if (player.getType() == P1) max_wall = 0;
	else max_wall = 3;
	int this_mRow = get_mRow();
	int this_mCol = get_mCol();
	int player_mRow = player.get_mRow();
	int player_mCol = player.get_mCol();
	//if (map.getVal({this_mRow, this_mCol}) == EMPTY && map.getVal({ player_mRow, player_mCol }) != EMPTY) return { false, false };
	switch (direction)
	{
	case UP:
		if (abs(this_mCol - player_mCol) < 1 && this_mRow > player_mRow + 1
			&& map.seeThrough({ this_mRow, this_mCol }, { player_mRow, player_mCol }, UP, max_wall))
		{
			if (this_mRow - player_mRow > 2) return { true, true };
			return { true, false };
		}

		else return { false, false };
		break;
	case LEFT:
		if (abs(this_mRow - player_mRow) < 1 && this_mCol > player_mCol + 1
			&& map.seeThrough({ this_mRow, this_mCol }, { player_mRow, player_mCol }, LEFT, max_wall))
		{
			if (this_mCol - player_mCol > 2) return { true, true };
			return { true, false };
		}
		else return { false, false };
		break;
	case DOWN:
		if (abs(this_mCol - player_mCol) < 1 && this_mRow < player_mRow - 1
			&& map.seeThrough({ this_mRow, this_mCol }, { player_mRow, player_mCol }, DOWN, max_wall))
		{
			if (player_mRow - this_mRow > 2) return { true, true };
			return { true, false };
		}
		else return { false, false };
		break;
	case RIGHT:
		if (abs(this_mRow - player_mRow) < 1 && this_mCol < player_mCol
			&& map.seeThrough({ this_mRow, this_mCol }, { player_mRow, player_mCol }, RIGHT, max_wall))
		{
			if (player_mCol - this_mCol > 2) return { true, true };
			return { true, false };
		}
		else return { false, false };
		break;
	default:
		return { false, false };
		break;
	}
}

sm ComputerPlayer::nextStep(const Class_Map& map, const Class_Unit& player,  const Class_Player& commander) 
{
	this->setDireciton(getDirection());
	std::vector<Direction> validDirections; // finding valid directions towards which won't hit wall
	validDirections.push_back(LEFT);
	validDirections.push_back(RIGHT);
	validDirections.push_back(UP);
	validDirections.push_back(DOWN);
	
	

	for (Direction direction : validDirections)
	{
		// wether can see player toward this direction
		sm res = seen_movable(player, map, direction);
		if (res.seen) {
			setDireciton(direction);
			if (isTouch(map)) res.moveable = false;
			return res;
		}
		// wether can see commander toward this direction

		else
		{

			res = seen_movable(commander, map, direction);
			if (res.seen) {
				setDireciton(direction);
				if (isTouch(map)) res.moveable = false;
				return res;
			}

		}

	}

	// if can't see player or commander

	if (!isTouch(map))
	{
		int prob = rand() % 100;
		if (prob < 3) {

			int randNum = rand() % validDirections.size();
			setDireciton(validDirections.at(randNum));
		}
		return { false, true };
	}

	else
	{
		int randNum = rand() % validDirections.size();
		setDireciton(validDirections.at(randNum));
		return { false, true };
	}
	
}


void ComputerPlayer::load()
{
	for (int i = 0; i < ArmorCount; i++)
	{
		for (int j = 0; j < DirectionCount; j++)
		{
			for (size_t k = 0; k < 2; k++)
			{
				loadimage(&this->pri_img[i][j][k], CP_FileName[i][j][k], unit_px, unit_px);
			}

		}
	}

	for (int i = 0; i < ArmorCount; i++)
	{
		for (int j = 0; j < DirectionCount; j++)
		{
			loadimage(&this->pri_img_hide[i][j], PlayerHide_FileName[i][j], unit_px, unit_px);


		}
	}
}


void ComputerPlayer::show()
{
	int x = getX();
	int y = getY();
	if (timeGetTime() - timer > 100)
	{
		timer = timeGetTime();
		counter = (counter + 1) % 2;
	}
	putimage(x, y, &this->pri_img_hide[this->getArmorLevel()][this->getDirection()], SRCAND);
	putimage(x, y, &this->pri_img[this->getArmorLevel()][this->getDirection()][counter], SRCPAINT);
}