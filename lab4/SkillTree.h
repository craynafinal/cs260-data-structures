#ifndef SKILLTREE_H
#define SKILLTREE_H

#include "SkillNode.h"

class SkillTree
{
public:
	SkillTree ();
	SkillTree (const char* titleValue);
	SkillTree (const char* titleValue, const SkillNode* rootValue);
	SkillTree (const SkillTree& value);
	~SkillTree ();
	void operator= (const SkillTree& value);
	void AddSkill (const char* nameValue, const char* descValue, const unsigned int levelValue); // add a root
	void AddSkill (const char* nameValue, const char* descValue, const unsigned int levelValue, const char* parentNameValue); // add a node that is not a root
	Skill* FindSkill (const char* name) const;
	void Display (ostream& value) const;
	char* getTitle () const;
	void setTitle (const char* titleValue);
	bool isTreeEmpty () const;
	
private:
	void destroyString (char*& string);
	unsigned int numOfChildren (const SkillNode* nodeValue) const;
	void setString (const char* source, char*& dest);
	void destroyNodes ();
	SkillNode* locateNode (SkillNode* start, const char* searchKey) const;
	void preorderTraverse (ostream& value, const SkillNode* rootValue, const unsigned int height) const;
	void inorderTraverse (SkillNode* rootValue);
	void copyTree (SkillNode* rootValue);

	static const unsigned int NUM_CHILD = NUMBER_OF_CHILD;
	
	char* title; // the name of this tree
	SkillNode* root;
};

#endif SKILLTREE_H