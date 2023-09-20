#include <iostream>
using namespace std;

#include "Character.hpp"
#include "Mage.hpp"

#include "Character.cpp"
#include "Mage.cpp"

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

int main()
{
    Mage m;
    //printCharacterAttributes(&m);
    printMageAttributes(&m);
    
}