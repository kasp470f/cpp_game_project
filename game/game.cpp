// game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Player/Hero.h"
#include "Intro.h"
#include "GameFloor/GameFloor.h"

int main() {
	GameFloor gameFloor(1);
	std::cout << gameFloor.getFloorName() << endl;
	gameFloor.encounter();
	/*Hero hero;
	Intro intro;
	intro.initIntro(hero);*/
	

	return 0;
}