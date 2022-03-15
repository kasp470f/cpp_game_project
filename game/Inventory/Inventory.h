#pragma once

#include "Type/Weapon.h"
#include "Type/Armor.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Inventory
{
private:
	int cap;
	int nrOfItems;
	//pointer-pointer
	Item** itemArr;
	void expand();
	void initialize(const int from = 0);


public:
	Inventory();
	~Inventory();
	Inventory(const Inventory& obj);
	inline int size() const { return this->nrOfItems; }
	Item& operator [] (const int index);
	//const bruges ved deklaration af en pointer (da positionen i hukommelsen er/skal vaere konstant).
	void addItem(const Item& item);
	void removeItem(int index);
	void printInventory() const;
};
