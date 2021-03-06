#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <graphics.h>

#pragma comment(lib,"Winmm.lib")

using namespace std;

//特殊宏定义
#define Int unsigned short int
#define MapInt unsigned char
#define KEY_DOWN(VK_NONAME) (GetAsyncKeyState(VK_NONAME) & 0x8000)



//绘图坐标
struct pos_XY
{
	short int x, y;
};

/*****************
设置窗口的相关参数
*****************/
const Int source_map_px = 8;//原坦克大战一个地图单元对应的像素大小
const Int px_multiple = 3;//图片像素放大倍数
const Int map_px = source_map_px * px_multiple;//每个地图单元的实际像素大小
const Int unit_px = map_px * 2;//坦克、道具的绘图大小
const Int bullet_px = map_px / 2;//子弹绘图大小
//地图数组的行、列数
const Int map_row = 30;
const Int map_col = 32;
//单元数组的行、列数，为地图数组的两倍，以此达到坦克等移动“半格”的效果
const Int unit_row = map_row * 2;
const Int unit_col = map_col * 2;

//游戏界面的宽和高（像素）
const Int map_wide = map_px * map_col;
const Int map_height = map_px * map_row;
//菜单按钮的宽和高
const Int menue_wide = 80;
const Int menue_height = 40;
//菜单文字的宽度和高度、字体类型
const Int text_size = 30;
const wchar_t* const text_style = _T("华文楷体");


const Int unit_size = 4;//每个单元在unit矩阵中占用的宽度（坦克长宽为4，炮弹为2）
const Int bullet_size = unit_size / 2;
const Int unit_sizeInMap = unit_size / 2;

/*******************************
物体移动速度、画面刷新速率等设置
*******************************/
const Int RenewClock = 1000 / 60;//画面刷新周期
enum Speed//每次刷新时物体应移动的像素数
{
	SlowSpeed = (2 * unit_sizeInMap * map_px) * RenewClock / 1000, //每秒走两大格
	NormalSpeed = (3 * unit_sizeInMap * map_px) * RenewClock / 1000, //每秒走三大格
	FastSpeed = (4 * unit_sizeInMap * map_px) * RenewClock / 1000,//每秒走四大格
	HighSpeed = 2 * FastSpeed,
	VeryHighSpeed = 2 * HighSpeed
};


const int slowSpeed = map_px / 8;
const int medianSpeed = map_px / 4;
const int fastSpeed = map_px / 3;
const int superSpeed = map_px / 2;


const int lowLife = 5;
const int medianLife = 15;
const int highLife = 30;
const int playerLowLife = 50;
const int playerMedianLife = 100;
const int playerHighLife = 150;
const int playerSuperLife = 300;


const int shortShootInterval = 100;
const int medianShootInterval = 200;
const int longShootInterval = 300;
const int superLongShootIntervel = 400;

/***************
各单位的相关参数
***************/
enum MapType//地图类型
{
	EMPTY,//空地
	WALL_UL = 0x01, WALL_UR = 0x02, WALL_DL = 0x04, WALL_DR = 0x08,//四分之一块砖
	WALL_UP = 0x03, WALL_LEFT = 0x05, WALL_RIGHT = 0x0A, WALL_DOWN = 0x0C,//半块砖
	WALL = 0x0F,//砖墙
	IRON,//防爆门
	BORDER,//地图边界
	SEA,//海面
	ICE = 0x21,//冰面
	JUNGLE,//丛林
};
enum UnitType//各单位类型值，用于碰撞检测
{
	//子弹
	BULLET = 500,
	P1 = 300,//1号玩家
	P2 = 400,//2号玩家
	CP = 600,//敌人
	COMMANDER = 0xC8,//指挥官
	BOOM,
};
enum Direction//方向，绘制、开炮时用
{
	UP, LEFT, DOWN, RIGHT, DirectionCount
};
enum Armor//坦克装甲等级
{
	DEAD = -1, NORMAL, LIGHT, STRONG, HEAVY, ArmorCount
};
enum Key//键盘控制
{
	Key_UP = 'W', Key_LEFT = 'A', Key_RIGHT = 'D', Key_DOWN = 'S',
	Key_SHOOT = 'J', Key_PAUSE = 'P',
	Key_START = 'F', Key_SELECT = 'R'
};

enum Effect
{
	SPEED_UP_LV1, SPEED_UP_LV2, SLOW_SPEED, STRONGER_ARMOR_LV1, STRONGER_ARMOR_LV2, STRONGER_ARMOR_LV3
};

/*************
玩家图片文件名
**************/
//玩家四种形态的四个方向的图片
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
电脑玩家图片文件名
******************/
//四种敌军坦克的四个方向的图片
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
地图元素的图片文件名
********************/
enum MapFileNum
{
	FileNum_wall, FileNum_iron, FileNum_border, FileNum_sea0, FileNum_sea1, FileNum_ice, FileNum_jungle, MapFileCount
};
const wchar_t* const Map_FileName[MapFileCount] =
{ _T("Image\\map\\wall.png"),_T("Image\\map\\iron.png"),_T("Image\\map\\border.png"),_T("Image\\map\\sea0.png"),_T("Image\\map\\sea1.png"),_T("Image\\map\\ice.png"),_T("Image\\map\\jungle.png") };

//子弹图片文件名
const wchar_t* const Bullet_FileName[DirectionCount] =
{ _T("Image\\bullet\\bullet_up.png"),_T("Image\\bullet\\bullet_left.png"),_T("Image\\bullet\\bullet_down.png"),_T("Image\\bullet\\bullet_right.png") };
const wchar_t* const BulletHide_FileName[DirectionCount] =
{ _T("Image\\bullet\\bullet_hide_up.png"),_T("Image\\bullet\\bullet_hide_left.png"),_T("Image\\bullet\\bullet_hide_down.png"),_T("Image\\bullet\\bullet_hide_right.png") };

//爆炸图片文件名
const wchar_t* const Boom_FileName[5] =
{ _T("Image\\boom\\boom0.png"),_T("Image\\boom\\boom1.png") ,_T("Image\\boom\\boom2.png") ,_T("Image\\boom\\boom3.png") ,_T("Image\\boom\\boom4.png") };
const wchar_t* const BoomHide_FileName[5] =
{ _T("Image\\boom\\boom0_hide.png"),_T("Image\\boom\\boom1_hide.png") ,_T("Image\\boom\\boom2_hide.png") ,_T("Image\\boom\\boom3_hide.png") ,_T("Image\\boom\\boom4_hide.png") };