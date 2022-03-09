#include "Floor.h"

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

Floor::Floor(Hero &hero, int floorLevel)
{
	this->hero = &hero;
	this->enemy = Monster();

	this->floorLevel = floorLevel;

	Combat();
}

Floor::~Floor()
{
}

void Floor::Combat()
{
	while (hero->getHealth() >= 1 || enemy.getHealth() >= 1) 
	{
		int selectedAction = 0;
		bool checkingAction = true;
		while(checkingAction) {
			enemy.combatStats();
			hero->combatStats();
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
				if (selectedAction > 2) selectedAction = 0;
				break;
			case ENTER:
				checkingAction = false;
				break;
			}

			system("cls");
		}

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
						cout << hero->getName() << " attacked " << enemy.getName() << " but swung to wide and missed" << endl;
					}
				}

				if (enemy.getHealth() >= 1) {
					int enemyAttackDamage = (int)ceil(enemy.getAttack() - (hero->getDefense() / 2));
					if (enemyAttackDamage < 0) {
						hero->takeDamage(enemyAttackDamage);
						cout << enemy.getName() << " attacked " << hero->getName() << " for " << enemyAttackDamage << " damage!" << endl;
					}
					else {
						cout << enemy.getName() << " attacked " << hero->getName() << " but swung to wide and missed" << endl;
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
						cout << enemy.getName() << " attacked " << hero->getName() << " but swung to wide and missed" << endl;
					}
				}

				if (hero->getHealth() >= 1) {
					int heroAttackDamage = (int)ceil(hero->getAttackMax() - (enemy.getDefense() / 2));
					if (heroAttackDamage < 0) {
						enemy.takeDamage(heroAttackDamage);
						cout << hero->getName() << " attacked " << enemy.getName() << " for " << heroAttackDamage << " damage!" << endl;
					}
					else {
						cout << hero->getName() << " attacked " << enemy.getName() << " but swung to wide and missed" << endl;
					}
				}
			}
			Sleep(2000);
		}
		else if (selectedAction == 1) {
			int increasedDefense = hero->getDefense() + 5;
			hero->setDefense(increasedDefense);
			cout << hero->getName() << " increased his defense by 5, brining it up to " << increasedDefense << endl;

			int enemyAttackDamage = (int)ceil(enemy.getAttack() - (hero->getDefense() / 2));
			hero->takeDamage(enemyAttackDamage);
			cout << enemy.getName() << " attacked " << hero->getName() << " for " << enemyAttackDamage << " damage!" << endl;

			hero->setDefense(increasedDefense - 5);
			cout << hero->getName() << " increased defense has returned to its normal state of " << hero->getDefense() << endl;
			Sleep(2000);
		}

		system("cls");
	}
}
