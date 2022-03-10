#pragma once
#include <string>
#include "../../Monsters/Monster.h"
#include "../../Player/Hero.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

class Floor
{
private:	
	Monster enemy;
	Hero* hero;
	int floorLevel;

	void encounter();

public:	
	Floor(Hero &hero, int floorLevel);
	~Floor();
	
	Hero getPlayer() { return *hero; }
	Monster getEnemy() { return enemy; }
	int getFloorLevel() { return floorLevel; }
	
	void flee();
	void openInventory();
};