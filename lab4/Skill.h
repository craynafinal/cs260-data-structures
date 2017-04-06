#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <fstream>

using namespace std;

class Skill
{
public:
	Skill ();
	Skill (const char* nameValue, const char* descValue, const unsigned int levelValue);
	Skill (const Skill& value);
	~Skill ();
	void operator= (const Skill& value);
	void Display (ostream& value) const;
	char* getName () const;
	char* getDesc () const;
	unsigned int getLevel () const;
	void setName (const char* nameValue);
	void setDesc (const char* descValue);
	void setLevel (const unsigned levelValue);
	bool dataValid () const;

private:
	void setString (const char* source, char*& dest);
	void destroyString (char*& string);

	char* name;
	char* desc;
	unsigned int level;
};

#endif SKILL_H