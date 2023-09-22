//Name : Kyle
//Instructor : Dr. Tiziana Ligorio
//Project 2

#include "Barbarian.hpp"

//Constructors
//default
/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default weapons: "NONE". 
*/
Barbarian::Barbarian()
{
    main_weapon_ = "NONE";
    secondary_weapon_ = "NONE";
    enraged_ = false;
}

//param constructor
/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false
    @param      : The character's main weapon (a const string reference). 
                  String inputs can be in lowercase, but must be converted to uppercase 
                  when setting the variable. Only alphabetical characters are allowed.
                  Default to "NONE"
    @param      : The character's offhand weapon (a const string reference). 
                  String inputs can be in lowercase, but must be converted to uppercase 
                  when setting the variable. Only alphabetical characters are allowed.
                  Default to "NONE"
    @param      : A flag indicating whether the character is enraged. Default to false
    @post       : The private members are set to the values of the corresponding parameters. 
                : If the main and secondary weapons are not provided or invalid, the variables                    are set to "NONE".
*/
Barbarian::Barbarian(const std::string &pName, const std::string &pRace, int pVitality, 
        int pArmor, int pLevel, bool pEnemy,
        const std::string pMainWeapon, const std::string pSecondaryWeapon, const bool pEnraged)
        :
        Character(pName, pRace, pVitality, pArmor, pLevel, pEnemy)
{
    this->setMainWeapon(pMainWeapon);
    this->setSecondaryWeapon(pSecondaryWeapon);
    this->setEnrage(pEnraged);
}

//main weapon setters and getters
/**
    @param    : a reference to a string representing the Character's main weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
                If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setMainWeapon(const std::string &pMainWeapon)
{
    //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pMainWeapon.length();

    //capitalized while also checking if it's alphabetical
    //if not all letters, return false
    for(int i = 0; i < inputLength; i++)
    {
        if(!std::isalpha(pMainWeapon[i])) return false;//quick exit if not alphabetical
        capitalInput += toupper(pMainWeapon[i]);
    }

    main_weapon_ = capitalInput;
    return true;
}

/**
    @return   : a string of the Character's main weapon
**/
std::string Barbarian::getMainWeapon() const
{
    return main_weapon_;
}

//secondary weapon setters and getters
/**
    @param    : a reference to a string representing the Character's secondary weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
              : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setSecondaryWeapon(const std::string &pSecondaryWeapon)
{
    //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pSecondaryWeapon.length();

    //capitalized while also checking if it's alphabetical
    //if not all letters, return false
    for(int i = 0; i < inputLength; i++)
    {
        if(!std::isalpha(pSecondaryWeapon[i])) return false;//quick exit if not alphabetical
        capitalInput += toupper(pSecondaryWeapon[i]);
    }

    secondary_weapon_ = capitalInput;
    return true;
}

/**
   @return    : a string of the Character's secondary weapon
**/
std::string Barbarian::getSecondaryWeapon() const
{
    return secondary_weapon_;    
}

//enrage setters and getters
/**
  @param      : a reference to a bool
  @post       : sets the private member variable to the value of the parameter.
**/
void Barbarian::setEnrage(const bool &pEnrage)
{
    enraged_ = pEnrage;
}

/**
  @return  : a boolean of whether the Character is enraged
**/
bool Barbarian::getEnrage() const
{
    return enraged_;
}

/**
  @post   : sets the enraged variable to the opposite of what it was
**/
void Barbarian::toggleEnrage()
{
    enraged_ = !enraged_;
}