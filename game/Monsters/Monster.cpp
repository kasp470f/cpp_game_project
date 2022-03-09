#include "Monster.h"

Monster::Monster(string name, int health, int attack, int defense, int speed, int exp, int gold)
{
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
    this->exp = exp;
    this->gold = gold;
}

Monster::~Monster() {

}

void Monster::printStats() {
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Speed: " << speed << endl;
    cout << "Exp: " << exp << endl;
    cout << "Gold: " << gold << endl;
}
