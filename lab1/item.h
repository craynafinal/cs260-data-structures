#ifndef ITEM_H
#define ITEM_H

// class item will provide member variables and methods to control item name and weight.

class item
{
public:
	item (const char* name, const double weight); // constructor with parameters
	item (); // default constructor
	item (const item& object); // copy constructor
	~item (); // destructor

	char* GetName () const;
	void SetName (const char* name);
	double GetWeight () const;
	void SetWeight (const double weight);
	void operator= (const item& object);
private:
	char* itemName; // the name of item in the inventory
	double itemWeight; // weight of the specific item
};

#endif ITEM_H