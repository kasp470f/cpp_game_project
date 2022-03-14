#include "Weapon.h"

Weapon::Weapon(string name, int value, int attackMin, int attackMax)
	:Item(name, value)
{
	this->type = "Weapon";
	this->attackMin = attackMin;
	this->attackMax = attackMax;
}

Weapon::~Weapon()
{
}