#include "GameFloor.h"


GameFloor::GameFloor(int floorLevel)
{
	this->FloorName = "Level: " + std::to_string(floorLevel);	
}

GameFloor::~GameFloor(){ }

std::string GameFloor::getFloorName()
{
	return FloorName;
}