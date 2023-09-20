#include "Mage.hpp"

//Constructors
Mage::Mage()
{
    school_of_magic_ = "NONE";
    weapon_ = "NONE";
    can_summon_incarnate_ = false;
}

//Parameterized constructor
// Mage::Mage(const std::string &pName, const std::string &pRace, int pVitality, 
//         int pArmor, int pLevel, bool pEnemy, const std::string &pSchool, 
//         const std::string &pWeapon, bool pSummon)
// {

// }

//School Setter and getter
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

std::string Mage::getSchool() const
{
    return school_of_magic_;
}

//Casting Weapons setters and getters
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

std::string Mage::getCastingWeapon() const
{
    return weapon_;
}

//Incarnate setters and getters
void Mage::setIncarnateSummon(const bool &pSummon)
{
    can_summon_incarnate_ = pSummon;
}

bool Mage::hasIncarateSummon() const
{
    return can_summon_incarnate_;
}