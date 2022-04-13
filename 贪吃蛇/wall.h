#pragma once
#include<iostream>
using namespace std;
class Wall
{
public:
	enum 
	{
		ROW = 26,
	    COL = 26
	};
	void initwall();//设置墙体
	void draw();//输出（画出）游戏空间内的所有图案
	void setwall(int x,int y,char c);//根据坐标设置游戏空间内的符号
	char getwall(int x,int y);			//根据索引获得当前位置的符号
private:
	char gamearray[ROW][COL];
};


