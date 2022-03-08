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
}

void Hero::printStats() const //Hvorfor er det vi skal have en 'const' her?
{
	std::cout << "~~** YOUR HERO's STATS **~~" << std::endl;
	std::cout << "* Name: " << this->name << std::endl;
	std::cout << "* Level: " << this->pcLevel << std::endl;
	std::cout << "* Exp: " << this->exp << std::endl;
	std::cout << "* Next Level: " << this->expNext << std::endl;
	std::cout << std::endl;
	std::cout << "* Attack: " << this->attackMin << " - " << this->attackMax << std::endl;
	std::cout << "* Defense: " << this->defense << std::endl;
	std::cout << "* Health: " << this->health << " / " << this->healthMax << std::endl;
}