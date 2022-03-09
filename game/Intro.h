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
	void initIntro(Hero &hero);
	void mainMenu();

	//Accessor
	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;
	Hero hero;
};