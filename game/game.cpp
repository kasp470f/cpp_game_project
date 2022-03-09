// game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Player/Hero.h"
#include "Intro.h"
#include "Tower/Floor/Floor.h"

int main() {
	Hero hero;
	Intro intro;
	intro.initIntro(hero);

	Floor s(hero, 1);

	return 0;
}