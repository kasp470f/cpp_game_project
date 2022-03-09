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
	Monster(string name, int health, int attack, int defense, int speed, int exp, int gold);
	~Monster();

	void printStats();

	string getName() { return name; };
	int getHealth() { return health; };
	int getAttack() { return attack; };
	int getDefense() { return defense; };
	int getSpeed() { return speed; };
	int getExp() { return exp; };
	int getGold() { return gold; };
};