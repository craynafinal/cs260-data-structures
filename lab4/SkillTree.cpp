/*************************************************************************************************
	// Jong Seong Lee - CS 260
	// Assignment - Lab# 4
	
	1. SkillTree class is used to manipulate Skill nodes with general tree structure.
************************************************************************************************/

#include "SkillTree.h"

SkillTree::SkillTree ():
	title (nullptr),
	root (nullptr)
{
	// default constructor
}
SkillTree::SkillTree (const char* titleValue):
	title (nullptr),
	root (nullptr)
{
	// constructor
	setTitle (titleValue);
}
SkillTree::SkillTree (const char* titleValue, const SkillNode* rootValue):
	title (nullptr),
	root (nullptr)
{
	// constructor
	setTitle (titleValue);
}
SkillTree::SkillTree (const SkillTree& value):
	title (nullptr),
	root (nullptr)
{
	// copy constructor
	*this = value;
}
SkillTree::~SkillTree ()
{
	// destructor
	destroyString (title);
	destroyNodes ();
}
unsigned int SkillTree::numOfChildren (const SkillNode* nodeValue) const
{
	/*************************************************************************************************
		This function is going to check how many children linked to nodeValue.
		Returns 0 if there is no child linked; otherwise, returns the number of children in unsigned int form.

		1. Precondition: None
		2. Postcondition: None
	*************************************************************************************************/
	
	unsigned int ret = 0;
	bool found = false;
	unsigned int i = 0;

	while (!found && i < NUM_CHILD)
	{
		if (nodeValue->children [i] != nullptr) 
		{
			ret ++;
		}
		else
		{
			found = true;
		}
		i ++;
	}
	
	return ret;
}
void SkillTree::operator= (const SkillTree& value)
{
	// operator overloading
	setTitle (value.title);
	AddSkill (value.root->data.getName (), value.root->data.getDesc (), value.root->data.getLevel ());
	copyTree (value.root);	
}
void SkillTree::copyTree (SkillNode* rootValue)
{
	/*************************************************************************************************
		Basically copyTree is the same as preorderTraverse, but different parameter set and function for copying tree from another object.

		1. Precondition: None
		2. Postcondition: None
	*************************************************************************************************/
	unsigned int numChild = numOfChildren (rootValue); // get how many children exist

	for (unsigned int i = 0; i < numChild; i++)
	{
		
		if (rootValue->children [i] != nullptr)
		{
			AddSkill (rootValue->children [i]->data.getName (), rootValue->children [i]->data.getDesc (),rootValue->children [i]->data.getLevel (), rootValue->data.getName ());
			copyTree (rootValue->children [i]);	// and do recursion call
		}
	}
}
bool SkillTree::isTreeEmpty () const
{
	/*************************************************************************************************
		isTreeEmpty will check if tree is empty. Returns true if empty, false otherwise.

		1. Precondition: None
		2. Postcondition: None
	*************************************************************************************************/
	return root == nullptr;
}
void SkillTree::AddSkill (const char* nameValue, const char* descValue, const unsigned int levelValue)
{
	/*************************************************************************************************
		This AddSkill will create a tree by adding a root node or will make a new root and link an old root as a child.

		1. Precondition: None
		2. Postcondition: A tree created or tree height increased by 1.
	*************************************************************************************************/
			
	if (isTreeEmpty ()) // if tree is empty
	{
		Skill temp (nameValue, descValue, levelValue);
		SkillNode* newNode = new SkillNode;
		newNode->setData (temp);
		
		root = newNode;
	}
	else // if there is already root exists
	{
		Skill temp (nameValue, descValue, levelValue);
		SkillNode* newNode = new SkillNode;
		newNode->setData (temp);
		newNode->children [0] = root;
		root = newNode;
	}
}
void SkillTree::AddSkill (const char* nameValue, const char* descValue, const unsigned int levelValue, const char* parentNameValue)
{
	/*************************************************************************************************
		This AddSkill will add a new node or data that are not root. This function does not check data to find a position to put it.
		Only checks if there is appropriate parent node and insert a new node if there is free space to add a new child. Otherwise, this function will do nothing.

		1. Precondition: None
		2. Postcondition: None
	*************************************************************************************************/
		
	SkillNode* parent = locateNode (root, parentNameValue); // returns node, nullptr if not found
	
	if (parent != nullptr) // if match was found
	{
			unsigned int numChild = numOfChildren (parent);
		if (numChild < NUM_CHILD) // if there is still free space for a child left
		{
			Skill temp (nameValue, descValue, levelValue);
			SkillNode* newNode = new SkillNode;
			newNode->setData (temp);
			parent->children [numChild] = newNode;
		}
	}
}
Skill* SkillTree::FindSkill (const char* name) const // let's add imp later
{
	/*************************************************************************************************
		Simply finds a node and returns its data as pointer variable.

		1. Precondition: None
		2. Postcondition: None
	*************************************************************************************************/
	Skill* ret = nullptr;
	
	SkillNode* temp = locateNode (root, name);

	ret = &temp->data;

	return ret;
}
void SkillTree::Display (ostream& value) const
{
	/*************************************************************************************************
		Display will print all data in a tree in preorder. This function will take ostream value as a parameter for better control in the future.
		This function will print root, but will let preorderTraverse do the rest of work.

		1. Precondition: None
		2. Postcondition: None
	*************************************************************************************************/
	cout << "Skill Tree: " << title << "\n";

	if (isTreeEmpty ())
	{
		cout << "  Empty\n";
	}
	else
	{
		cout << "  - ";
		root->printData (value); // print the root first
		preorderTraverse (value, root, 1);
	} // end if
}
char* SkillTree::getTitle () const
{
	return title;
}
void SkillTree::setTitle (const char* titleValue)
{
	setString (titleValue, title);
}
void SkillTree::destroyString (char*& dest)
{
	if (this->title != nullptr)
	{
		delete [] dest;
	} // end if
}
void SkillTree::preorderTraverse (ostream& value, const SkillNode* rootValue, const unsigned int height) const
{
	/*************************************************************************************************
		This function is designed to go through everynode in a tree and print their data except a root node. The parameter height is for output styling.

		1. Precondition: Should pass root for the first time when calling this function.
		2. Postcondition: None
	*************************************************************************************************/
	unsigned int numChild = numOfChildren (rootValue); // get how many children exist
		
	for (unsigned int i = 0; i < numChild; i++)
	{
		
		if (rootValue->children [i] != nullptr)
		{
			for (unsigned int coutIndex = 0; coutIndex <= height; coutIndex ++)
			{
				cout << "  ";
			}
			cout << "- ";
			rootValue->children [i]->printData (value); // print first
			
			preorderTraverse (value, rootValue->children [i], height + 1);	// and do recursion call
		}
	}
}
void SkillTree::setString (const char* source, char*& dest)
{
	if (source != nullptr) // check if nameValue does exists
	{
		destroyString (dest);
		unsigned int length = strlen (source) + 1; // +1 to include \0 value

		// let's check if length is over 0

		dest = new char [length]; // allocates memory
		strncpy (dest, source, length);
	}
	else
	{
		dest = nullptr;
	}
}
void SkillTree::destroyNodes ()
{
	inorderTraverse (root);
	delete root;
}

void SkillTree::inorderTraverse (SkillNode* rootValue)
{
	/*************************************************************************************************
		inorderTraverse is going to visit all the nodes in a tree and will delete everything to prevent memeory leak. 

		1. Precondition: Should pass root for the first time when calling this function.
		2. Postcondition: None
	*************************************************************************************************/
	unsigned int numChild = numOfChildren (rootValue); // get how many children exist
		
	for (unsigned int i = 0; i < numChild; i++)
	{
		if (rootValue->children [i] != nullptr)
		{
			inorderTraverse (rootValue->children [i]);	// and do recursion call
			delete rootValue->children [i];
		}
	}
}

SkillNode* SkillTree::locateNode (SkillNode* start, const char* searchKey) const
{
	/*************************************************************************************************
		Returns the node location that matches the search key with its data.

		1. Precondition: None
		2. Postcondition: This function will return nullptr if nothing found.
	*************************************************************************************************/
	
	SkillNode* ret = nullptr;

	bool found = false;
	
	if (start->data.dataValid ()) 
	{
		if (strcmp (searchKey, start->data.getName ()) == 0) // if name matches the search key
		{
			
			ret = start;
		}
		else // if not found, keep searching for it
		{
		
			unsigned int numChild = numOfChildren (start);
			if (numChild > 0) // if this is not a leaf
			{
			
				bool childFound = false;
				unsigned int i = 0;
				while (!childFound && i < numChild)
				{
				
					ret = locateNode (start->children [i], searchKey);
					if (ret != nullptr)
					{
						childFound = true;
					}
					else
					{
						i ++;
					}
				}
			}
		}
	} // end if
		
	return ret; // if !found, this will return nullptr
}