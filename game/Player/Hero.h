#pragma once

#include "../Inventory.h"
#include "../Weapon.h"

class Hero
{
public:
	Hero();
	virtual ~Hero();

	//Functions
	void initialize(const string name);
	void printStats() const;

	//Accessors
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->pcLevel; }
	inline const int& getAttack() const { return this->attack; }
	inline const int& getAttackMin() const { return this->attackMin; }
	inline const int& getAttackMax() const { return this->attackMax; }
	inline const int& getDefense() const { return this->defense; }
	inline const int& getHealth() const { return this->health; }
	inline const int& getHealthMax() const { return this->healthMax; }
	inline const int& getSpeed() const { return this->speed; }

	//Encounter-used functions
	void printCombatStats();
	inline void takeDamage(int damage) { health -= damage; }
	inline void setDefense(int defense) { this->defense = defense; }

private:
	Inventory inventory;
	//Armor armor;
	//Modifiers
	string name;
	int pcLevel;
	int exp;
	double expNext;

	int attack;
	int attackMin;
	int attackMax;
	int defense;
	int health;
	int healthMax;
	int speed;
};