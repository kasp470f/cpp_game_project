// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player/Hero.h"
#include "Game.h"

int main() {
	Hero hero;
	Game game;

	system("cls");
	game.initGame(hero);
}