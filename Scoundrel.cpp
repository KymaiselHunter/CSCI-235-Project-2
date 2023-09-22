//Name : Kyle
//Instructor : Dr. Tiziana Ligorio
//Project 2

#include "Scoundrel.hpp"

//constructors
/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
*/
Scoundrel::Scoundrel()
{
    dagger_ = WOOD;
    faction_ = "NONE";
    has_disguise_ = false;
}

/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false.
    @param      : The character's dagger type (a const string reference).
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the dagger enum. Default to WOOD
    @param      : The character's Faction (a const string reference). 
                  Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the variable. Default to "NONE"
    @param      : A flag indicating whether the character has a disguise. Default to false
    @post       : The private members are set to the values of the corresponding 
                  parameters.
                 If the dagger type is not provided or invalid, the variable should 
                  be set to WOOD. 
                 If the Faction is not provided or invalid, the variable should be 
                  set to "NONE". 
*/
Scoundrel::Scoundrel(const std::string &pName, const std::string &pRace, int pVitality, 
        int pArmor, int pLevel, bool pEnemy, const std::string &pDagger, 
        const std::string &pFaction, const bool pDisguise)
        :
        Character(pName, pRace, pVitality, pArmor, pLevel, pEnemy)
{
    setDagger(pDagger);
    if(!this->setFaction(pFaction)) faction_ = "NONE";
    has_disguise_ = pDisguise;
}

//Dagger setter and getters
/**
   @param     : a reference to a string representing the dagger type
   @post      : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the dagger type is not valid (i.e, is one of the following: 
                [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                the variable should be set to WOOD. 
**/
void Scoundrel::setDagger(const std::string &pDagger)
{
    //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pDagger.length();

    for(int i = 0; i < inputLength; i++)
    {
        capitalInput += toupper(pDagger[i]);
    }

    //sets dagger to respective enum
    if(capitalInput == "BRONZE") dagger_ = BRONZE;
    else if(capitalInput == "IRON") dagger_ = IRON; 
    else if(capitalInput == "STEEL") dagger_ = STEEL;
    else if(capitalInput == "MITHRIL") dagger_ = MITHRIL;
    else if(capitalInput == "ADAMANT") dagger_ = ADAMANT;
    else if(capitalInput == "RUNE") dagger_ = RUNE;
    else dagger_ = WOOD;
}


/**
  @return     : the string indicating the character's dagger type
**/
std::string Scoundrel::getDagger() const
{
    if(dagger_ == BRONZE) return "BRONZE";
    else if(dagger_ == IRON) return "IRON";
    else if(dagger_ == STEEL) return "STEEL";
    else if(dagger_ == MITHRIL) return "STEEL";
    else if(dagger_ == ADAMANT) return "ADAMANT";
    else if(dagger_ == RUNE) return "RUNE";
    else return "WOOD";
}

//faction setters and getters
//faction setter
/**
    @param    : a reference to a string representing the character's Faction
    @post     : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the provided faction is not one of the following: 
               [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
               do nothing and return false.
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Scoundrel::setFaction(const std::string &pFaction)
{
    //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pFaction.length();

    for(int i = 0; i < inputLength; i++)
    {
        capitalInput += toupper(pFaction[i]);
    }

    //Checks if the input matches, changes and returns true if it does
    //stays the same and returns false if otherwise
    if(capitalInput == "NONE" || capitalInput == "CUTPURSE" || 
    capitalInput == "SHADOWBLADE" || capitalInput == "SILVERTONGUE")
    {
        faction_ = capitalInput;
        return true;
    }
    else return false;
}

//Faction getter
/**
  @return  : the string indicating the character's Faction
**/
std::string Scoundrel::getFaction() const
{
    return faction_;
}

//disguise setters and getters
//disguise setter
/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character has a disguise
**/
void Scoundrel::setDisguise(const bool &pDisguise)
{
    has_disguise_ = pDisguise;
}

//disguise getter
/**
  @return  : the disguise flag
**/
bool Scoundrel::hasDisguise() const
{
    return has_disguise_;
}
