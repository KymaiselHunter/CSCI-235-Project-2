#ifndef MAGE_HPP
#define MAGE_HPP

#include "Character.hpp"
#include <string>

class Mage : public Character
{
    private:
        std::string school_of_magic_;
        std::string weapon_;
        bool can_summon_incarnate_;

    public:
        //Constructors      
        Mage();

        //p = parameter
        Mage(const std::string &pName, const std::string &pRace = "NONE", int pVitality = 0, 
        int pArmor = 0, int pLevel = 0, bool pEnemy = false, const std::string &pSchool = "NONE", 
        const std::string &pWeapon = "NONE", bool pSummon = false);

        //School accessor and mutator
        bool setSchool(const std::string &pSchool);
        std::string getSchool() const;

        //weapon accesor and mutator
        bool setCastingWeapon(const std::string &pWeapon);
        std::string getCastingWeapon() const;

        //incarnateSummon accessor and mutator
        void setIncarnateSummon(const bool &pSummon);
        bool hasIncarateSummon() const;
};


#endif //MAGE_HPP
