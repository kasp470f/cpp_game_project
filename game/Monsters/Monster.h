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

	inline string getName() { return name; };
	inline int getHealth() { return health; };
	inline int getAttack() { return attack; };
	inline int getDefense() { return defense; };
	inline int getSpeed() { return speed; };
	inline int getExp() { return exp; };
	inline int getGold() { return gold; };

	//Encounter-used functions
	void setHealth(int health);
	void printCombatStats();
};