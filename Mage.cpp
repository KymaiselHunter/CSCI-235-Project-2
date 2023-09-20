#include "Mage.hpp"

//for to upper
//#include <cctype>

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

bool Mage::setSchool(const std::string &pSchool)
{
    //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pSchool.length();

    for(int i = 0; i < inputLength; i++)
    {
        capitalInput = toupper(pSchool[i]);
    }

    if(capitalInput == "ELEMENTAL" || capitalInput == "NECROMANCY" || capitalInput == "ILLUSION")
    {
        school_of_magic_ = capitalInput;
        return true;
    }
    else return false;
    
}