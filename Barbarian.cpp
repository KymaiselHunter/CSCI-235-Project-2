#include "Barbarian.hpp"

//Constructors
//default
Barbarian::Barbarian()
{
    main_weapon_ = "NONE";
    secondary_weapon_ = "NONE";
    enraged_ = false;
}

//param constructor
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

std::string Barbarian::getMainWeapon() const
{
    return main_weapon_;
}

//secondary weapon setters and getters
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

std::string Barbarian::getSecondaryWeapon() const
{
    return secondary_weapon_;    
}

//enrage setters and getters
void Barbarian::setEnrage(const bool &pEnrage)
{
    enraged_ = pEnrage;
}

bool Barbarian::getEnrage() const
{
    return enraged_;
}

void Barbarian::toggleEnrage()
{
    enraged_ = !enraged_;
}