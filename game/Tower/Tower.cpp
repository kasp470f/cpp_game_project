#include "Tower.h"

Tower::Tower(Hero& hero, int floors)
{
	this->floorAmount = floors;
	for (int i = 0; i < getFloorAmount(); i++)
	{
		irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();
		engine->setSoundVolume(0.5);
		Floor* currentFloor;
		currentFloor = new Floor(hero, i, engine);
		delete currentFloor;
		cout << "Proceding to next floor...";
		Sleep(2000);
		engine->drop();
	}
}

Tower::~Tower(){ }