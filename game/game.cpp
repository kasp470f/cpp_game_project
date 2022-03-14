// game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player/Hero.h"
#include "Intro.h"
#include "Inventory/Inventory.h"
//#include "Tower/Tower.h"

int main() {
	Hero hero;
	Intro intro;

	Inventory inv;

	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());

	//inv.debugPrint();

	intro.initIntro(hero);
}