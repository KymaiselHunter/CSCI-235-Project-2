#include "Scoundrel.hpp"

//constructors
//default
Scoundrel::Scoundrel()
{
    dagger_ = WOOD;
    faction_ = "NONE";
    has_disguise_ = false;
}

// parameterized
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
//Dagger setter
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
    else dagger_ = BRONZE;
}

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
std::string Scoundrel::getFaction() const
{
    return faction_;
}

//disguise setters and getters
//Scoundrel setter
void Scoundrel::setDisguise(const bool &pDisguise)
{
    has_disguise_ = pDisguise;
}

//Scoundrel getter
bool Scoundrel::hasDisguise() const
{
    return has_disguise_;
}
