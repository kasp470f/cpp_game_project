#include "Armor.h"

Armor::Armor(string name, int value, string slot, int defense)
	:Item(name, value)
{
	this->type = "Armor";
	this->slot = slot;
	this->defense = defense;
}

Armor::~Armor()
{
}