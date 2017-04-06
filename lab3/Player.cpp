#include "Player.h"
#include <iostream>
using namespace std;

Player::Player () :
	name (nullptr),
	gender (UNKOWN),
	level (INITIAL_LEVEL)
{
}

Player::Player (const char* nameValue, const PlayerGender genderValue, const unsigned int levelValue) :
	name (nullptr),
	gender (genderValue),
	level (levelValue)
{
	setName (nameValue);
}

Player::Player (const char* nameValue, const PlayerGender genderValue) :
	name (nullptr),
	gender (genderValue),
	level (INITIAL_LEVEL)
{
	setName (nameValue);
}

Player::Player (const Player& value)
{
	*this = value;
}

Player::~Player ()
{
	destroyName ();
}

void Player::destroyName ()
{
	if (name != nullptr)
	{
		delete [] name;	
	}
}

void Player::operator= (const Player& value)
{
	if (this != &value) // should compare address
	{
		setName (value.getName ());
		setGender (value.getGender ());
		setLevel (value.getLevel ());
	}
}
	
char* Player::getName () const
{
	return name;
}

void Player::setName (const char* nameValue)
{
	if (nameValue != nullptr)
	{
		destroyName ();
		unsigned int length = strlen (nameValue) + 1;
		name = new char [length];
		strncpy (name, nameValue, length);
	}
	else
	{
		name = nullptr;
	}
}

PlayerGender Player::getGender () const
{
	return gender;
}

void Player::setGender (const PlayerGender genderValue)
{
	if (genderValue)
	{
		gender = genderValue;
	}
}

unsigned int Player::getLevel () const
{
	return level;
}

void Player::setLevel (const unsigned int levelValue)
{
	if (level)
	{
		level = levelValue;
	}
}

void Player::LevelUp ()
{
	level ++;
}

bool Player::isInitialized () const
{
	bool check = false;

	if (getName () != nullptr && getGender () && getLevel ())
	{
		check = true;
	}

	return check;
}
