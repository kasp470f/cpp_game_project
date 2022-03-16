#pragma once

#include "Player/Hero.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "Tower/Floor/Floor.h"
#include "Inventory/Type/Weapon.h"
#include "Inventory/Type/Armor.h"

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	//Funktioner
	void initGame(Hero &hero);
	int actionSelection();
	void mainMenu();

	//Accessor
	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;
	Hero hero;
};