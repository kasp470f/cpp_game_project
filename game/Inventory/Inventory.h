#pragma once
#include "Item.h"

class Inventory
{
private:
	int cap;
	int nrOfItems;
	//pointer-pointer
	Item** itemArr;
	void expand();
	void initialize(const int from);

public:
	Inventory();
	~Inventory();
	//const bruges ved deklaration af en pointer (da positionen i hukommelsen er/skal være konstant).
	void addItem(const Item& item);
	void removeItem(int index);
	inline void debugPrint() const
	{
		for (size_t i = 0; i < this->nrOfItems; i++)
		{
			std::cout << this->itemArr[i]->debugPrint() << std:: endl;
		}
	}
};

