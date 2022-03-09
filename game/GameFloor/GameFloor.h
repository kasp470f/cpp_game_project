#pragma once
#include <string>
#include <iostream>

class GameFloor
{
private:
	std::string FloorName;
public:
	GameFloor(int floorLevel);
	~GameFloor();
	std::string getFloorName();
};