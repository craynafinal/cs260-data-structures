#ifndef PLAYER_H
#define PLAYER_H

enum PlayerGender {MALE, FEMALE, UNKOWN};

const unsigned int SET_INITIAL_LEVEL = 0;

class Player
{
public:
	// default constructor
	//		1. members are automatically set to default values
	Player (); 

	// constructor with 3 parameters
	//		1. set members with 3 parameters passed
	//		2. nameValue should be string variable of a player's name
	//		3. genderValue should be PlayerGender variable, refer to enum declared above this class
	//		4. levelValue should be unsigned integer
	Player (const char* nameValue, const PlayerGender genderValue, const unsigned int levelValue);

	// constructor with 2 parameters
	//		1. same as the constructor with 3 parameters above, but does not take level value
	//		2. use default level value (INITIAL_LEVEL)
	Player (const char* nameValue, const PlayerGender genderValue);

	// copy constructor
	//		1. should pass Player object
	//		2. invokes operator=
	Player (const Player& value);

	// destructor
	//		1. does nothing but invokes destroyName ()
	~Player (); // destructor

	// operator=
	//		1. takes Player object as variable
	//		2. if two objects are not the same, this object copies from the parameter
	//		3. copies all members, invoking setName (), setGender (), setLevel ()
	void operator= (const Player& value);

	// destoryName
	//		1. if this object has name member initialized, delete the member to prevent memory leak
	void destroyName ();

	// getName
	//		1. returns member name
	char* getName () const;

	// setName
	//		1. takes char* variable that is the name of a player
	//		2. if the parameter is initialized, copies it into name
	void setName (const char* nameValue);

	// getGender
	//		1. returns member gender
	PlayerGender getGender () const;

	// setGender
	//		1. assign gender with parameter genderValue
	void setGender (const PlayerGender genderValue);

	// getLevel
	//		1. returns member level
	unsigned int getLevel () const;

	// setLevel
	//		1. sets member level with parameter levelValue
	void setLevel (const unsigned int levelValue);

	// levelUp
	//		1. increase the value of member level by 1
	void LevelUp ();

	// isInitialized
	//		1. checks if members of this object initialized
	//		2. returns false if initialized, true otherwise
	bool isInitialized () const;
	
private:
	// members
	static const unsigned int INITIAL_LEVEL = SET_INITIAL_LEVEL;	// starting level
	char* name;														// player name
	PlayerGender gender;											// player gender
	unsigned int level;												// player level
};

#endif PLAYER_H
