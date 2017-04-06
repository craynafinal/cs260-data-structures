#ifndef SKILLNODE_H
#define SKILLNODE_H

#include "Skill.h"

const unsigned int NUMBER_OF_CHILD = 3;

class SkillNode
{
public:
	SkillNode ();
	SkillNode (const SkillNode& value);
	void operator= (const SkillNode& value);
	Skill getData () const;
	void setData (const Skill value);
	void setData (const char* nameValue, const char* descValue, const unsigned int levelValue);
	void printData (ostream& value) const;
	
private:
	void initChildren ();
	void copyData (const Skill dataArr []);

	static const unsigned int NUM_CHILD = NUMBER_OF_CHILD;
	
	Skill data;
	SkillNode* children [NUM_CHILD];
		
	friend class SkillTree;
};

#endif SKILLNODE_H