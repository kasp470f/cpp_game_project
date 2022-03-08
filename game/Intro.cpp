#include "Intro.h"

Intro::Intro()
{
	choice = 0;
	playing = true;
}

Intro::~Intro()
{
}

void Intro::initIntro()
{
	string name;
	cout << "Welcome to the TEMPLE OF DOOM";
	cout << endl;

	cout << "Enter your hero's name: ";
	getline(cin, name);

	hero.initialize(name);
}

void Intro::mainMenu()
{
	cout << "1: Enter the Tower of Doom" << endl;
	cout << "2: Buy gear" << endl;
	cout << "3: Character Stats" << endl;
	cout << endl;
	cout << "0: Quit Game" << endl;

	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		playing = true;
		break;

	case 2:
		playing = true;
		break;

	case 3:
		hero.printStats();
		break;

	case 0:
		playing = false;
		break;

	default:
		break;
	}
}