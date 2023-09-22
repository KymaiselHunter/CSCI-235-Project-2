#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character
{
    private:
        std::string main_weapon_;
        std::string secondary_weapon_;
        bool enraged_;
    
    public:
        Barbarian();
        Barbarian(const std::string &pName, const std::string &pRace = "NONE", int pVitality = 0, 
        int pArmor = 0, int pLevel = 0, bool pEnemy = false, 
        const std::string pMainWeapon = "NONE", const std::string pSecondaryWeapon = "NONE", const bool pEnraged = false);

        bool setMainWeapon(const std::string &pMainWeapon);
        std::string getMainWeapon() const;

        bool setSecondaryWeapon(const std::string &pSecondaryWeapon);
        std::string getSecondaryWeapon() const;

        void setEnrage(const bool &pEnrage);
        bool getEnrage() const;
        void toggleEnrage();
};

#endif //BARBARIAN_HPP