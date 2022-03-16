#include "Inventory.h"

Inventory::Inventory()
{
	this->cap = 10;
	this->nrOfItems = 0;
	this->itemArr = new Item * [cap];
	this->initialize();

}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
}

Inventory::Inventory(const Inventory& obj)
{
	this->cap = obj.cap;
	this->nrOfItems = obj.nrOfItems;
	this->itemArr = new Item * [this->cap];

	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	initialize(this->nrOfItems);
}

Item& Inventory::operator[](const int index)
{
	if (index < 0 || index >= this->nrOfItems)
		throw("BAD INDEX!");
	return *this->itemArr[index];
}

void Inventory::expand()
{
	//increase array's itemcap times 2
	this->cap *= 2;

	//make a temp array of the new size
	Item** tempArr = new Item * [this->cap];

	//copy all items to the temp array
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}

	//delete the old array instance
	delete[] this->itemArr;

	//set the position of old array in memory to be the temp array
	this->itemArr = tempArr;

	//add nullpointers to every index in the new array
	this->initialize(this->nrOfItems);
}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < cap; i++)
	{
		itemArr[i] = nullptr;
	}
}

void Inventory::addItem(const Item& item)
{
	if (this->nrOfItems >= this->cap)
	{
		expand();
	}
	this->itemArr[this->nrOfItems++] = item.clone();	//Changed
}

void Inventory::removeItem(int index)
{

}

void Inventory::printInventory() const
{
	cout << "==== Inventory ====" << endl;
	cout << "Items: " << endl;

	for (int i = 0; i < nrOfItems; i++)
	{
		cout << "*" << i + 1 << ": ";
		if (itemArr[i]->type == "Weapon")
		{
			((Weapon*)itemArr[i])->debugPrint();
		}
		else if (itemArr[i]->type == "Armor")
		{
			((Armor*)itemArr[i])->debugPrint();
		}
		else
		{
			itemArr[i]->debugPrint();
		}
	}
}