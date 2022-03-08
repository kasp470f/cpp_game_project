// game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Intro.h"

int main() {
	Intro intro;
	intro.initIntro();

	while (intro.getPlaying())
	{
		intro.mainMenu();
		system("cls");
	}

	return 0;
}