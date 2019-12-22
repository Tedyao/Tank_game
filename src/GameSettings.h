#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <graphics.h>

#pragma comment(lib,"Winmm.lib")

using namespace std;

//����궨��
#define Int unsigned short int
#define MapInt unsigned char
#define KEY_DOWN(VK_NONAME) (GetAsyncKeyState(VK_NONAME) & 0x8000)



//��ͼ����
struct pos_XY
{
	short int x, y;
};

/*****************
���ô��ڵ���ز���
*****************/
const Int source_map_px = 8;//ԭ̹�˴�սһ����ͼ��Ԫ��Ӧ�����ش�С
const Int px_multiple = 4;//ͼƬ���طŴ���
const Int map_px = source_map_px * px_multiple;//ÿ����ͼ��Ԫ��ʵ�����ش�С
const Int unit_px = map_px * 2;//̹�ˡ����ߵĻ�ͼ��С
const Int bullet_px = map_px / 2;//�ӵ���ͼ��С
//��ͼ������С�����
const Int map_row = 30;
const Int map_col = 32;
//��Ԫ������С�������Ϊ��ͼ������������Դ˴ﵽ̹�˵��ƶ�����񡱵�Ч��
const Int unit_row = map_row * 2;
const Int unit_col = map_col * 2;

//��Ϸ����Ŀ�͸ߣ����أ�
const Int map_wide = map_px * map_col;
const Int map_height = map_px * map_row;
//�˵���ť�Ŀ�͸�
const Int menue_wide = 80;
const Int menue_height = 40;
//�˵����ֵĿ�Ⱥ͸߶ȡ���������
const Int text_size = 30;
const wchar_t* const text_style = _T("���Ŀ���");


const Int unit_size = 4;//ÿ����Ԫ��unit������ռ�õĿ�ȣ�̹�˳���Ϊ4���ڵ�Ϊ2��
const Int bullet_size = unit_size / 2;
const Int unit_sizeInMap = unit_size / 2;

/*******************************
�����ƶ��ٶȡ�����ˢ�����ʵ�����
*******************************/
const Int RenewClock = 1000 / 60;//����ˢ������
enum Speed//ÿ��ˢ��ʱ����Ӧ�ƶ���������
{
	SlowSpeed = (2 * unit_sizeInMap * map_px) * RenewClock / 1000, //ÿ���������
	NormalSpeed = (3 * unit_sizeInMap * map_px) * RenewClock / 1000, //ÿ���������
	FastSpeed = (4 * unit_sizeInMap * map_px) * RenewClock / 1000,//ÿ�����Ĵ��
	HighSpeed = 2 * FastSpeed,
	VeryHighSpeed = 2 * HighSpeed
};

/***************
����λ����ز���
***************/
enum MapType//��ͼ����
{
	EMPTY,//�յ�
	WALL_UL = 0x01, WALL_UR = 0x02, WALL_DL = 0x04, WALL_DR = 0x08,//�ķ�֮һ��ש
	WALL_UP = 0x03, WALL_LEFT = 0x05, WALL_RIGHT = 0x0A, WALL_DOWN = 0x0C,//���ש
	WALL = 0x0F,//שǽ
	IRON,//������
	BORDER,//��ͼ�߽�
	SEA,//����
	ICE = 0x21,//����
	JUNGLE,//����
};
enum UnitType//����λ����ֵ��������ײ���
{
	//�ӵ�
	BULLET = 500,
	P1 = 300,//1�����
	P2 = 400,//2�����
	CP = 600,//����
	COMMANDER = 0xC8,//ָ�ӹ�
};
enum Direction//���򣬻��ơ�����ʱ��
{
	UP, LEFT, DOWN, RIGHT, DirectionCount
};
enum Armor//̹��װ�׵ȼ�
{
	DEAD = -1, NORMAL, LIGHT, STRONG, HEAVY, ArmorCount
};
enum Key//���̿���
{
	Key_UP = 'W', Key_LEFT = 'A', Key_RIGHT = 'D', Key_DOWN = 'S',
	Key_SHOOT = 'J', Key_PAUSE = 'P',
	Key_START = 'F', Key_SELECT = 'R'
};

/*************
���ͼƬ�ļ���
**************/
//���������̬���ĸ������ͼƬ
const wchar_t* const P1_FileName[ArmorCount][DirectionCount][2] =
{
	_T("Image\\tank\\player1\\player1_0_up1.png"),_T("Image\\tank\\player1\\player1_0_up2.png"),
	_T("Image\\tank\\player1\\player1_0_left1.png"),_T("Image\\tank\\player1\\player1_0_left2.png"),
	_T("Image\\tank\\player1\\player1_0_down1.png"),_T("Image\\tank\\player1\\player1_0_down2.png"),
	_T("Image\\tank\\player1\\player1_0_right1.png"),_T("Image\\tank\\player1\\player1_0_right2.png"),

	_T("Image\\tank\\player1\\player1_1_up1.png"),_T("Image\\tank\\player1\\player1_1_up2.png"),
	_T("Image\\tank\\player1\\player1_1_left1.png"),_T("Image\\tank\\player1\\player1_1_left2.png"),
	_T("Image\\tank\\player1\\player1_1_down1.png"),_T("Image\\tank\\player1\\player1_1_down2.png"),
	_T("Image\\tank\\player1\\player1_1_right1.png"),_T("Image\\tank\\player1\\player1_1_right2.png"),

	_T("Image\\tank\\player1\\player1_2_up1.png"),_T("Image\\tank\\player1\\player1_2_up2.png"),
	_T("Image\\tank\\player1\\player1_2_left1.png"),_T("Image\\tank\\player1\\player1_2_left2.png"),
	_T("Image\\tank\\player1\\player1_2_down1.png"),_T("Image\\tank\\player1\\player1_2_down2.png"),
	_T("Image\\tank\\player1\\player1_2_right1.png"),_T("Image\\tank\\player1\\player1_2_right2.png"),

	_T("Image\\tank\\player1\\player1_3_up1.png"),_T("Image\\tank\\player1\\player1_3_up2.png"),
	_T("Image\\tank\\player1\\player1_3_left1.png"),_T("Image\\tank\\player1\\player1_3_left2.png"),
	_T("Image\\tank\\player1\\player1_3_down1.png"),_T("Image\\tank\\player1\\player1_3_down2.png"),
	_T("Image\\tank\\player1\\player1_3_right1.png"),_T("Image\\tank\\player1\\player1_3_right2.png")
};
const wchar_t* const PlayerHide_FileName[ArmorCount][DirectionCount] =
{
	_T("Image\\tank\\player_hide\\player_hide0_up.png"),
	_T("Image\\tank\\player_hide\\player_hide0_left.png"),
	_T("Image\\tank\\player_hide\\player_hide0_down.png"),
	_T("Image\\tank\\player_hide\\player_hide0_right.png"),

	_T("Image\\tank\\player_hide\\player_hide1_up.png"),
	_T("Image\\tank\\player_hide\\player_hide1_left.png"),
	_T("Image\\tank\\player_hide\\player_hide1_down.png"),
	_T("Image\\tank\\player_hide\\player_hide1_right.png"),

	_T("Image\\tank\\player_hide\\player_hide2_up.png"),
	_T("Image\\tank\\player_hide\\player_hide2_left.png"),
	_T("Image\\tank\\player_hide\\player_hide2_down.png"),
	_T("Image\\tank\\player_hide\\player_hide2_right.png"),

	_T("Image\\tank\\player_hide\\player_hide3_up.png"),
	_T("Image\\tank\\player_hide\\player_hide3_left.png"),
	_T("Image\\tank\\player_hide\\player_hide3_down.png"),
	_T("Image\\tank\\player_hide\\player_hide3_right.png")
};
const wchar_t* const Commander_FileName[2] = { _T("Image\\commander0.png"),_T("Image\\commander1.png") };
const wchar_t* const CommanderHide_FileName[2] = { _T("Image\\commander0_hide.png"),_T("Image\\commander1_hide.png") };

/*****************
�������ͼƬ�ļ���
******************/
//���ֵо�̹�˵��ĸ������ͼƬ
const wchar_t* const CP_FileName[ArmorCount][DirectionCount][2] =
{
	_T("Image\\tank\\enemy\\enemy0_up1.png"),_T("Image\\tank\\enemy\\enemy0_up2.png"),
	_T("Image\\tank\\enemy\\enemy0_left1.png"),_T("Image\\tank\\enemy\\enemy0_left2.png"),
	_T("Image\\tank\\enemy\\enemy0_down1.png"),_T("Image\\tank\\enemy\\enemy0_down2.png"),
	_T("Image\\tank\\enemy\\enemy0_right1.png"),_T("Image\\tank\\enemy\\enemy0_right2.png"),

	_T("Image\\tank\\enemy\\enemy1_up1.png"),_T("Image\\tank\\enemy\\enemy1_up2.png"),
	_T("Image\\tank\\enemy\\enemy1_left1.png"),_T("Image\\tank\\enemy\\enemy1_left2.png"),
	_T("Image\\tank\\enemy\\enemy1_down1.png"),_T("Image\\tank\\enemy\\enemy1_down2.png"),
	_T("Image\\tank\\enemy\\enemy1_right1.png"),_T("Image\\tank\\enemy\\enemy1_right2.png"),

	_T("Image\\tank\\enemy\\enemy2_up1.png"),_T("Image\\tank\\enemy\\enemy2_up2.png"),
	_T("Image\\tank\\enemy\\enemy2_left1.png"),_T("Image\\tank\\enemy\\enemy2_left2.png"),
	_T("Image\\tank\\enemy\\enemy2_down1.png"),_T("Image\\tank\\enemy\\enemy2_down2.png"),
	_T("Image\\tank\\enemy\\enemy2_right1.png"),_T("Image\\tank\\enemy\\enemy2_right2.png"),

	_T("Image\\tank\\enemy\\enemy3_up1.png"),_T("Image\\tank\\enemy\\enemy3_up2.png"),
	_T("Image\\tank\\enemy\\enemy3_left1.png"),_T("Image\\tank\\enemy\\enemy3_left2.png"),
	_T("Image\\tank\\enemy\\enemy3_down1.png"),_T("Image\\tank\\enemy\\enemy3_down2.png"),
	_T("Image\\tank\\enemy\\enemy3_right1.png"),_T("Image\\tank\\enemy\\enemy3_right2.png")
};
const wchar_t* const CPHide_FileName[ArmorCount][DirectionCount] =
{
	_T("Image\\tank\\enemy_hide\\enemy_hide0_up.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide0_left.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide0_down.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide0_right.png"),

	_T("Image\\tank\\enemy_hide\\enemy_hide1_up.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide1_left.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide1_down.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide1_right.png"),

	_T("Image\\tank\\enemy_hide\\enemy_hide2_up.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide2_left.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide2_down.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide2_right.png"),

	_T("Image\\tank\\enemy_hide\\enemy_hide3_up.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide3_left.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide3_down.png"),
	_T("Image\\tank\\enemy_hide\\enemy_hide3_right.png")
};

/********************
��ͼԪ�ص�ͼƬ�ļ���
********************/
enum MapFileNum
{
	FileNum_wall, FileNum_iron, FileNum_border, FileNum_sea0, FileNum_sea1, FileNum_ice, FileNum_jungle, MapFileCount
};
const wchar_t* const Map_FileName[MapFileCount] =
{ _T("Image\\map\\wall.png"),_T("Image\\map\\iron.png"),_T("Image\\map\\border.png"),_T("Image\\map\\sea0.png"),_T("Image\\map\\sea1.png"),_T("Image\\map\\ice.png"),_T("Image\\map\\jungle.png") };

//�ӵ�ͼƬ�ļ���
const wchar_t* const Bullet_FileName[DirectionCount] =
{ _T("Image\\bullet\\bullet_up.png"),_T("Image\\bullet\\bullet_left.png"),_T("Image\\bullet\\bullet_down.png"),_T("Image\\bullet\\bullet_right.png") };
const wchar_t* const BulletHide_FileName[DirectionCount] =
{ _T("Image\\bullet\\bullet_hide_up.png"),_T("Image\\bullet\\bullet_hide_left.png"),_T("Image\\bullet\\bullet_hide_down.png"),_T("Image\\bullet\\bullet_hide_right.png") };

//��ըͼƬ�ļ���
const wchar_t* const Boom_FileName[5] =
{ _T("Image\\boom\\boom0.png"),_T("Image\\boom\\boom1.png") ,_T("Image\\boom\\boom2.png") ,_T("Image\\boom\\boom3.png") ,_T("Image\\boom\\boom4.png") };
const wchar_t* const BoomHide_FileName[5] =
{ _T("Image\\boom\\boom0_hide.png"),_T("Image\\boom\\boom1_hide.png") ,_T("Image\\boom\\boom2_hide.png") ,_T("Image\\boom\\boom3_hide.png") ,_T("Image\\boom\\boom4_hide.png") };