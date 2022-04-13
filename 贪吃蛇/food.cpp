#include <iostream>
using namespace std;
#include "food.h"
#include"wall.h"
#include<Windows.h>

void gotoxy2(HANDLE hOut2, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);

Food::Food(Wall& tempwall):wall(tempwall)
{
}
void Food::setfood()
{
	while (true)
	{
		foodx = rand() % (Wall::ROW - 2) + 1;
		foody = rand() % (Wall::COL - 2) + 1;
		//如果坐标位置是蛇身，就重新设置食物位置
		if (wall.getwall(foodx, foody) == ' ')
		{
			wall.setwall(foodx, foody, '#');
			gotoxy2(hOut2, foody*2, foodx);
			cout << "#";
			break;
		}
	}
}	
