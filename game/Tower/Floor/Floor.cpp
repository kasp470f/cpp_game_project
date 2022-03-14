#include "Floor.h"

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

//Instantiates a new floor
Floor::Floor(Hero& hero, int floorLevel)
{
	this->hero = &hero;
	this->enemy = new Monster();

	this->floorLevel = floorLevel;

	encounter();
}

//Floor destructor
Floor::~Floor(){ }


#pragma region DontMove_Monster
// If Attack and Willhit from enemy is changed to be from the Monster class. It doesn't compile. Because of a LNK2019 error which I can't solve.
bool Floor::willEnemyHit()
{
	int enemyAttackChance = rand() % 100 + 1;
	if (enemyAttackChance <= 60) { return true; }
	return false;
}

void Floor::enemyAttack() {
	int enemyAttackDamage = (int)ceil(enemy->getAttack() + 1 - (hero->getDefense() / 2));
	if (enemyAttackDamage > 0 && willEnemyHit()) {
		hero->setHealth(hero->getHealth() - enemyAttackDamage);
		cout << enemy->getName() << " attacked " << hero->getName() << " for " << enemyAttackDamage << " damage!" << endl;
	}
	else {
		cout << enemy->getName() << " attacked " << hero->getName() << " but swung too wide and missed" << endl;
	}
}
#pragma endregion


void Floor::encounter()
{
	system("cls");
	while (hero->getHealth() >= 1 && enemy->getHealth() >= 1)
	{
		int selectedAction = actionSelection();

		// Attack !THIS NEEDS TO BE MADE MORE EFFICIENT!
		if (selectedAction == 0) {
			//highest attackspeed hits first
			if (hero->getSpeed() > enemy->getSpeed()) {
				hero->heroAttack(enemy);
				enemyAttack();
			}
			else {
				enemyAttack();
				hero->heroAttack(enemy);
			}
			Sleep(3000);
		}
		//Take def potion
		else if (selectedAction == 1) {
			int increasedDefense = hero->getDefense() + 5;
			hero->setDefense(increasedDefense);
			cout << hero->getName() << " increased his defense by 5, bringing it up to " << increasedDefense << endl;
			enemyAttack();

			hero->setDefense(increasedDefense - 5);
			cout << hero->getName() << "'s increased defense has returned to its normal state of " << hero->getDefense() << endl;
			Sleep(3000);
		}
		else if (selectedAction == 2) {
			system("cls");
			openInventory();
			Sleep(1000);
		}
		else if (selectedAction == 3) {
			system("cls");
			flee();
			Sleep(1000);
		}

		system("cls");
	};
	if (hero->getHealth() <= 0) {
		cout << "Your epic adventure has ended!" << endl;
		cout << "---------------- GAME OVER! ----------------" << endl;
		Sleep(2000);
	}
	if (enemy->getHealth() <= 0)
	{
		cout << enemy->getName() << " has died!" << endl;
		Sleep(2000);
	}
}

int Floor::actionSelection()
{
	int selectedAction = 0;
	bool checkingAction = true;
	while (checkingAction)
	{
		cout << "Floor " << getFloorLevel() << endl;
		cout << "------------------------------" << endl;
		enemy->printCombatStats();
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
		case KEY_ENTER:
			checkingAction = false;
			break;
		}

		system("cls");
	};

	return selectedAction;
}

void Floor::flee()
{
	cout << "-------- You flee... --------" << endl;
	cout << "(impementation in progress)" << endl;
}

void Floor::openInventory()
{
	cout << endl << "-------- You open your inventory... --------" << endl;
	cout << "(impementation in progress)" << endl;
}