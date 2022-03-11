#include "Hero.h"

Hero::Hero()
{
	this->name = "";
	this->pcLevel = 1;
	this->attack = 0;
	this->attackMin = 0;
	this->attackMax = 0;
	this->defense = 0;
	this->health = 0;
	this->healthMax = 0;
	this->speed = 0;
}

Hero::~Hero()
{

}

void Hero::initialize(std::string name)
{
	this->name = name;
	this->pcLevel = pcLevel;
	this->exp = 0;
	this->expNext =
		expNext = static_cast<int>((50.0) / 3) * (pow(pcLevel, 3) -
			6 * pow(pcLevel, 2) +
			(17 * pcLevel) - 12);

	this->attackMin = 2;
	this->attackMax = 4;
	this->defense = 10;
	this->health = 10;
	this->healthMax = 10;
	this->speed = 1;
}

void Hero::printStats() const
{
	cout << "~~** YOUR HERO's STATS **~~" << endl;
	cout << "* Name: " << this->name << endl;
	cout << "* Level: " << this->pcLevel << endl;
	cout << "* Exp: " << this->exp << endl;
	cout << "* Next Level: " << this->expNext << endl;
	cout << endl;
	cout << "* Attack: " << this->attackMin << " - " << this->attackMax << endl;
	cout << "* Defense: " << this->defense << endl;
	cout << "* Health: " << this->health << " / " << this->healthMax << endl;
}

//Encounter-used functions
void Hero::printCombatStats()
{
	cout << name << endl
		<< " [ HP: " << health 
		<< " | ATK: " << attackMax 
		<< " | DEF: " << defense
		<< " | SPD: "<< speed 
		<< " ]" << endl;
}

inline bool Hero::willHit()
{
	int heroAttackChance = rand() % 100 + 1;
	if (heroAttackChance <= 75) { return true; }
	return false;
}

void Hero::heroAttack(Monster* enemy)
{
	int heroAttackDamage = (int)ceil(getAttackMax() - (enemy->getDefense() / 2));
	if (heroAttackDamage > 0 && willHit()) {
		enemy->takeDamage(heroAttackDamage);
		cout << getName() << " attacked " << enemy->getName() << " for " << heroAttackDamage << " damage!" << endl;
	}
	else {
		cout << getName() << " attacked " << enemy->getName() << " but swung too wide and missed" << endl;
	}
}
