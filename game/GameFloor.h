#pragma once
#include <string>

class GameFloor
{
private:
	std::string FloorName;
public:
	GameFloor(int floorLevel);
	~GameFloor();
	std::string getFloorName();
};