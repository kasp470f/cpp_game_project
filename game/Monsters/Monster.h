#pragma once
#include <iostream>
#include <string>
using namespace std;

class Monster
{
private:
	string name;
	int health;
	int attack;
	int defense;
	int speed;
	int exp;
	int gold;

public:
	Monster();
	Monster(string name, int health, int attack, int defense, int speed, int exp, int gold);
	~Monster();

	void genMonster(int difficulty);
	void printStats();

	inline const string& getName() const { return name; };
	inline const int& getHealth() const { return health; };
	inline const int& getAttack() const { return attack; };
	inline const int& getDefense() const { return defense; };
	inline const int& getSpeed() const { return speed; };
	inline const int& getExp() const { return exp; };
	inline const int& getGold() const { return gold; };

	//Encounter-used functions
	void printCombatStats();
	inline void takeDamage(int damage) { health -= damage; }
};