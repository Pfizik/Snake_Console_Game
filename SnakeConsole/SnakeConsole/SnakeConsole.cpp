#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "fruit.h"
#include "map.h"
#include "player.h"
#include "game_status.h"
#include "fruitspawner.h"
#include "startup.h"
#include "tail.h"
using namespace std;
enum eDirection { STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Draw()
{
	system("cls");

	for (int i = 0; i < map.width+2; i++)
	{
		cout << "#" ;
	}

	cout << endl;

	for (int i = 0; i < map.height; i++)
	{
		for (int g = 0; g < map.width; g++)
		{
			if (g==0)
			{
				cout << "#";
			}
			if (i==player.y and g==player.x)
			{
				cout << "O";
			}
			else if (i==fruit.y and g==fruit.x)
			{
				cout << "F";
			}
			else
			{
				bool printcheck = false;
				for (int j = 0; j < tail.n; j++)
				{
					if (tail.x[j] == g and tail.y[j] == i)
					{
						cout << "o";
						printcheck = true;
					}
				}
				if (!printcheck)
				{
					cout << " ";
				}
			}
			if (g == map.width - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}

	

	for (int i = 0; i < map.width+2; i++)
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
	int px = tail.x[0];
	int py = tail.y[0];
	int p2x, p2y;
	tail.x[0] = player.x;
	tail.y[0] = player.y;

	for (int i = 1; i < tail.n; i++)
	{
		p2x = tail.x[i];
		p2y = tail.y[i];
		tail.x[i] = px;
		tail.y[i] = py;
		px = p2x;
		py = p2y;
	}

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

	for (int i = 0; i < tail.n; i++)
	{
		if (tail.x[i] == player.x and tail.y[i] == player.y)
		{
			gamestatus = false;
		}
	}

	if (player.x == fruit.x and player.y == fruit.y)
	{
		FruitSpawner();
		tail.n++;
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
