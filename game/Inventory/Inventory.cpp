#include "Inventory.h"

Inventory::Inventory()
{
	this->cap = 10;
	this->nrOfItems = 0;
	this->itemArr = new Item * [cap];
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
}

void Inventory::expand()
{
	this->cap *= 2;

	Item** tempArr = new Item * [this->cap];

	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		tempArr[i] = new Item(*this->itemArr[i]);
	}

	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;

	this->itemArr = tempArr;

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

	this->itemArr[this->nrOfItems++] = new Item(item);
}

void Inventory::removeItem(int index)
{

}