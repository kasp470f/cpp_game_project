#pragma once
#include <string>
#include <iostream>
using namespace std;

class GameFloor
{
private:
	std::string FloorName;
	int FloorLevel;
public:
	GameFloor(int floorLevel);
	~GameFloor();
	string getFloorName();
	void encounter();
	void attack();
	void flee();
	void openInventory();
};