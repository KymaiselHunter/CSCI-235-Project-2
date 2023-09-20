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

int main()
{
    Character m;
    printCharacterAttributes(&m);

    
}