#include <iostream>
using namespace std;

#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"

#include "Character.cpp"
#include "Mage.cpp"
#include "Scoundrel.cpp"

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
    cout << "Mage Incarnate:" << pMage->hasIncarateSummon() << endl;
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
}