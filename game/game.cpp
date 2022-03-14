// game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player/Hero.h"
#include "Intro.h"
#include <irrKlang.h>
//#include "Tower/Tower.h"
using namespace irrklang;

int main() {
	ISoundEngine* engine = createIrrKlangDevice();
	engine->play2D("bell.wav");
	Hero hero;
	Intro intro;

	//Inventory inv;
	//inv.addItem(Item());
	//inv.addItem(Item());
	//inv.addItem(Item());
	//inv.addItem(Item());
	//inv.addItem(Item());
	//inv.addItem(Item());
	//inv.addItem(Item());

	//inv.debugPrint();
	system("cls");
	intro.initIntro(hero);

	while (intro.getPlaying())
	{
		intro.mainMenu();
	}

	engine->drop();
	return 0;
}