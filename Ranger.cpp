#include "Ranger.hpp"

//Constructors
//Default
Ranger::Ranger()
{
    has_companion_ = false;
}

//Paramertrized
Ranger::Ranger(const std::string &pName, const std::string &pRace, int pVitality, 
        int pArmor, int pLevel, bool pEnemy,
        const std::vector<Arrows> pArrows, const std::vector<std::string> pAffinities, const bool pCompanian)
        :
        Character(pName, pRace, pVitality, pArmor, pLevel, pEnemy)
{
    int arrowSize = pArrows.size();
    for(int i = 0; i < arrowSize; i++)
    {
        this->addArrows(pArrows.at(i).type_, pArrows.at(i).quantity_);
    }

    int affinitiesSize = pAffinities.size();
    for(int i = 0; i < affinitiesSize; i++)
    {
        this->addAffinity(pAffinities.at(i));
    }

    this->setCompanion(pCompanian);
}

std::vector<Arrows> Ranger::getArrows() const
{
    return arrows_;
}

bool Ranger::addArrows(const std::string &pType, const int &pQuantity)
{
    //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pType.length();

    for(int i = 0; i < inputLength; i++)
    {
        capitalInput += toupper(pType[i]);
    }
    
    //if invalid type leave and return false
    if(capitalInput != "WOOD" && capitalInput != "FIRE" && capitalInput != "WATER" &&
    capitalInput != "POISON"&& capitalInput != "BLOOD") return false;

    //varibables to check if this arrow exists or not
    int vectorSize = arrows_.size();
    bool newArrowType = true;
    int arrowIndex = -1;//unused if arrow of this type does not exist
    //loops through the arrow vector to see if it should be updated
    for(int i = 0; i < vectorSize; i++)
    {
        //if this arrow type already exists, just add to arrow struct quantity
        if(arrows_.at(i).type_ == capitalInput) 
        {
            newArrowType = false;
            arrowIndex = i;
        }
    }

    if(newArrowType)
    {
        //add new arrow with newType
        Arrows newArrow;
        newArrow.quantity_ = pQuantity;
        newArrow.type_ = capitalInput;
        arrows_.push_back(newArrow);
    }
    else
    {
        //add arrows to existing arrow type
        arrows_.at(arrowIndex).quantity_ += pQuantity;
    }
    return true;
}

bool Ranger::fireArrow(const std::string &pType)
{
    //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pType.length();

    for(int i = 0; i < inputLength; i++)
    {
        capitalInput += toupper(pType[i]);
    }
    
    //if invalid type leave and return false
    if(capitalInput != "WOOD" && capitalInput != "FIRE" && capitalInput != "WATER" &&
    capitalInput != "POISON"&& capitalInput != "BLOOD") return false;

    //varibables to check if this arrow exists or not
    int vectorSize = arrows_.size();
    bool hasArrowType = false;
    int arrowIndex = -1;//unused if arrow of this type does not exist
    //loops through the arrow vector to see if it should be updated
    for(int i = 0; i < vectorSize; i++)
    {
        //if this arrow type already exists, just add to arrow struct quantity
        if(arrows_.at(i).type_ == capitalInput) 
        {
            hasArrowType = true;
            arrowIndex = i;
        }
    }

    //if they have the arrow type and quantity, fire it
    if(hasArrowType && arrows_.at(arrowIndex).quantity_ > 0)
    {
        //FIREEEEE
        arrows_.at(arrowIndex).quantity_ -= 1;
        return true;
    }
    else return false;
}

//affinity methods
bool Ranger::addAffinity(const std::string &pAffinity)
{
     //takes parameter and capitalizes it into capitalInput;
    std::string capitalInput;
    int inputLength = pAffinity.length();

    for(int i = 0; i < inputLength; i++)
    {
        capitalInput += toupper(pAffinity[i]);
    }
    
    //if invalid type leave and return false
    if(capitalInput != "FIRE" && capitalInput != "WATER" && 
    capitalInput != "POISON" && capitalInput != "BLOOD") return false;

    //varibables to check if this AFFINITY is in the vector or not
    int vectorSize = affinities_.size();
    //loops through the affinities vector to see if it should be updated
    for(int i = 0; i < vectorSize; i++)
    {
        //if this affinity already exists, return false
        if(affinities_.at(i) == capitalInput) 
        {
            
            return false;
        }
    }

    affinities_.push_back(capitalInput);
    return true;
}

std::vector<std::string> Ranger::getAffinities() const
{
    return affinities_;
}

void Ranger::setCompanion(const bool &pCompanion)
{
    has_companion_ = pCompanion;
}

bool Ranger::getCompanion() const
{
    return has_companion_;
}