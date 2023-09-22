//Name : Kyle
//Instructor : Dr. Tiziana Ligorio
//Project 2

#include "Ranger.hpp"

//Constructors
//Default
/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
*/
Ranger::Ranger()
{
    has_companion_ = false;
}

//Paramertrized
/**
   Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false
  @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Invalid arrows are those with non-positive quantities or invalid types.
                If the vector contains invalid arrows, those arrows are discarded. 
                Default to empty vector
  @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
                String inputs can be in lowercase, but must be converted to uppercase.
                If the vector contains invalid affinities, those affinities are discarded.
                Default to empty vector
  @param      : A flag indicating whether the character is able to recruit an animal companion. 
                Default to false
  @post       : The private members are set to the values of the corresponding parameters
*/
Ranger::Ranger(const std::string &pName, const std::string &pRace, int pVitality, 
        int pArmor, int pLevel, bool pEnemy,
        const std::vector<Arrows> pArrows, const std::vector<std::string> pAffinities, const bool pCompanian)
        :
        Character(pName, pRace, pVitality, pArmor, pLevel, pEnemy)
{
    //int arrowSize = pArrows.size();
    for(size_t i = 0; i < pArrows.size(); i++)//size_t
    {
        this->addArrows(pArrows.at(i).type_, pArrows.at(i).quantity_);
    }

    //int affinitiesSize = pAffinities.size();
    for(size_t i = 0; i < pAffinities.size(); i++)
    {
        this->addAffinity(pAffinities.at(i));
    }

    this->setCompanion(pCompanian);
}

//Arrow methods
/**
  @return     : a vector of the Character's arrows
**/
std::vector<Arrows> Ranger::getArrows() const
{
    return arrows_;
}

/**
    @param    : a reference to string representing the arrow type
    @param    : a reference to an integer quantity
    @post     : If the character already has that type of arrow, the quantity in the vector 
                is updated. If not, the arrow is added to the vector. 
                Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Quantity of arrows must be greater than 0
                Invalid arrows are those with non-positive quantities or invalid types.
                If the arrows are invalid, they are not added.
    @return   : True if the arrows were added successfully, false otherwise
**/
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
    //int vectorSize = arrows_.size();
    bool newArrowType = true;
    int arrowIndex = -1;//unused if arrow of this type does not exist
    //loops through the arrow vector to see if it should be updated
    for(size_t i = 0; i < arrows_.size(); i++)
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

/**
    @param    : a reference to string representing the arrow type
    @post     : If the character has the listed arrow AND enough arrows to fire one, 
                the quantity of remaining arrows in the vector is updated.
                Lowercase valid arrow types are accepted but converted to uppercase.
                If firing the last arrow, simply decrement the quantity to 0.
    @return   : True if the character had the listed arrow AND enough arrows, False otherwise.
**/
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
    //int vectorSize = arrows_.size();
    bool hasArrowType = false;
    int arrowIndex = -1;//unused if arrow of this type does not exist
    //loops through the arrow vector to see if it should be updated
    for(size_t i = 0; i < arrows_.size(); i++)
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
/**
    @param  : a reference to string representing an affinity 
    @post   : If the affinity does not already exist in the vector, add it to the vector.
              Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
              String inputs can be in lowercase, but must be converted to uppercase when 
              setting the variable.
              There should be no duplicate affinities.
              If the affinity is invalid, it is NOT added.
    @return : True if the affinity was added successfully, false otherwise
**/
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
    //int vectorSize = affinities_.size();
    //loops through the affinities vector to see if it should be updated
    for(size_t i = 0; i < affinities_.size(); i++)
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

/**
  @return     : a vector of the Character's affinities
**/
std::vector<std::string> Ranger::getAffinities() const
{
    return affinities_;
}

//Companion setters and getters
/**
    @param    : a reference to a boolean indicating whether the character is able to recruit 
                an animal companion
    @post     : sets the private member variable to the value of the parameter.
**/
void Ranger::setCompanion(const bool &pCompanion)
{
    has_companion_ = pCompanion;
}

/**
    @return   : a boolean indicating whether the character is able to recruit an animal companion
**/
bool Ranger::getCompanion() const
{
    return has_companion_;
}