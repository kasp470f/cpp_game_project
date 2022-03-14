#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Item 
{
private:
	string name;
	string type;
	int value;
	void printInventory() const;

public:
	Item();
	virtual ~Item();

	inline string debugPrint() const { return this->name; }
};

