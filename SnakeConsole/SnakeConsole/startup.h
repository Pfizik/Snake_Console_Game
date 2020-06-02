#pragma once
#include <iostream>
#include "fruit.h"
#include "map.h"
#include "player.h"
#include "game_status.h"

void Startup()
{
	player.x = map.width / 2;
	player.y = map.height / 2;

	FruitSpawner();
}