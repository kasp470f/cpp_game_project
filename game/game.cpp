// game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Player/Hero.h"
#include "Intro.h"
#include <irrKlang.h>
//#include "Tower/Tower.h"
using namespace irrklang;

int main() {
	ISoundEngine* engine = createIrrKlangDevice();
	engine->play2D("bell.wav");					//WORKING!
	//engine->play2D("../audio/bell.wav");		//NOT WORKING!


	Hero hero;
	Intro intro;

	system("cls");
	intro.initIntro(hero);
	engine->drop();
}