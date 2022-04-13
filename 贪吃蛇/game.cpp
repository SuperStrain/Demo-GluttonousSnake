#include <iostream>
using namespace std;
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>

//光标定位函数
void gotoxy(HANDLE hOut, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
    COORD pos;
    pos.X = x;             //横坐标
    pos.Y = y;            //纵坐标
    SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效

int main()
{
    char prekey = NULL;
    srand((unsigned int)time(NULL));
    Wall wall;
    Food food(wall);
    bool isDead = false;
    wall.initwall();
    wall.draw();
    snake Snake(wall,food);
    Snake.Initsnake();
    food.setfood();

    gotoxy(hOut, 0, Wall::ROW);
    cout << "得分：" << Snake.getSore() << "分" << endl;
    //接收用户输入
    while (!isDead)
    {
        char key = _getch();
        if (prekey==NULL && key == Snake.LEFT)
        {
            continue;
        }
        do
        {
            if (key == Snake.LEFT || key == Snake.RIGHT || 
                key == Snake.DOWN || key == Snake.UP)
            {
                if ((prekey == Snake.LEFT && key == Snake.RIGHT) ||
                    (prekey == Snake.RIGHT && key == Snake.LEFT) ||
                    (prekey == Snake.UP && key == Snake.DOWN) ||
                    (prekey == Snake.DOWN && key == Snake.UP))
                {
                    key = prekey;
                }
                else
                {
                    prekey = key;
                }
                if (Snake.move(key) == true)
                {
                    //system("cls");
                    //wall.draw();
                    gotoxy(hOut, 0, Wall::ROW);
                    cout << "得分：" << Snake.getSore() << "分" << endl;
                    Sleep(400);
                }
                else
                {
                    isDead = true;
                    break;
                }
            }
            else
            {
                key = prekey;//强制将错误按键化作为上一个按键
            } 
        } while (_kbhit()==0);
        if (Snake.move(key) == true)
        {
            //system("cls");
            //wall.draw();
            gotoxy(hOut, 0, Wall::ROW);
            cout << "得分：" << Snake.getSore() << "分" << endl;
            Sleep(Snake.getSleepTime());
        }
        else
        {
            isDead = true;
            break;
        }
    }
    system("pause");
    return 0;
}

