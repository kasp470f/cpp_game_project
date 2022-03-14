#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Item 
{
	string name;
	int value;
public:
	Item(string name, int value);
	virtual ~Item();

	string type;
	string getName() { return this->name; }
	int getValue() { return this->value; }

	virtual Item* clone() const = 0;
	
	virtual void debugPrint() const { 
		cout << "[Name: " << this->name << " Value: " << this->value 
			<< "]" << endl; 
	}
};

