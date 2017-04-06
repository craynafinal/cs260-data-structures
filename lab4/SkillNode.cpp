/*************************************************************************************************
	// Jong Seong Lee - CS 260
	// Assignment - Lab# 4
	
	1. SkillNode is node class used by SkillTree database class.
	2. Many of annotations are omitted due to readability and cleanness of code and because they are simple.
************************************************************************************************/

#include "SkillNode.h"

SkillNode::SkillNode ()
{
	this->initChildren ();
}
SkillNode::SkillNode (const SkillNode& value)
{
	this->initChildren ();
	*this = value; // invoking operator= overloaded
}
void SkillNode::operator= (const SkillNode& value)
{
	this->setData (value.data); // only copies data, not children
}
Skill SkillNode::getData () const
{
	return this->data;
}
void SkillNode::printData (ostream& value) const
{
	this->data.Display (value); // using skill class meathod
}
void SkillNode::setData (const Skill value)
{
	this->data = value; // using skill operator= overloaded
}
void SkillNode::setData (const char* nameValue, const char* descValue, const unsigned int levelValue)
{
	this->data.setName (nameValue);
	this->data.setDesc (descValue);
	this->data.setLevel (levelValue);
}
void SkillNode::initChildren ()
{
	/*************************************************************************************************
		initChildren should only be called for constructors.
		This function is designed to set all children nullptr without checking existing values because checking uninitialized values will cause an error.
	
		1. Precondition: Must be called in constructors, not other functions
		2. Postcondition: All pointers are set to nullptrs.
	*************************************************************************************************/
	for (unsigned int i = 0; i < NUM_CHILD; i ++)
	{
		this->children [i] = nullptr;
	}
}