#include "PlayerDB.h"

PlayerDB::PlayerDB () : 
	nodeCount (0),
	output (&cout)
{
	for (int i = 0; i < MAX_ARR; i++)
	{
		hashArr [i] = nullptr;
	}
}

PlayerDB::PlayerDB (const PlayerDB& value) :
	output (&cout)
{
	*this = value;
}

PlayerDB::PlayerDB (ostream& value) :
	nodeCount (0),
	output (&value)
{
	for (int i = 0; i < MAX_ARR; i++)
	{
		hashArr [i] = nullptr;
	}
}

PlayerDB::~PlayerDB ()
{
	destroyHashTable ();
}

void PlayerDB::operator= (const PlayerDB& value)
{
	if (this != &value)
	{
		this->output = value.output;
		this->nodeCount = value.nodeCount;

		destroyHashTable ();
		
		for (unsigned int index = 0; index < MAX_ARR; index++)
		{
			if (!value.isTableEmpty (index)) // if the header is not null
			{
				HashTable* temp = value.hashArr [index];
				cout << temp->data.getName ();
				HashTable* newNode = new HashTable (*temp);
				this->hashArr [index] = newNode;
				HashTable* prev = newNode;
				temp = temp->next;
				
				while (temp != nullptr)
				{
					HashTable* newNode = new HashTable (*temp);
					cout << temp->data.getName ();
					prev->next = newNode;
					prev = newNode;
					temp = temp->next;
				}
				
			}
			else // if the linked list is empty
			{
				this->hashArr [index] = nullptr;
			}cout << "done" << endl;
		}
	}
}

void PlayerDB::destroyHashTable ()
{
	for (unsigned int index = 0; index < MAX_ARR; index ++)
	{
		HashTable* temp = hashArr [index];

		while (temp != nullptr)
		{
			hashArr [index] = temp->next;
			delete temp;
			temp = hashArr [index];
		}
		
		temp = nullptr;
	}
}

void PlayerDB::AddPlayer (const Player& value)
{//value.getName () != nullptr
	
	if (!value.isInitialized()) // prevent getting error
	{
		*output << "Attempting to add player \"" << value.getName () << "\" to the database -- ";
	
		unsigned int arrLoc = hashFunction (value.getName ()); // get index from hash function
		HashTable* temp = hashArr [arrLoc]; // define a temp pointer to the head
		bool found = false; // variable sets true if there is already same player name
		
		while (!found && temp != nullptr)
		{
			if (strcmp (temp->data.getName (), value.getName ()) == 0)
			{
				found = true;
			}
		
			temp = temp->next;
		}
	
		if (!found)
		{
			
			HashTable* newNode;
			newNode = new HashTable;
					
			newNode->setData (value); // player default constructor invoked here

			newNode->next = hashArr [arrLoc];
			hashArr [arrLoc] = newNode;
		
			*output << "Success!\n";
			nodeCount ++; // increase the entry of a player
		}
		else
		{
			*output << "Failed.\n";
		}
	}
}

void PlayerDB::RemovePlayer (const char* key)
{
	*output << "Removing player \"" << key << "\" from the database -- ";

	unsigned int arrLoc = hashFunction (key);
	HashTable* temp = hashArr [arrLoc];
	HashTable* prev = nullptr;
	bool found = false;
	bool isOnlyNode = (temp->next == nullptr);
	
	while (!found && temp != nullptr)
	{
		if (strcmp (temp->data.getName (), key) == 0) // if key is matching
		{
			if (hashArr [arrLoc] == temp) // when node is in the first location
			{
				hashArr [arrLoc] = temp->next;
				delete temp;
				found = true;
			}
			else // if node is in the middle of list
			{
				prev->next = temp->next;
				delete temp;
				found = true;
			}
		}
		else // when key is not matching
		{	
			prev = temp;
			temp = temp->next;
		}
	}

	// print the result
	if (found)
	{
		*output << "Success!\n";
		nodeCount --;
		if (isOnlyNode)
		{
			hashArr [arrLoc] = nullptr;
		}
	}
	else
	{
		*output << "Failed.\n";
	}
	
	temp = nullptr;
	prev = nullptr;
}

void PlayerDB::PrintDiagnostics () const
{
	*output << "====================\n" << "Hash Table Diagnostics\n\n" << "Table Size: " << MAX_ARR << "\nNumber of Entries: " << getNodeCount () << endl;
	
	for (unsigned int index = 0; index < MAX_ARR; index ++)
	{
		*output << "Slot[" << index << "]:\n";
		
		if (hashArr [index] == nullptr) // check if array is empty
		{
			*output << "  EMPTY\n";
		}
		else // performs work if array is not empty
		{
			HashTable* temp = hashArr [index];
			
			while (temp != nullptr) // print the nodes until temp reaches the end of list
			{
				*output << "  " << temp->data.getName () << "[" << temp->data.getLevel () << "]\n";
				temp = temp->next;
			}
		}
	}
	
	*output << "====================\n";
}

Player* PlayerDB::FetchPlayer (const char* key) const
{
	*output << "Fetching player \"" << key << "\" -- ";
	
	Player* pointer = nullptr;
	unsigned int index = hashFunction (key);
	bool found = false;
	
	if (!isTableEmpty (index))
	{
		HashTable* temp = hashArr [index];
		while (!found && temp != nullptr)
		{
			if (strcmp (temp->data.getName (), key) == 0) // if key is matching
			{
				pointer = &temp->data;
				found = true;
			}
				temp = temp->next;			
		}
	}
	
	if (found)
	{
		*output << "Success!\n";
	}
	else
	{
		*output << "Failed.\n";
	}
	
	return pointer;
}

bool PlayerDB::isTableEmpty (const unsigned int& index) const
{
	bool isEmpty = false; // assume when table not empty is major case

	if (hashArr [index] == nullptr)
	{
		isEmpty = true;
	}
	
	return isEmpty;
}

unsigned int PlayerDB::getNodeCount () const
{
	return nodeCount;
}

unsigned int PlayerDB::hashFunction (const char* key) const
{
	unsigned int size = strlen (key);
	unsigned int sum = key [0];

	for (unsigned int index = 1; index < size; index ++)
	{
		sum = sum * 32 + key [index]; // using honer's rule
	}

	return sum % MAX_ARR; // works with long strings
}