#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "fruit.h"
#include "map.h"
#include "player.h"
#include "game_status.h"
#include "fruitspawner.h"
#include "startup.h"
using namespace std;
enum eDirection { STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Draw()
{
	system("cls");

	for (int i = 0; i < map.width; i++)
	{
		cout << "#";
	}

	cout << endl;

	for (int i = 0; i < map.height; i++)
	{
		for (int g = 0; g < map.width; g++)
		{
			if (g==0 or g==(map.width-1))
			{
				cout << "#";
			}
			else if (i==player.y and g==player.x)
			{
				cout << "O";
			}
			else if (i==fruit.y and g==fruit.x)
			{
				cout << "F";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	

	for (int i = 0; i < map.width; i++)
	{
		cout << "#";
	}

	cout << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 27:
			gamestatus = false;
			break;
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case LEFT:
		player.x--;
		break;
	case RIGHT:
		player.x++;
		break;
	case UP:
		player.y--;
		break;
	case DOWN:
		player.y++;
		break;
	default:
		break;
	}

	if (player.x > map.width or player.x<0 or player.y>map.height or player.y < 0)
	{
		gamestatus = false;
	}
	if (player.x == fruit.x and player.y == fruit.y)
	{
		FruitSpawner();
	}
}

int main()
{
	Startup();
	while (gamestatus)
	{
		Draw();
		Input();
		Logic();
		Sleep(100);
	}
}
