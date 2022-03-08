#include "GameFloor.h"
#include <iostream>
#include <string>

GameFloor::GameFloor(int floorLevel)
{
	this->FloorName = "Level: " + std::to_string(floorLevel);	
}

GameFloor::~GameFloor(){ }

std::string GameFloor::getFloorName()
{
	return FloorName;
}