#pragma once
#include<iostream>
#include"wall.h"
using namespace std;

class Food
{
public:
	Food(Wall &tempwall);
	int foodx;
	int foody;
	void setfood();
	Wall& wall;
private:

};
