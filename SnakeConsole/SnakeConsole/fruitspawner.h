#pragma once
#include <iostream>
#include <ctime>
#include <algorithm>
#include "fruit.h"
#include "map.h"
#include "player.h"
#include "game_status.h"

void FruitSpawner()
{
	srand(time(0));
	int x = rand() %map.width-2;
	int y = rand() %map.height-2;
	if (x > 0 and y > 0)
	{
		fruit.x = x;
		fruit.y = y;
	}
	else
	{
		FruitSpawner();
	}
}