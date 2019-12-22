#include "GamePlay.h"

GamePlay::GamePlay(int computer_num)
	:player(Class_Player(2, 16, P1, NORMAL, UP)), map(Class_Map()), computer_number(computer_num)
{
	int cnt = 0;
	int line = 2;
	for (int i = 1; i <= computer_number; i++, cnt++) {
		computers.push_back(new ComputerPlayer(line, 4 * cnt + 2, CP, NORMAL, LEFT));
		if (i % 4 == 0)
		{
			line += 2;
			cnt = 0;
		}
	}

}

GamePlay::~GamePlay()
{
	for (Class_Bullet* bullet : bullets) delete bullet;
	for (ComputerPlayer* computer : computers) delete computer;

}

void GamePlay::play()
{
	int cnt = 0;
	initgraph(map_wide, map_height);
	setbkcolor(BLACK);
	cleardevice();

	BeginBatchDraw();
	while (true)
	{
		if (player.getLife() < 1)
		{
			cleardevice();
			gameOver();
			FlushBatchDraw();
			Sleep(1000000);
		}
		cleardevice();

		if (KEY_DOWN(VK_LEFT) || KEY_DOWN('A')) {
			player.setDireciton(LEFT);
			if (!player.isTouch(map)) player.move();
		}
		else if (KEY_DOWN(VK_RIGHT) || KEY_DOWN('D')) {
			player.setDireciton(RIGHT);
			if (!player.isTouch(map)) player.move();
		}
		else if (KEY_DOWN(VK_DOWN) || KEY_DOWN('S')) {
			player.setDireciton(DOWN);
			if (!player.isTouch(map)) player.move();


		}
		else if (KEY_DOWN(VK_UP) || KEY_DOWN('W')) {
			player.setDireciton(UP);
			if (!player.isTouch(map)) player.move();


		}
		else if (KEY_DOWN('J')) {
			Class_Bullet* bullet = player.shoot();
			if (bullet != nullptr) bullets.push_back(bullet);
		}

		show();
		
		FlushBatchDraw();
		Sleep(25);

	}
}