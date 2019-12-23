#include "GamePlay.h"

GamePlay::GamePlay(int computer_num)
	:player(Class_Player(26, 18, P1, NORMAL, UP, playerMedianLife, shortShootInterval, fastSpeed)), map(Class_Map()), computer_number(computer_num), commander(Commander(playerHighLife, longShootInterval, slowSpeed)), waitForSpawn(true)
{
	srand((int)time(0));
	
	spawnEnemy();
	waitForSpawn = false;
	
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
			if (!waitForSpawn)
			{
				waitForSpawn = true;
				spawnTimer = timeGetTime();
			}
			if (waitForSpawn && timeGetTime() - spawnTimer > 3000)
			{
				spawnEnemy();
				waitForSpawn = false;
			}
			
		}
		cleardevice();

		controlLoop();

		show();
		
		FlushBatchDraw();
		Sleep(25);

	}
}