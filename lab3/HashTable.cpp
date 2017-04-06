#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable () :
	next (nullptr)
{
}

HashTable::HashTable (const HashTable& value) :
	next (nullptr)
{
	*this = value;
}

HashTable::~HashTable ()
{
	next = nullptr;
}

void HashTable::operator= (const HashTable& value)
{
	if (this != &value)
	{
		this->data = value.data; // does not copy variable next
	}
}

void HashTable::setData (const Player& value)
{
	this->data = value; // invoking = operator in Player class
}

Player HashTable::getData () const
{
	return data;
}