#include "Item.h"

Item::Item()
{
	this->name = "Sword";
	this->type = "NONE";
	this->value = 0;
}

Item::~Item()
{

}

void Item::printInventory() const
{
	cout << "=Inventory=" << endl;
	cout << "Items: " << endl;
	cout << "* " << this->name << endl;
}