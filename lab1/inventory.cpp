#include "inventory.h"

const double MAX_WEIGHT = 100;

inventory::inventory () // constructor
{
	maxWeight = MAX_WEIGHT;
	initialization ();	
}

inventory::inventory (const double weight) // constructor
{
	if (weight >= 0)
	{
		maxWeight = weight;
	}
	else
	{
		maxWeight = MAX_WEIGHT;
	}
	initialization ();
}

inventory::~inventory () // destructor
{
	deleteNodeType (head);
}

void inventory::initialization ()
{
	totalWeight = 0;
	totalCount = 0;
	head = nullptr;
	totalSize = 0;
}

void inventory::deleteNodeType (NodeType *curr)
{
	while (curr != nullptr)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
	
	head = nullptr;
}

void inventory::AddItem (const item value)
{
	if (totalWeight + value.GetWeight () <= maxWeight)
	{
		NodeType* newNode = new NodeType (value);
		NodeType* prev = nullptr;
		NodeType* curr = head;
	
		char* newName = value.GetName ();
		double newWeight = value.GetWeight ();

		// when there is no item in the list
		if (head == nullptr)
		{
			head = newNode;
			totalSize ++;		
		}
		else
		{
			int stringCheck;
			bool found = false;
			
			// search for the right place
			while (curr != nullptr && !found)
			{
				stringCheck = strcmp (newName, curr->data.GetName ());

				if (stringCheck <= 0)
				{
					found = true;
				}
				else
				{
					prev = curr;
					curr = curr->next;
				}
			}

			// if there is already an item with the same name
			if (stringCheck == 0)
			{
				curr->count ++;
				delete newNode;
				newNode = nullptr;
			} 
			else
			{
				if (prev == nullptr)
				{
					head = newNode;
					newNode->next = curr;
				}
				else
				{
					prev->next = newNode;
					newNode->next = curr;
				}
				totalSize ++;			
			}
		}
		totalCount ++;
		prev = nullptr;
		curr = nullptr;
		totalWeight = newWeight + totalWeight;
		cout << "You picked up a " << newName << ".\n";
	}
	else
	{
		cout << "You're not strong enough to pick up the bag of gold coins with everything else you're carrying.\n";
	}
}

void inventory::RemoveItem (const char* name)
{
	if (head == nullptr) // if the list is empty
	{
		cout << "There is no data to remove.\n\n";
	}
	else
	{
		NodeType* prev = nullptr;
		NodeType* curr = head;

		int stringCheck;
		bool found = false;
						
		while (curr != nullptr && !found) // search for the node
		{
			stringCheck = strcmp (name, curr->data.GetName ());

			if (stringCheck == 0)
			{
				found = true;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		};
	
		if (curr == nullptr) // when not found
		{
			cout << "You don't have a " << name << " in your inventory.\n";
		}
		else if (curr->count > 1) // if the item has more than qty of 2
		{
			curr->count --;
			cout << "You dropped a " << name << ".\n";
			totalWeight = totalWeight - curr->data.GetWeight ();
			totalCount --;
			totalSize --;
		}
		else
		{
			if (head == curr)
			{
				head = curr->next;
				
			}
			else // general case
			{
				prev->next = curr->next;
				
			}
			totalWeight = totalWeight - curr->data.GetWeight ();
			totalCount --;
			totalSize --;
			delete curr;
			cout << "You dropped a " << name << ".\n";
		}
		prev = nullptr;
		curr = nullptr;
	}
}

unsigned int inventory::GetCount () const
{
	return totalCount;
}

double inventory::GetWeight () const
{
	return totalWeight;
}

void inventory::PrintInventory () const
{
	cout << "\nCurrent\tinventory:\n";

	if (head == nullptr)
	{
		cout << "\t(no items)\n\n";
	} else
	{
		NodeType* curr;
		
		for (curr=head; curr!=nullptr; curr=curr->next)
		{
			cout << "\t[" << curr->count << "] " << curr->data.GetName () << "\n";
		}

		cout << "Total items: " << totalCount << "\n";
		cout << "Total weight: " << totalWeight << "\n\n";
	}
}