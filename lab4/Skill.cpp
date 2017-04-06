/*************************************************************************************************
	// Jong Seong Lee - CS 260
	// Assignment - Lab# 4
	
	1. This class Skill is data class that contains detailed information about skills.
	2. Many of annotations are omitted due to readability and cleanness of code and because they are simple.
************************************************************************************************/

#include "Skill.h"

const unsigned int DEFAULT_LEVEL = 0;

Skill::Skill ():
	name (nullptr),
	desc (nullptr),
	level (DEFAULT_LEVEL)
{
}
Skill::Skill (const char* nameValue, const char* descValue, const unsigned int levelValue):
	name (nullptr),
	desc (nullptr),
	level (levelValue)
{
	setString (nameValue, this->name);
	setString (descValue, this->desc);
}
Skill::Skill (const Skill& value):
	name (nullptr),
	desc (nullptr),
	level (value.level)
{
	*this = value;
}
Skill::~Skill ()
{
	destroyString (this->name);
	destroyString (this->desc);
}
void Skill::operator= (const Skill& value)
{
	setString (value.name, this->name);
	setString (value.desc, this->desc);
	setLevel (value.level);
}
void Skill::Display (ostream& value) const
{	
	value << name << " -- " << desc << " [Lvl: " << level << "]\n"; // displays node data in required form
}
char* Skill::getName () const
{
	return this->name;
}
char* Skill::getDesc () const
{
	return this->desc;
}
unsigned int Skill::getLevel () const
{
	return this->level;
}
void Skill::setName (const char* nameValue)
{
	setString (nameValue, this->name);
}
void Skill::setDesc (const char* descValue)
{
	setString (descValue, this->desc);
}
void Skill::setLevel (const unsigned levelValue)
{
	level = levelValue;
}
void Skill::destroyString (char*& string)
{
	if (string != nullptr)
	{
		delete [] string;
		string = nullptr;
	}
}
void Skill::setString (const char* source, char*& dest)
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

bool Skill::dataValid () const
{
	return (this->name != nullptr && this->desc != nullptr); // level is always initialized by constructors
}