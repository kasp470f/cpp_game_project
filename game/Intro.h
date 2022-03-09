#pragma once

#include "Player/Hero.h"
#include <string>
#include <iostream>

using namespace std;

class Intro
{
public:
	Intro();
	virtual ~Intro();

	//Funktioner
	void initIntro();
	void mainMenu();

	//Accessor
	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;

	//Helten i spillet
	Hero hero;
};