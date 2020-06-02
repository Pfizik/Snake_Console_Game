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
	fruit.x = rand() % map.width-2;
	fruit.y = rand() % map.height-2;
}