//Name : Kyle
//Instructor : Dr. Tiziana Ligorio
//Project 2

#ifndef RANGER_HPP
#define RANGER_HPP

#include "Character.hpp"

#include<string>
#include<vector>

struct Arrows
{
    std::string type_;
    int quantity_;
};


class Ranger: public Character
{
    private:
        std::vector<Arrows> arrows_;
        std::vector<std::string> affinities_;
        bool has_companion_;

    public:
        Ranger();
        

        Ranger(const std::string &pName, const std::string &pRace = "NONE", int pVitality = 0, 
        int pArmor = 0, int pLevel = 0, bool pEnemy = false, 
        const std::vector<Arrows> pArrows = std::vector<Arrows>(), const std::vector<std::string> pAffinities = std::vector<std::string>(), const bool pCompanian = false);

        std::vector<Arrows> getArrows() const;
        bool addArrows(const std::string &pType, const int &pQuantity);
        bool fireArrow(const std::string &pType);

        bool addAffinity(const std::string &pAffinity);
        std::vector<std::string> getAffinities() const;

        void setCompanion(const bool &pCompanion);
        bool getCompanion() const;
};



#endif //RANGER_HPP