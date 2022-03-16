#include "Game.h"
#include "Tower/Tower.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

Game::Game()
{
	choice = 0;
	playing = true;
}

Game::~Game()
{
}

void Game::initGame(Hero& hero)
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
	system("cls");
}

int Game::actionSelection()
{
	int selectedAction = 0;
	bool checkingAction = true;
	while (checkingAction) {
		cout << "Welcome to the TOWER OF DOOM" << endl;

		// Change the color of certain text part
		if (selectedAction == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "[Enter the Tower of Doom]";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << endl;

		if (selectedAction == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "[Character Stats]";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << endl;

		if (selectedAction == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "[Inventory]";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << endl;

		if (selectedAction == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "[Quit Game]";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << endl;

		int c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			selectedAction--;
			if (selectedAction < 0) selectedAction = 3;
			break;
		case KEY_DOWN:
			selectedAction++;
			if (selectedAction > 3) selectedAction = 0;
			break;
		case KEY_ENTER:
			checkingAction = false;
			break;
		}

		system("cls");
	}
	return selectedAction;
}

void Game::mainMenu()
{
	Inventory inv;
	Weapon* weapon1 = new Weapon("Excalibur", 10000, 2, 4);
	Armor* chest = new Armor("Chest of Doom", 5000, "Chest", 50);
	Armor* helm = new Armor("Helm of Doom", 4000, "Helm", 40);
	Armor* gloves = new Armor("Gloves of Doom", 3700, "Gloves", 37);
	Armor* bracers = new Armor("Bracers of Doom", 3000, "Helm", 30);
	Armor* leggings = new Armor("Leggings of Doom", 3500, "Helm", 35);
	Armor* boots = new Armor("Boots of the Fairy", 100, "Helm", 1);
	inv.addItem(*weapon1);
	inv.addItem(*chest);
	inv.addItem(*helm);
	inv.addItem(*gloves);
	inv.addItem(*bracers);
	inv.addItem(*leggings);
	inv.addItem(*boots);

	

	

	choice = actionSelection();
	cout << endl;

	Tower* tower;

	switch (choice)
	{
	case 0:
		system("cls");
		tower = new Tower(hero, 100);
		playing = true;
		break;

	case 1:
		system("cls");
		hero.printStats();
		system("pause");
		break;

	case 2:
		system("cls");
		inv.printInventory();
		system("pause");
		break;

	case 3:
		exit(1);
		break;
	}
}