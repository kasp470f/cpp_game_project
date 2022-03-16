#pragma once
#include "../Item.h"

class Armor :
	public Item
{
private:
	int defense;
	string slot;
public:
	Armor(string name, int value, string slot, int defense);
	virtual ~Armor();

	inline Armor* clone() const { return new Armor(*this); }

	void debugPrint() {
		cout << this->getName()
			<< " [Slot: " << this->slot
			<< " | Defense: " << this->defense
			<< " | Value: " << this->getValue() << "g]"
			<< endl;
	}
};
