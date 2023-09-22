#include <iostream>
using namespace std;

#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"

#include "Character.cpp"
#include "Mage.cpp"
#include "Scoundrel.cpp"
#include "Ranger.cpp"
#include "Barbarian.cpp"

#include <vector>
void printCharacterAttributes(Character *pCharacter)
{
    cout << "Character Name: " << pCharacter->getName() << endl;
    cout << "Character Race: " << pCharacter->getRace() << endl;
    cout << "Character Vitality: " << pCharacter->getVitality() << endl;
    cout << "Character Armor: " << pCharacter->getArmor() << endl;
    cout << "Character Level: " << pCharacter->getLevel() << endl;
    cout << "Character isEnemy: " << pCharacter->isEnemy() << endl;
}

void printMageAttributes(Mage *pMage)
{
    printCharacterAttributes(pMage);

    cout << "\nUnique Mage attributes: " << endl;
    cout << "Mage School: " << pMage->getSchool() << endl;
    cout << "Mage Weapon: " << pMage->getCastingWeapon() << endl;
    cout << "Mage Incarnate:" << pMage->hasIncarnateSummon() << endl;
}

void testMageSetters(Mage *pMage, string pSchool = "NONE", string pWeapon = "NONE", bool pIncarnate = false)
{
    pMage->setSchool(pSchool);
    pMage->setCastingWeapon(pWeapon);
    pMage->setIncarnateSummon(pIncarnate);

    printMageAttributes(pMage);
}

void printScoundrelAttributes(Scoundrel *pScoundrel)
{
    printCharacterAttributes(pScoundrel);

    cout << "\nUnique Scoundrel attributes: " << endl;
    cout << "Scoundrel Dagger: " << pScoundrel->getDagger() << endl;
    cout << "Scoundrel Faction: " << pScoundrel->getFaction() << endl;
    cout << "Scoundrel Disguise: " << pScoundrel->hasDisguise() << endl;
}

void printRangerAttributes(Ranger *pRanger)
{
    printCharacterAttributes(pRanger);

    vector<Arrows> rangerQuiver = pRanger->getArrows();
    
    cout << "Ranger Quiver:" << endl;
    for(int i = 0; i < rangerQuiver.size(); i++)
    {
        cout << rangerQuiver.at(i).type_ << " : " << rangerQuiver.at(i).quantity_ << endl;
    }
    
    vector<string> rangerAffinities = pRanger->getAffinities();
    
    cout << "Ranger Affinities: " << endl;
    for(int i = 0 ; i < rangerAffinities.size(); i++)
    {
        cout << rangerAffinities.at(i) << endl;
    }

    cout << "Has Companion: " << pRanger->getCompanion() << endl;
}

void testRangerSetters(Ranger *pRanger, string pArrowType = "NONE", int pArrowQuantity = 0, string pAffinity = "NONE", bool pCompanion = false)
{
    cout << "Arrow added?: "<<pRanger->addArrows(pArrowType, pArrowQuantity) << endl;
    pRanger->addAffinity(pAffinity);
    pRanger->setCompanion(pCompanion);

    printRangerAttributes(pRanger);

    pRanger->fireArrow(pArrowType);
    pRanger->fireArrow("wood");

    printRangerAttributes(pRanger);
}

void printBarbarianAttributes(Barbarian *pBarbarian)
{
    printCharacterAttributes(pBarbarian);

    cout << "\nUnique Barbarian attributes: " << endl;
    cout << "Barbarian main: " << pBarbarian->getMainWeapon() << endl;
    cout << "Barbarian secondary: " << pBarbarian->getSecondaryWeapon() << endl;
    cout << "Barbarian enrage: " << pBarbarian->getEnrage() << endl;
}

void testBarbarianSetters(Barbarian *pBarbarian, string pMainWeapon = "NONE", string pSecondaryWeapon = "NONE", bool pEnrage = false)
{
    pBarbarian->setMainWeapon(pMainWeapon);
    pBarbarian->setSecondaryWeapon(pSecondaryWeapon);
    pBarbarian->setEnrage(pEnrage);

    printBarbarianAttributes(pBarbarian);

    cout <<"Test toggle" << endl;
    pBarbarian->toggleEnrage();
    printBarbarianAttributes(pBarbarian);
}

int main()
{
    Mage m;
    //printCharacterAttributes(&m);
    printMageAttributes(&m);
    
    testMageSetters(&m, "elemental", "WAnd", true);

    cout << "Test Paramertized Mage Constructor" << endl;
    Mage m2 = Mage("Kyle", "HUMAN", 1000, 2000, 3000, false, "elemental", "WAnd", true);
    printMageAttributes(&m2);

    cout << "\nTest Scoundrel" << endl;
    Scoundrel s;
    printScoundrelAttributes(&s);

    cout << "Test Paramertized SCoundrel Constructor" << endl;
    Scoundrel s2 = Scoundrel("Kyle", "HUMAN", 1000, 2000, 3000, false, "iron", "shadowblade", true);
    printScoundrelAttributes(&s2);

    cout << "\nTest Ranger" << endl;
    Ranger r;
    printRangerAttributes(&r);

    testRangerSetters(&r, "fire", 5, "water", true);
    
    cout << "Test Paramertized Ranger Constructor" << endl;
    Arrows testArrow;
    testArrow.type_ = "poison";
    testArrow.quantity_ = 25;

    vector<Arrows> testQuiver;
    testQuiver.push_back(testArrow);

    vector<string> testAffinities;
    testAffinities.push_back("FIRE");

    Ranger r2 = Ranger("Kyle", "HUMAN", 1000, 2000, 3000, false, testQuiver, testAffinities, true);
    printRangerAttributes(&r2);

    cout << "Test Default Paramertized Ranger Constructor" << endl;
    Ranger r3 = Ranger("Kyle");
    printRangerAttributes(&r3);

    cout << "Test Barbarian: " << endl;
    Barbarian b;
    printBarbarianAttributes(&b);
    testBarbarianSetters(&b, "deez", "nuts", true);

    cout << "Test Paramertized Barbarian Constructor" << endl;
    Barbarian b2 = Barbarian("Kyle", "HUMAN", 1000, 2000, 3000, false, "yo", "mama", true);
    printBarbarianAttributes(&b2);
}