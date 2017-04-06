#include <iostream>
#include "item.h"

using namespace std;

item::item (const char* name, const double weight) // constructor with parameters
{
	SetName (name);
	SetWeight (weight);
}

item::item () // default constructor
{
	itemName = "null";
	itemWeight = 0;
}

item::item (const item& object) // copy constructor
{
	*this = object;
}

void item::operator= (const item& object) // operator overloading
{
	if (this == &object)
	{
	}
	else
	{
		SetName (object.GetName ());
		SetWeight (object.GetWeight ());
	}
}

item::~item () // destructor
{
	if (itemName)
	{
		delete [] itemName;
	}
}

char* item::GetName () const
{
	return itemName;
}

void item::SetName (const char* name)
{
	unsigned int length = strlen (name) + 1; 
	itemName = new char [length];
	strncpy (itemName, name, length);
	
}

double item::GetWeight () const
{
	return itemWeight;
}

void item::SetWeight (const double weight)
{
	itemWeight = weight;
}