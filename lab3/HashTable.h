#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Player.h"

class HashTable
{
public:
	// default constructor
	//		1. only sets member next
	//		2. let the member data initialized by constructor in Player class
	HashTable ();

	// copy constructor
	//		1. sets member next as well as memberdata
	//		2. invoke operator = to initialize
	HashTable (const HashTable& value);

	// destructor
	~HashTable ();

	// operator=
	//		1. if the parameter and this object are not the same, this object copies member data from the parameter
	//		2. let the copy constructor of Player class handle it
	void operator= (const HashTable& value);

	// setData
	//		1. copies the member data from the parameter, let the copy constructor of Player class handle it
	void setData (const Player& value);

	// getData
	//		1. returns member data
	Player getData () const;
	
private:
	// members
	Player data;			// player data, refer Player class for more information
	HashTable* next;		// next pointer

	friend class PlayerDB;
};

#endif HASHTABLE_H