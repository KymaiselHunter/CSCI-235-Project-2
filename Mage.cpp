//Name : Kyle
//Instructor : Dr. Tiziana Ligorio
//Project 2

#include "Mage.hpp"

//Constructors
/**
  Default constructor.
  Default-initializes all private members. 
  Default character name: "NAMELESS". Booleans are default-initialized to False. 
  Default school of magic and weapon: "NONE". 
*/
Mage::Mage()
{
    school_of_magic_ = "NONE";
    weapon_ = "NONE";
    can_summon_incarnate_ = false;
}

//Parameterized constructor
/**
  Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false.
  @param      : The character's school of magic (a const string reference). Valid schools: 
                [ELEMENTAL, NECROMANCY, ILLUSION]. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE".
  @param      : The character's choice of weapon (a const string reference). 
                Valid weapons: [WAND, STAFF]
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE".
  @param      : A flag indicating whether the character is able to summon an 
                incarnate. Default to false.
  @post       : The private members are set to the values of the corresponding 
                parameters.
                REMEMBER: If the school of magic or weapon is not provided or invalid, the 
                variables should be set to "NONE". 
*/
Mage::Mage(const std::string &pName, const std::string &pRace, int pVitality, 
        int pArmor, int pLevel, bool pEnemy, const std::string &pSchool, 
        const std::string &pWeapon, bool pSummon)
        :
        Character(pName, pRace, pVitality, pArmor, pLevel, pEnemy)
{
    if(!this->setSchool(pSchool)) school_of_magic_ = "NONE";
    if(!this->setCastingWeapon(pWeapon)) weapon_ = "NONE";
    can_summon_incarnate_ = pSummon;
}

//School Setter and getter
/**
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. If 
              the provided school of magic is not one of the following: [ELEMENTAL, 
              NECROMANCY, ILLUSION], do nothing and return false.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setSchool(const std::string &pSchool)
{
    //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pSchool.length();

    for(int i = 0; i < inputLength; i++)
    {
        capitalInput += toupper(pSchool[i]);
    }

    //Checks if the input matches, changes and returns true if it does
    //stays the same and returns false if otherwise
    if(capitalInput == "ELEMENTAL" || capitalInput == "NECROMANCY" || capitalInput == "ILLUSION")
    {
        school_of_magic_ = capitalInput;
        return true;
    }
    else return false;
}

/**
  @return  : the string indicating the character's school of magic
**/
std::string Mage::getSchool() const
{
    return school_of_magic_;
}

//Casting Weapons setters and getters
/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
              If the provided weapon is not one of the following: 
              [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setCastingWeapon(const std::string &pWeapon)
{
    //same process of get School but with weapon names
    //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pWeapon.length();

    for(int i = 0; i < inputLength; i++)
    {
        capitalInput += toupper(pWeapon[i]);
    }
    
    //Checks if the input matches, changes and returns true if it does
    //stays the same and returns false if otherwise
    if(capitalInput == "WAND" || capitalInput == "STAFF")
    {
        weapon_ = capitalInput;
        return true;
    }
    else return false;   
}

/**
  @return  : the string indicating the character's weapon
**/
std::string Mage::getCastingWeapon() const
{
    return weapon_;
}

//Incarnate setters and getters
/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character can 
            summon an incarnate
**/
void Mage::setIncarnateSummon(const bool &pSummon)
{
    can_summon_incarnate_ = pSummon;
}

/**
  @return  : the summon-incarnate flag
**/
bool Mage::hasIncarnateSummon() const
{
    return can_summon_incarnate_;
}