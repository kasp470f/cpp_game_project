#pragma once
#include "../Item.h"

class Weapon :
	public Item
{
private:
	int attackMin;
	int attackMax;
public:
	Weapon(string name, int value, int attackMin, int attackMax);
	virtual ~Weapon();

	inline Weapon* clone() const { return new Weapon(*this); }

	void printItem() {
		cout << this->getName() << " [Damage: " << this->attackMin << " - "
			<< this->attackMax << " | Value: " << this->getValue() << "g]"
			<< endl;
	}
};
