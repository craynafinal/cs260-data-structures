#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "item.h"

using namespace std;

class inventory
{
public:
	inventory (); // default constructor
	inventory (double weight); // constructor with a parameter
	~inventory (); // deconstructor

	// AddItem will add a new item to the inventory
	// precondition: a parameter of type item must be provided
	void AddItem (const item value);

	// RemoveItem will remove a node in the inventory that has the same name as the one provided
	// precondition: a name of an item should be provided
	void RemoveItem (const char *name);

	// PrintInventory will print all information saved in linked list
	void PrintInventory () const;

private:

	// NodeType is the data type used to save node information
	struct NodeType
	{
		NodeType (const item& value) // constructor with parameter
		{
			//data.SetName (value.GetName ());
			//data.SetWeight (value.GetWeight ());

			// need to make it like this
			data = value;
			
			next = nullptr;
			count = 1;
			
		}
		
		item data;
		unsigned int count; // qty of an item
		NodeType *next;
	};

	NodeType *head;

	unsigned int GetCount () const;
	double GetWeight () const;
	void initialization (); // used as constructor
	void deleteNodeType (NodeType *curr); // used as destructor
	

	double maxWeight; // the max weight capacity
	double totalWeight; // current weight value
	unsigned int totalCount; // total number of items
	unsigned int totalSize; // total size of linked list
};

#endif INVENTORY_H