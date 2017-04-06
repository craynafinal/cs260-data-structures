#ifndef POTION_H
#define POTION_H

#include <iostream>
#include "main.h"

using namespace std;

class Potion
{
	friend ostream& operator<< (ostream& osObject, const Potion&);

public:
	Potion (); // default constructor
	Potion (const PotionType& value); // constructor with parameter
	Potion (const Potion& value); // copy constructor
		
	void operator= (const Potion& value); // operator overloading
	PotionType GetType () const;
	bool setPotionType (const PotionType& value);

private:
	PotionType data;
};

#endif POTION_H