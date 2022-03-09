#pragma once
#include "../../Monsters/Monster.h"
#include "../../Player/Hero.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

class Floor
{
private:
	Monster enemy;
	Hero* hero;
	int floorLevel;

	void Combat();
public:
	Floor(Hero &hero, int floorLevel);
	~Floor();

	Hero getPlayer() { return *hero; }
	Monster getEnemy() { return enemy; }
	int getFloorLevel() { return floorLevel; }
};

