#include "Tower.h"

Tower::Tower(Hero& hero, int floors)
{
	this->floorAmount = floors;
	for (int i = 0; i < getFloorAmount(); i++)
	{
		Floor* currentFloor;
		currentFloor = new Floor(hero, i);
		delete currentFloor;
		cout << "Proceding to next floor...";
		Sleep(2000);
	}
}

Tower::~Tower(){ }