#pragma once
#include "../Player/Hero.h"
#include "Floor/Floor.h"
#include <iostream>
using namespace std;


class Tower
{
private:
	Hero* hero;
	int floorAmount;

public:
	Tower(Hero& hero, int floors);
	~Tower();

	inline const int& getFloorAmount() const { return floorAmount; };
};