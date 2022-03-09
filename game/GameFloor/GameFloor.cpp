#include "GameFloor.h"
#include "../Monsters/Monster.h"
#include "../Player/Hero.h"

//Create a new monster to fight
Monster mob;

//Create hero
Hero hero;

//Instantiates a new floor
GameFloor::GameFloor(int floorLevel)
{
	this->FloorLevel = floorLevel;
	this->FloorName = "Level: " + to_string(FloorLevel);
}

//Floor destructor
GameFloor::~GameFloor(){ }

//Returns the floor's name
string GameFloor::getFloorName()
{
	return FloorName;
}

void GameFloor::encounter()
{
	//print monster's stats
	//[HP:10 - ATK : 5 - DEF : 5 - SPD : 5
	cout << "You encounter a " 
		<< mob.getName() << " [ HP: "
		<< mob.getHealth() << " - ATK: "
		<< mob.getAttack() << " - DEF: "
		<< mob.getDefense() << " - SPD: "
		<< mob.getSpeed() << " ]" << endl;
	//print hero's stats
	hero.printStats();
	cout << "What would you like to do? [(A)TTACK] [(F)LEE] [(I)NVENTORY]" << endl;
	char choice;
	cin >> choice;
	
	switch (toupper(choice))
	{
	case 'A':
		attack();
		break;
	case 'F':
		//flee();
		cout << endl << "-------- You flee... --------" << endl;
		break;
	case 'I':
		//openInventory();
		cout << endl << "-------- You open your inventory..." << endl;
		break;
	}
}
//Gets hero and monster stats and initiates fight after checking fastest speed
void GameFloor::attack()
{

	cout << endl << "-------- Attackmode initialized! --------" << endl;
	bool heroFastest = false;
	if (hero.getSpeed() < mob.getSpeed()) {
		heroFastest = true;
	}

	//The stats that - for now - decides the outcome of the encounter
	int heroAttack = hero.getAttack()+1;
	int heroHealth = hero.getHealth()+20;
	int mobHealth = mob.getHealth();
	int mobAttack = mob.getAttack();
	
	//Attack mode that switches between combatants
	do 
	{		
		switch (heroFastest)
		{
			case true:
				cout << "You attack " << mob.getName() << " for " << to_string(heroAttack) << " damage." << endl;
				mobHealth -= heroAttack;
				if (mobHealth <= 0) {
					cout << mob.getName() << " has died." << endl;
				}
				else {
					cout << mob.getName() << " has " << to_string(mobHealth) << " HP left." << endl;
					heroFastest = false;
				}
				break;
			default:				
				cout << mob.getName() << " attacks you for " << to_string(mobAttack) << " damage." << endl;
				heroHealth -= mobAttack;
				if (heroHealth <= 0) {
					cout << "Your epic adventure has ended!"<<endl;
					cout << "---------------- GAME OVER! ----------------" << endl;
				}
				else {
					cout << "You have " << to_string(heroHealth) << " HP left." << endl;
					heroFastest = true;
				}
				break;
		}
	} while (heroHealth > 0 && mobHealth > 0);
	hero.setHealth(heroHealth);
}

void GameFloor::flee()
{
}

void GameFloor::openInventory()
{
}
