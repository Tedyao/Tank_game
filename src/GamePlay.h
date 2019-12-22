#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <graphics.h>
#include <stdio.h>
#include "Class_Tank.h"
#include "Class_Player.h"
#include "Class_Map.h"
#include <stdio.h>
#include <vector>
#include "Class_Bullet.h"
#include "ComputerPlayer.h"

#define KEY_DOWN(KEY) (GetAsyncKeyState(KEY) & 0x8000)

class GamePlay
{
private:
	int computer_number;
	Class_Player player;
	Class_Map map;
	std::vector<Class_Bullet*> bullets;
	std::vector<ComputerPlayer*> computers;

public:
	GamePlay(int computer_num);
	~GamePlay();
	void play();
	void displayInfo();
	void move();
	void show();
	boolean isHit(Class_Bullet* bullet, Class_Player* computer);
	void gameOver();

};


inline void GamePlay::gameOver()
{
	outtextxy(map_wide / 2, map_height / 2, _T("GAME OVER"));
}


inline void GamePlay::displayInfo()
{
	/*
	TCHAR x[10];
	TCHAR y[10];
	swprintf(x, 10, _T("x: %d"), player.getX() / map_px * 2);
	swprintf(y, 10, _T("y: %d"), player.getY() / map_px * 2);
	TCHAR m_row[10];
	TCHAR m_col[10];
	swprintf(m_row, 10, _T("x: %d"), player.get_mCol());
	swprintf(m_col, 10, _T("y: %d"), player.get_mRow());
	TCHAR x_[10];
	TCHAR y_[10];
	swprintf(x_, 10, _T("x: %d"), player.getX());
	swprintf(y_, 10, _T("y: %d"), player.getY());
	outtextxy(map_px, map_px, x);
	outtextxy(4 * map_px, map_px, y);
	outtextxy(map_px, 2 * map_px, m_col);
	outtextxy(4 * map_px, 2 * map_px, m_row);
	outtextxy(map_px, 3 * map_px, x_);
	outtextxy(4 * map_px, 3 * map_px, y_);
	*/
	TCHAR health_[12];
	swprintf(health_, 12, _T("Health: %d"), player.getLife());
	outtextxy(3 * map_px, 2 * map_px, health_);
	TCHAR enemy_[12];
	swprintf(enemy_, 12, _T("Enemy: %d"), computers.size());
	outtextxy(6 * map_px, 2 * map_px, enemy_);
}

inline boolean GamePlay::isHit(Class_Bullet* bullet, Class_Player* computer)
{
	int c_row = computer->getY() / map_px;
	int c_col = computer->getX() / map_px;
	int row = bullet->getY() / map_px;
	int col = bullet->getX() / map_px;
	return row >= c_row && row <= c_row + 2 && col >= c_col && col <= c_col + 2;
}

inline void GamePlay::show()
{
	displayInfo();
	for (ComputerPlayer* computer : computers) {
		sm res = computer->nextStep(map, player);
		if (res.seen)
		{
			Class_Bullet* bullet = computer->shoot();
			if (bullet != nullptr) bullets.push_back(bullet);
			if (res.moveable) computer->move();
			
		}
		else computer->move();
		computer->show();
	}
	map.show();
	player.show();
	auto it = bullets.begin();
	for (it; it != bullets.end(); ) {
		if ((*it)->getX() < 2 * map_px || (*it)->getX() >= map_wide - 4 * map_px || (*it)->getY() < map_px * 2 || (*it)->getY() >= map_height - map_px * 2)
		{
			delete* it;
			it = bullets.erase(it);
		}
		else if (!(*it)->bulletTouch(map))
		{

			boolean flag = false;
			if ((*it)->getOwner() == P1)
			{
				for (ComputerPlayer* computer : computers) {
					if (isHit(*it, computer)) {
						computer->decreaseLife();
						
						flag = true;
						
					}
				}
			}
			if ((*it)->getOwner() == CP)
			{
				if (isHit(*it, &player))
				{
					player.decreaseLife();
					flag = true;
				}
			}
			

			if (!flag) {
				(*it)->move();
				(*it)->show();
				it++;
			}
			else {
				delete* it;
				it = bullets.erase(it);
			}
		}
		else {
			// If bullets are touching some object...
			(*it)->destory(map);
			delete* it;
			it = bullets.erase(it);
		}

	}

	auto c_iter = computers.begin();
	for (c_iter; c_iter != computers.end(); )
	{
		if (!(*c_iter)->isAlive()) c_iter = computers.erase(c_iter);
		else c_iter++;
	}
	
}


inline void GamePlay::move()
{
	if (!player.isTouch(map)) player.move();
	auto it = bullets.begin();
	
}

