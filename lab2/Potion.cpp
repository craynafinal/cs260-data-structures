#include "Potion.h"

Potion::Potion ()
{
	data = UNKNOWN;
}

Potion::Potion (const PotionType& value)
{
	data = value;
}

Potion::Potion (const Potion& value)
{
	*this = value;
}

void Potion::operator= (const Potion& value)
{
	if (this != &value)
	{
		data = value.data;
	}
}

ostream& operator<< (ostream& osObject, const Potion& value)
{
	osObject << "Potion of " << PotionTypeString (value.data) << endl;
	return osObject;
}

PotionType Potion::GetType () const
{
	return data;
}

bool Potion::setPotionType (const PotionType& value)
{
	data = value;
	return true;
}