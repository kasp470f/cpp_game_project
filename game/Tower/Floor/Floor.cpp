#include "Floor.h"
#include "../../Intro.h"

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

//Instantiates a new floor
Floor::Floor(Hero& hero, int floorLevel)
{
	this->hero = &hero;
	this->enemy = Monster();
	this->floorLevel = floorLevel;

	encounter();
}

//Floor destructor
Floor::~Floor(){ }

void Floor::encounter()
{
	system("cls");
	while (hero->getHealth() >= 1 || enemy.getHealth() >= 1)
	{
		int selectedAction = 0;
		bool checkingAction = true;
		while (checkingAction)
		{
			enemy.printCombatStats();
			hero->printCombatStats();
			cout << endl;

			// Change the color of certain text part
			if (selectedAction == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "[ATTACK]";

			if (selectedAction == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "[DEFEND]";

			if (selectedAction == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "[INVENTORY]";

			if (selectedAction == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "[FLEE]";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << endl;

			int c = 0;
			switch ((c = _getch())) {
			case KEY_LEFT:
				selectedAction--;
				if (selectedAction < 0) selectedAction = 2;
				break;
			case KEY_RIGHT:
				selectedAction++;
				if (selectedAction > 3) selectedAction = 0;
				break;
			case ENTER:
				checkingAction = false;
				break;
			}

			system("cls");
		};

		// Attack !THIS NEEDS TO BE MADE MORE EFFICIENT!
		if (selectedAction == 0) {
			if (hero->getSpeed() >= enemy.getSpeed()) {
				if (hero->getHealth() >= 1) {
					int heroAttackDamage = (int)ceil(hero->getAttackMax() - (enemy.getDefense() / 2));
					if (heroAttackDamage < 0) {
						enemy.takeDamage(heroAttackDamage);
						cout << hero->getName() << " attacked " << enemy.getName() << " for " << heroAttackDamage << " damage!" << endl;
					}
					else {
						cout << hero->getName() << " attacked " << enemy.getName() << " but swung too wide and missed" << endl;
					}
				}

				if (enemy.getHealth() >= 1) {
					int enemyAttackDamage = (int)ceil(enemy.getAttack() - (hero->getDefense() / 2));
					if (enemyAttackDamage < 0) {
						hero->takeDamage(enemyAttackDamage);
						cout << enemy.getName() << " attacked " << hero->getName() << " for " << enemyAttackDamage << " damage!" << endl;
					}
					else {
						cout << enemy.getName() << " attacked " << hero->getName() << " but swung too wide and missed" << endl;
					}
				}
			}
			else {
				if (enemy.getHealth() >= 1) {
					int enemyAttackDamage = (int)ceil(enemy.getAttack() - (hero->getDefense() / 2));
					if (enemyAttackDamage < 0) {
						hero->takeDamage(enemyAttackDamage);
						cout << enemy.getName() << " attacked " << hero->getName() << " for " << enemyAttackDamage << " damage!" << endl;
					}
					else {
						cout << enemy.getName() << " attacked " << hero->getName() << " but swung too wide and missed" << endl;
					}
				}

				if (hero->getHealth() >= 1) {
					int heroAttackDamage = (int)ceil(hero->getAttackMax() - (enemy.getDefense() / 2));
					if (heroAttackDamage < 0) {
						enemy.takeDamage(heroAttackDamage);
						cout << hero->getName() << " attacked " << enemy.getName() << " for " << heroAttackDamage << " damage!" << endl;
					}
					else {
						cout << hero->getName() << " attacked " << enemy.getName() << " but swung too wide and missed" << endl;
					}
				}
			}
			Sleep(3000);
		}
		//Take def potion
		else if (selectedAction == 1) {
			int increasedDefense = hero->getDefense() + 5;
			hero->setDefense(increasedDefense);
			cout << hero->getName() << " increased his defense by 5, bringing it up to " << increasedDefense << endl;

			int enemyAttackDamage = (int)ceil(enemy.getAttack() - (hero->getDefense() / 2));
			hero->takeDamage(enemyAttackDamage);
			cout << enemy.getName() << " attacked " << hero->getName() << " for " << enemyAttackDamage << " damage!" << endl;

			hero->setDefense(increasedDefense - 5);
			cout << hero->getName() << "'s increased defense has returned to its normal state of " << hero->getDefense() << endl;
			Sleep(3000);
		}
		else if(selectedAction == 3)
		{
			system("cls");
			flee();
			Sleep(3000);
			break;
		}

		system("cls");
	};
}

//void Floor::encounter()
//{
//	//print monster's stats
//	cout << "You encounter a ";
//	mob.printCombatStats();
//	
//	//print hero's stats
//	cout << "You have ";
//	hero.printCombatStats();
//	cout << "What would you like to do? [(A)TTACK] [(F)LEE] [OPEN (I)NVENTORY]" << endl;
//
//	char choice;
//	cin >> choice;
//	
//	switch (toupper(choice))
//	{
//	case 'A':
//		attack();
//		break;
//	case 'F':
//		flee();		
//		break;
//	case 'I':
//		openInventory();		
//		break;
//	}
//}
//Gets hero and monster stats and initiates fight after checking fastest speed
//void Floor::attack()
//{
//	cout << endl << "-------- Attackmode initialized! --------" << endl;
//	bool heroFastest = false;
//	if (hero.getSpeed() < mob.getSpeed()) { heroFastest = true; }
//
//	//The stats that - for now - decides the outcome of the encounter
//	int heroAttack = hero.getAttack()+1;
//	int heroHealth = hero.getHealth()+20;
//	int mobHealth = mob.getHealth();
//	int mobAttack = mob.getAttack();
//	
//	//Attack mode that switches between combatants
//	do 
//	{		
//		switch (heroFastest)
//		{
//			case true:
//				cout << "You attack " << mob.getName() << " for " << to_string(heroAttack) << " damage." << endl;
//				mobHealth -= heroAttack;
//				if (mobHealth <= 0) {
//					cout << mob.getName() << " has died." << endl;
//				}
//				else {
//					cout << mob.getName() << " has " << to_string(mobHealth) << " HP left." << endl;
//					heroFastest = false;
//				}
//				break;
//			default:				
//				cout << mob.getName() << " attacks you for " << to_string(mobAttack) << " damage." << endl;
//				heroHealth -= mobAttack;
//				if (heroHealth <= 0) {
//					cout << "Your epic adventure has ended!"<<endl;
//					cout << "---------------- GAME OVER! ----------------" << endl;
//				}
//				else {
//					cout << "You have " << to_string(heroHealth) << " HP left." << endl;
//					heroFastest = true;
//				}
//				break;
//		}
//	} while (heroHealth > 0 && mobHealth > 0);
//	hero.setHealth(heroHealth);
//}

void Floor::flee()
{
	cout << endl << "-------- You flee... --------" << endl;
}

void Floor::openInventory()
{
	cout << endl << "-------- You open your inventory... --------" << endl;
}
