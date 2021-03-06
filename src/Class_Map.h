#pragma once

#include "GameSettings.h"

const wchar_t map_file_path[] = _T("");//地图文件的路径名
const wchar_t map_file_name[] = _T("map.txt");//地图文件的文件名
const unsigned int max_stage = 35;//地图数量

struct pos_Map
{
	int row, col;
};

class Class_Map
{
public:
	Class_Map();
	MapInt getVal(const pos_Map& pos) const;
	void setVal(const pos_Map& pos, MapType type);
	void show();
	void show_tree();
	void loadMapPic(const wchar_t* const mapPicPath[7]);
	boolean seeThrough(const pos_Map& pos1, const pos_Map& pos2, Direction direction, int max_wall) const;
	
private:
	int stage;
	MapInt map[map_row][map_col];
	IMAGE map_pic[MapFileCount];
	void loadmap(unsigned int stage = 1);

};


inline MapInt Class_Map::getVal(const pos_Map& pos) const
{
	return this->map[pos.row][pos.col];
}

inline void Class_Map::setVal(const pos_Map& pos, MapType type)
{
	this->map[pos.row][pos.col] = (MapInt)type;
}

inline boolean Class_Map::seeThrough(const pos_Map& p1, const pos_Map& p2, Direction direction, int max_wall) const
{
	

	switch (direction)
	{
	case UP:
		for (int i = p2.row + 1; i < p1.row - 1; i++) {
			if (getVal({ i, p1.col }) != EMPTY && getVal({ i, p1.col }) != SEA && getVal({ i, p1.col }) != ICE) max_wall--;
			if (max_wall < 0) return false;
		}
		return true;
		break;
	case LEFT:
		for (int i = p2.col + 1; i < p1.col - 1; i++) {
			if (getVal({ p1.row, i }) != EMPTY && getVal({ p1.row, i }) != SEA && getVal({ p1.row, i }) != ICE) max_wall--;
			if (max_wall < 0) return false;
			
		}
		return true;
		break;
	case DOWN:
		for (int i = p1.row + 1; i < p2.row - 1; i++) {
			if (getVal({ i, p1.col }) != EMPTY && getVal({ i, p1.col }) != SEA && getVal({ i, p1.col }) != ICE) max_wall--;
			if (max_wall < 0) return false;
		}
		return true;
		break;
	case RIGHT:
		for (int i = p1.col + 1; i < p2.col - 1; i++) {
			if (getVal({ p1.row, i }) != EMPTY && getVal({ p1.row, i }) != SEA && getVal({ p1.row, i }) != ICE) max_wall--;
			if (max_wall < 0) return false;
		}
		return true;
		break;
	default:
		break;
	}
	return false;
}


