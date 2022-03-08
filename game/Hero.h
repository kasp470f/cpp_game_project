#pragma once
#include <string>
#include <iostream>

class Hero
{
public:
	Hero();
	virtual ~Hero();

	//Functions
	void initialize(const std::string name);
	void printStats() const;

	//Accessors
	inline const std::string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->pcLevel; }
	inline const int& getAttack() const { return this->attack; }
	inline const int& getAttackMin() const { return this->attackMin; }
	inline const int& getAttackMax() const { return this->attackMax; }
	inline const int& getDefense() const { return this->defense; }
	inline const int& getHealth() const { return this->health; }
	inline const int& getHealthMax() const { return this->healthMax; }

private:
	//Modifiers
	std::string name;
	int pcLevel;
	int exp;
	int expNext;

	int attack;
	int attackMin;
	int attackMax;
	int defense;
	int health;
	int healthMax;

};