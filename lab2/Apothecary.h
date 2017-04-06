#ifndef APOTHECARY_H
#define APOTHECARY_H

#include "Potion.h"

class Apothecary
{
public:
	Apothecary (); // default constructor
	Apothecary (const unsigned int& orderLimit, const unsigned int& shelfLimit); // constructor with parameters, sets the limits of the queue and the stack
	Apothecary (const Apothecary& value); // copy constructor
	~Apothecary (); // destructor
		
	struct ShelfStack // stack that saves the potions made by a wizard
	{
		ShelfStack::ShelfStack (const PotionType& value) // constructor with a parameter
		{
			data.setPotionType (value);
			next = nullptr;
		}

		void ShelfStack::setData (const PotionType& value)
		{
			data.setPotionType (value);
		}

		PotionType ShelfStack::getData () const
		{
			return data.GetType ();
		}

		Potion data; // saves potion type
		ShelfStack *next; 
	};

	void initialize (const unsigned int& orderLimit, const unsigned int& shelfLimit); // initialize object
	void operator= (const Apothecary& value); // operator overloading
	bool OrderPotion (const PotionType& value); // adds an order to queue
	int MakePotions (); // makes potions that are in the order queue
	bool BuyPotion (Potion& value); // a customer takes a potion from the shelf
	bool queueIsEmpty () const; // determines whether queue is empty or not, returns true if it is empty
	bool stackIsEmpty () const; // determines whether stack is empty or not, return true if it is empty
	unsigned int getQueueLength () const; // get the current length of the queue
	unsigned int getStackLength () const; // get the current length of the stack
	void pushStack (const PotionType& value); // push an item to the stack
	void destroyStack (); // delete all nodes
	void destroyQueue (); // delete all dynamic arrays
	void displayQueue () const; // display the list of items in queue

private:
	ShelfStack *stackHeader; // pointing the top of shelfStack
	unsigned int stackMax; // capacity of stack
	unsigned int stackLength; // current length of stack

	Potion *orderQueueArr; // saves a potion order list
	unsigned int queueFront; // queue front location
	unsigned int queueBack; // queue back location
	unsigned int queueMax; // capacity of queue
	unsigned int queueLength; // current length of queue
};

#endif APOTHECARY_H