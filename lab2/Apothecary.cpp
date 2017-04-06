#include "Apothecary.h"

const unsigned int STACK_MAX = 10;
const unsigned int QUEUE_MAX = 10;

Apothecary::Apothecary ()
{
	initialize (QUEUE_MAX, STACK_MAX);
}

Apothecary::Apothecary (const unsigned int& orderLimit, const unsigned int& shelfLimit)
{
	initialize (orderLimit, shelfLimit);
}

Apothecary::Apothecary (const Apothecary& value)
{
	*this = value;
}

Apothecary::~Apothecary ()
{
	destroyQueue ();
	destroyStack ();
}

void Apothecary::destroyStack ()
{
	ShelfStack *temp = stackHeader;

	while (temp != nullptr)
	{
		stackHeader = temp->next;
		delete temp;
		temp = stackHeader;
	}

	stackHeader = nullptr;
}

void Apothecary::destroyQueue ()
{
	if (orderQueueArr)
	{
		delete [] orderQueueArr;
		orderQueueArr = nullptr;
	}
}

void Apothecary::initialize (const unsigned int& orderLimit, const unsigned int& shelfLimit)
{
	// initialize shelf part
	stackHeader = nullptr;
	stackMax = shelfLimit;
	stackLength = 0;

	// initialize queue part
	queueMax = orderLimit;
	orderQueueArr = new Potion [queueMax];
	queueLength = 0;
	queueFront = 0;
	queueBack = 0;
}

void Apothecary::operator= (const Apothecary& value)
{
	if (this != &value)
	{
		// copy member variables
		this->stackMax = value.stackMax;
		this->stackLength = value.stackLength;
		this->queueFront = value.queueFront;
		this->queueBack = value.queueBack;
		this->queueMax = value.queueMax;
		this->queueLength = value.queueLength;

		// copy queue
		this->destroyQueue ();
		this->orderQueueArr = new Potion [this->queueMax];

		unsigned int index = this->queueFront;
		bool check = false;
		
		while (!check)
		{
			this->orderQueueArr [index].setPotionType (value.orderQueueArr [index].GetType ());
			index = (index + 1) % queueMax;
			check = (index == this->queueBack);
		}

		// copy stack
		this->destroyStack ();
		ShelfStack *temp = value.stackHeader;

		while (temp != nullptr)
		{
			this->pushStack (temp->getData ());
			temp = temp->next;
		}		
	}
}

bool Apothecary::OrderPotion (const PotionType& value)
{
	bool ret = false; // determines if job was successful or not

	if (queueMax != queueLength)
	{
		orderQueueArr [queueBack].setPotionType (value);
		queueBack = (queueBack + 1) % queueMax; // mod makes queueBack 0 if it reaches the size of queueMax
		queueLength ++;
		ret = true;
	}
	return ret;
}

void Apothecary::displayQueue () const
{
	if (queueIsEmpty ())
	{
		cout << "Your queue is empty." << endl;
	}
	else
	{
		unsigned int index = queueFront; // search index
		bool check = false;
		unsigned int num = 1; // display index

		while (!check)
		{
			cout << num << ". Potion of " << PotionTypeString (orderQueueArr [index].GetType ()) << endl;
			index = (index + 1) % queueMax;
			check = (index == queueBack);
			num ++;
		}
	}
}

int Apothecary::MakePotions ()
{
	unsigned int num = 0; // determines how many potions were made
	PotionType value;
	bool check = false;
	
	while (!check && queueLength != 0)
	{
		if (queueIsEmpty ())
		{
			cout << "The order queue is empty." << endl;
			check = true;
		}
		else if (stackMax == stackLength)
		{
			cout << "The shelf of potions is full.  You can't make any more until somebody buys some." << endl;
			check = true;
		}
		else
		{
			value = orderQueueArr [queueFront].GetType();
			queueFront = (queueFront + 1) % queueMax; // mode makes queueFront 0 if it reaches the size of queueMax
			queueLength --;
			num ++;

			// save the retrived item to the stack
			pushStack (value);

			cout << "Made a " << PotionTypeString (value) << " potion." << endl;
		}
	}
	return num;
}

void Apothecary::pushStack (const PotionType& value)
{
	ShelfStack *newStack = new ShelfStack (value);
	ShelfStack *curr = stackHeader;

	newStack->next = stackHeader;
	stackHeader = newStack;

	stackLength ++;
}

bool Apothecary::BuyPotion (Potion& value)
{
	bool ret = false;
	
	if (!stackIsEmpty ())
	{
		ShelfStack *temp;

		value.setPotionType (stackHeader->getData ());
		temp = stackHeader;
		stackHeader = stackHeader->next;
		delete temp;
		stackLength --;

		ret = true;
		temp = nullptr;
	}

	return ret;	
}

bool Apothecary::queueIsEmpty () const
{
	return (getQueueLength () == 0);
}

bool Apothecary::stackIsEmpty () const
{
	return (getStackLength () == 0);
}

unsigned int Apothecary::getQueueLength () const
{
	return queueLength;
}

unsigned int Apothecary::getStackLength () const
{
	return stackLength;
}