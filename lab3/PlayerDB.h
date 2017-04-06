#ifndef PLAYERDB_H
#define PLAYERDB_H

#include "Player.h"
#include "HashTable.h"
#include <iostream>

using namespace std;

const unsigned int SET_ARR_SIZE = 3;

class PlayerDB
{
public:
	// default constructor
	//		1. members are automatically set to default values
	//		2. ostream default value is cout
	//		3. initialization on the headers of hash table
	PlayerDB ();
	
	// copy constructor
	//		1. copies another PlayerDB object
	//		2. invokes operator =
	PlayerDB (const PlayerDB& value);

	// constructor with a parameter ostream
	//		1. same as default constructor but taking ostream variable as a parameter
	//		2. could use with fstream variable
	PlayerDB (ostream& value);

	// destructor
	//		1. destroys all hash table
	//		2. does nothing but invokes destroyHashTable function
	~PlayerDB ();

	// operator=
	//		1. copy another PlayerDB object
	//		2. copies all members
	//		3. copies all hash table elements
	void operator= (const PlayerDB& value); 

	// AddPlayer
	//		1. adds player by taking a Player object
	//		2. if a Player object is not initialized, the function does nothing
	//		3. adds a new node if successful, increases nodeCount by 1 as well
	//		4. it checks if there is any existing player that has the same name as the name of the parameter, if true, does not add a new player
	void AddPlayer (const Player& value);

	// RemovePlayer
	//		1. checks the hash table and see if there is a player name macthing the key
	//		2. parameter should be the name of a player
	//		3. if matches, remove player and decrease nodeCount by 1
	//		4. if fails, only print error message
	void RemovePlayer (const char* key);

	// PrintDiagnostics
	//		1. print all the hashtable elements, as well as the max arry size and the number of nodes in the table (nodeCount)
	void PrintDiagnostics () const;

	// FetchPlayer
	//		1. key is the name of a player that should be found
	//		2. if match is found, it returns the value as pointer to the Player object (address)
	Player* FetchPlayer (const char* key) const;

	// isTableEmpty
	//		1. it checks if a hash talbe's row is empty
	//		2. should pass index of hash table
	//		3. returns true if empty, false otherwise
	bool isTableEmpty (const unsigned int& index) const;

	// getNodeCount
	//		1. returns nodeCount, how many nodes in this hash table exist
	unsigned int getNodeCount () const;

	// destroyHashTable
	//		1. destroy all nodes in the hash table
	void destroyHashTable ();

private:
	// hashFunction
	//		1. calculates hash table index by taking string variable
	//		2. string variable should be the name of a player
	//		3. returns index in unsigned int form
	unsigned int hashFunction (const char* key) const;

	// member variables
	static const unsigned int MAX_ARR = SET_ARR_SIZE;		// max array size
	HashTable* hashArr [MAX_ARR];							// hash table, each array element also works as header
	unsigned int nodeCount;									// number of players added to the hash table
	ostream* output;										// default value is cout, also works as fstreams
};

#endif PLAYERDB_H