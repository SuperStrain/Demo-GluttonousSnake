#include "wall.h"

void Wall::initwall()
{
	for(int i=0;i<ROW;i++)
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
				gamearray[i][j] = '*';
			else
				gamearray[i][j] = ' ';
		}
}

void Wall::draw()
{
	for (int i = 0; i <ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << gamearray[i][j]<<' ';
		if (i == 10)
			cout << "\tA : left";
		if (i == 11)
			cout << "\tD : right";
		if (i == 12)
			cout << "\tW : top";
		if (i == 13)
			cout << "\tS : bottom";
		if (i == 14)
			cout << "create by YangYang";
		cout << endl;
	}
}

void Wall::setwall(int x, int y, char c)
{
	gamearray[x][y] = c;
}

char Wall::getwall(int x, int y)
{
	return gamearray[x][y];
}
