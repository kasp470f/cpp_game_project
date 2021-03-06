#include "Monster.h"

Monster::Monster()
{
    this->name = "Goblin";
    this->health = 10;
    this->attack = 5;
    this->defense = 5;
    this->speed = 2;
    this->exp = 5;
    this->gold = 5;
}

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

Monster::~Monster() 
{

}

void Monster::genMonster(int difficulty)
{

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

//Encounter-used function
void Monster::printCombatStats()
{
    cout << name << endl
        << " [ HP: " << health
        << " | ATK: " << attack
        << " | DEF: " << defense
        << " | SPD: " << speed
        << " ]" << endl;
}
