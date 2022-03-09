#include "GameFloor.h"
#include "../Monsters/Monster.h"
#include "../Player/Hero.h"

//Create a new monster to fight
Monster mob;
Hero hero;

GameFloor::GameFloor(int floorLevel)
{
	this->FloorLevel = floorLevel;
	this->FloorName = "Level: " + to_string(FloorLevel);
	//mob = new Monster();
}

GameFloor::~GameFloor(){ }

std::string GameFloor::getFloorName()
{
	return FloorName;
}

void GameFloor::encounter()
{
	//print monster's stats
	cout << "You encounter a " 
		<< mob.getName() << " [ HP: "
		<< mob.getHealth() << " - ATK: "
		<< mob.getAttack() << " - DEF: "
		<< mob.getDefense() << " - SPD: "
		<< mob.getSpeed() << " ]" << endl;
	//[HP:10 - ATK : 5 - DEF : 5 - SPD : 5
	//cout << hero.printCombatStats();
	cout << "What would you like to do? [(A)TTACK] [(F)LEE] [(I)NVENTORY]" << endl;
	char choice;
	cin >> choice;
	
	switch (toupper(choice))
	{
	case 'A':
		//attack();
		cout << endl << "You attack!";
		break;
	case 'F':
		//flee();
		cout << endl << "You flee...";
		break;
	case 'I':
		//openInventory();
		cout << endl << "You open your inventory...";
		break;
	}
}

//void GameFloor::attack()
//{
//	bool heroFastest = false;
//	if (hero.getSpeed()>mob.getSpeed()){
//		heroFastest = true;
//	}
//	do 
//	{
//		switch (heroFastest)
//		{
//			case true:
//				int heroAttack = hero.getAttack();
//				cout << "You attack " << mob.getName() << "for " << to_string(heroAttack) << " damage.";
//				mob.setHealth(mob.getHealth() -= heroAttack);
//					if (mob.getHealth()>0){
//						cout << mob.getName() << " has died";
//					}
//					else {
//						cout << mob.getName() << " has " << mob.getHealth() << " HP left";
//						heroFastest = false;
//					}
//				break;
//			default:
//				int mobAttack = mob.getAttack();
//				cout << mob.getName() << " attacks you for " << to_string(mobAttack) << " damage.";
//				hero.setHealth(hero.getHealth() -= mobAttack);
//				if (hero.getHealth() <= 0) {
//					cout << "Your epic adventure has ended."<<endl;
//					cout << "----------------GAME OVER----------------";
//				}
//				else {
//					cout << "You have " << hero.getHealth() << " HP left";
//					heroFastest = true;
//				}
//				break;
//		}
//	} while (hero.getHealth()>0 && mob.getHealth()>0);
//}
//
//void GameFloor::flee()
//{
//}
//
//void GameFloor::openInventory()
//{
//}
