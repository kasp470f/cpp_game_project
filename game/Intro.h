#pragma once

#include "Player/Hero.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "Inventory/Item.h"

using namespace std;

class Intro
{
public:
	Intro();
	virtual ~Intro();

	//Funktioner
	void initIntro(Hero &hero);
	void initInventory(Item& item);
	void mainMenu();

	//Accessor
	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;
	Hero hero;
};