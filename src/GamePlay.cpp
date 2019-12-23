#include "GamePlay.h"

GamePlay::GamePlay(int computer_num)
	:player(Class_Player(26, 18, P1, NORMAL, UP, playerMedianLife, shortShootInterval, fastSpeed)), map(Class_Map()), computer_number(computer_num), commander(Commander(playerHighLife, longShootInterval, slowSpeed))
{
	int cnt = 0;
	int line = 2;
	for (int i = 1; i <= computer_number; i++, cnt++) {
		computers.push_back(new ComputerPlayer(line, 4 * cnt + 2, CP, NORMAL, LEFT, lowLife, superLongShootIntervel, slowSpeed));
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
	for (Boom* boom : booms) delete boom;

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
		if (player.getLife() < 1 || commander.getLife() < 1)
		{
			cleardevice();
			gameOver();
			FlushBatchDraw();
			Sleep(1000000);
		}

		if (computers.size() < 1)
		{
			cleardevice();
			win();
			FlushBatchDraw();
			Sleep(1000000);
		}
		cleardevice();

		controlLoop();

		show();
		
		FlushBatchDraw();
		Sleep(25);

	}
}