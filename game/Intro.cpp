#include "Intro.h"

Intro::Intro()
{
	choice = 0;
	playing = true;
}

Intro::~Intro()
{
}

void Intro::initIntro(Hero& hero)
{
	string name;
	cout << "Welcome to the TOWER OF DOOM";
	cout << endl;

	cout << "Enter your hero's name: ";
	getline(cin, name);

	hero.initialize(name);
	this->hero = hero;

	while (getPlaying())
	{
		system("cls");
		mainMenu();
	}
}

void Intro::mainMenu()
{
	Inventory inv;

	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());

	cout << "1: Enter the Tower of Doom" << endl;
	cout << "2: Buy gear (Not working atm)" << endl;
	cout << "3: Character Stats" << endl;
	cout << "4: Inventory" << endl;
	cout << endl;
	cout << "0: Quit Game" << endl;

	string input;
	do
	{
		cin >> input;
	} while (!isdigit(input[0]));

	choice = stoi(input);
	cout << endl;
	switch (choice)
	{
	case 1:
		playing = false;
		break;

	case 2:
		playing = false;
		break;

	case 3:
		system("cls");
		hero.printStats();
		system("pause");
		break;

	case 4:
		system("cls");
		inv.debugPrint();
		system("pause");
		break;

	case 0:
		exit(1);
		break;

	default:
		break;
	}
}