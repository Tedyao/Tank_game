#include "ComputerPlayer.h"
#include <cmath>


ComputerPlayer::ComputerPlayer(int m_Row, int m_Col, UnitType type, Armor armor, Direction direction)
	:Class_Player(m_Row, m_Col, type, armor, direction, 10, 500, map_px / 8)
{
	ComputerPlayer::randomDirection = std::uniform_int_distribution<unsigned>(0, 4);
	randomChoice = std::uniform_int_distribution<unsigned>(0, 100);
	load();
}

ComputerPlayer::~ComputerPlayer()
{

}


boolean ComputerPlayer::isAlive()
{
	return getLife() > 0;
}


sm ComputerPlayer::seen_movable(const Class_Player& player, const Class_Map& map, Direction direction) const
{
	int this_mRow = get_mRow();
	int this_mCol = get_mCol();
	int player_mRow = player.get_mRow();
	int player_mCol = player.get_mCol();
	if (map.getVal({this_mRow, this_mCol}) == EMPTY && map.getVal({ player_mRow, player_mCol }) != EMPTY) return { false, false };
	switch (direction)
	{
	case UP:
		if (abs(this_mCol - player_mCol) < 2 && this_mRow > player_mRow + 1
			&& map.seeThrough({ this_mRow, this_mCol }, { player_mRow, player_mCol }, UP))
		{
			if (this_mRow - player_mRow > 3) return { true, true };
			return { true, false };
		}

		else return { false, false };
		break;
	case LEFT:
		if (abs(this_mRow - player_mRow) < 2 && this_mCol > player_mCol + 1
			&& map.seeThrough({ this_mRow, this_mCol }, { player_mRow, player_mCol }, LEFT))
		{
			if (this_mCol - player_mCol > 3) return { true, true };
			return { true, false };
		}
		else return { false, false };
		break;
	case DOWN:
		if (abs(this_mCol - player_mCol) < 2 && this_mRow < player_mRow - 1
			&& map.seeThrough({ this_mRow, this_mCol }, { player_mRow, player_mCol }, DOWN))
		{
			if (player_mRow - this_mRow > 3) return { true, true };
			return { true, false };
		}
		else return { false, false };
		break;
	case RIGHT:
		if (abs(this_mRow - player_mRow) < 2 && this_mCol < player_mCol
			&& map.seeThrough({ this_mRow, this_mCol }, { player_mRow, player_mCol }, RIGHT))
		{
			if (player_mCol - this_mCol > 3) return { true, true };
			return { true, false };
		}
		else return { false, false };
		break;
	default:
		return { false, false };
		break;
	}
}

sm ComputerPlayer::nextStep(const Class_Map& map, const Class_Player& player) 
{
	this->setDireciton(getDirection());
	std::vector<Direction> validDirections;
	if (!isTouch(map, LEFT)) validDirections.push_back(LEFT);
	if (!isTouch(map, RIGHT)) validDirections.push_back(RIGHT);
	if (!isTouch(map, UP)) validDirections.push_back(UP);
	if (!isTouch(map, DOWN)) validDirections.push_back(DOWN);
	
	
	boolean touch = isTouch(map);

	if (!touch) {
		

		for (Direction direction : validDirections)
		{
			sm res = seen_movable(player, map, direction);
			if (res.seen) {
				setDireciton(direction);
				return res;
			}
			
		}

		int prob = randomChoice(e);
		if (prob < 5) {
			
			int randNum = rand() % validDirections.size();
			setDireciton(validDirections.at(randNum));
		}
	}

	else
	{
		if (validDirections.size() < 1)
		{
			setLife(0);
			return { false, false };
		}
		int randNum = rand() % validDirections.size();
		setDireciton(validDirections.at(randNum));
	}
	return {false, false};
	
}


void ComputerPlayer::load()
{
	for (int i = 0; i < ArmorCount; i++)
	{
		for (int j = 0; j < DirectionCount; j++)
		{
			for (size_t k = 0; k < 2; k++)
			{
				loadimage(&this->img[i][j][k], CP_FileName[i][j][k], unit_px, unit_px);
			}

		}
	}

	for (int i = 0; i < ArmorCount; i++)
	{
		for (int j = 0; j < DirectionCount; j++)
		{
			loadimage(&this->img_hide[i][j], PlayerHide_FileName[i][j], unit_px, unit_px);


		}
	}
}