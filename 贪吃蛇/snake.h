#pragma once
#include<iostream>
using namespace std;
#include"wall.h"
#include"food.h"
class snake
{
public:
	snake(Wall &tempwall,Food &tempfood);//******
	struct Point
	{
		int x;
		int y;
		Point* next;
	};
	enum {
		UP='w', DOWN='s', LEFT='a', RIGHT='d' 
	};
	Point* head;
	Wall &wall;//******
	Food &food;
	bool isRool;
	int getSore();
	void Initsnake();
	void DestroyAllPonit();
	void addpoint(int x,int y);
	void deletepoint();
	bool move(char key);
	//设定难度
	//获取刷屏时间
	int getSleepTime();
	//获取蛇身段
	int countList();
private:

};
