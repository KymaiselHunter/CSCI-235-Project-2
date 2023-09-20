#ifndef SCOUNDREL_HPP
#define SCOUNDREL_HPP

#include "Character.hpp"

#include <string>

//enum for types of daggers
enum Dagger {WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE};

class Scoundrel : public Character
{
    private:
        Dagger dagger_;
        std::string faction_;
        bool has_disguise_;

    public: 
        //Constructors
        Scoundrel();
        Scoundrel(const std::string &pName, const std::string &pRace = "NONE", int pVitality = 0, 
        int pArmor = 0, int pLevel = 0, bool pEnemy = false, const std::string &pDagger = "WOOD", 
        const std::string &pFaction = "NONE", bool pDisguise = false);

        //accessor and mutators
        //Dagger accessor and mutators
        void setDagger(const std::string &pDagger);
        std::string getDagger() const;

        //Faction accessor and mutator
        bool setFaction(const std::string &pFaction);
        std::string getFaction() const;

        //disguise accesor and mutator
        void setDisguise(const bool &pDisguise);
        bool hasDisguise() const;
};

#endif //SCOUNDREL_HPP