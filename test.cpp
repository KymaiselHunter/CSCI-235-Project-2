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
    cout << "Name: " << pCharacter->getName() << endl;
    cout << "Race: " << pCharacter->getRace() << endl;
    cout << "Vitality: " << pCharacter->getVitality() << endl;
    cout << "Armor: " << pCharacter->getArmor() << endl;
    cout << "Level: " << pCharacter->getLevel() << endl;

    if(pCharacter->isEnemy()) cout << "Enemy: TRUE" << endl;
    else cout << "Enemy: FALSE" << endl;
}

void testMutators(Character *pCharacter, std::string pName = "NONE", const std::string pRace = "NONE", 
int pVitality = 0, int pArmor = 0, int pLevel = 0, bool pEnemy = false)
{
    pCharacter->setName(pName);
    pCharacter->setRace(pRace);
    pCharacter->setVitality(pVitality);
    pCharacter->setArmor(pArmor);
    pCharacter->setLevel(pLevel);
    if(pEnemy) pCharacter->setEnemy();
}

void printMageAttributes(Mage *pMage)
{
    printCharacterAttributes(pMage);

    //cout << "\nUnique Mage attributes: " << endl;
    cout << "School of Magic: " << pMage->getSchool() << endl;
    cout << "Weapon: " << pMage->getCastingWeapon() << endl;
    if(pMage->hasIncarnateSummon()) cout << "Summon Incarnate: TRUE" << endl;
    else cout << "Summon Incarnate: FALSE" << endl;
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

    //cout << "\nUnique Scoundrel attributes: " << endl;
    cout << "Dagger: " << pScoundrel->getDagger() << endl;
    cout << "Faction: " << pScoundrel->getFaction() << endl;
    if(pScoundrel->hasDisguise()) cout << "Disguise: TRUE" << endl;
    else cout << "Disguise: FALSE" << endl;
}

void printRangerAttributes(Ranger *pRanger)
{
    printCharacterAttributes(pRanger);

    vector<Arrows> rangerQuiver = pRanger->getArrows();
    
    cout << "Vector of arrows: ";
    for(int i = 0; i < rangerQuiver.size(); i++)
    {
        cout << rangerQuiver.at(i).type_ << ", " << rangerQuiver.at(i).quantity_;
        if(i < rangerQuiver.size() - 1) cout << ", ";
    }
    
    vector<string> rangerAffinities = pRanger->getAffinities();
    
    cout << "\nRanger Affinities: ";
    for(int i = 0 ; i < rangerAffinities.size(); i++)
    {
        cout << rangerAffinities.at(i);
        if(i < rangerAffinities.size() - 1) cout << ", ";
    }

    if(pRanger->getCompanion()) cout << "\nAnimal Companian: TRUE" << endl;
    else cout << "\nAnimal Companian: FALSE" << endl;
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

    //cout << "\nUnique Barbarian attributes: " << endl;
    cout << "Main Weapon: " << pBarbarian->getMainWeapon() << endl;
    cout << "Offhand Weapon: " << pBarbarian->getSecondaryWeapon() << endl;
    if(pBarbarian->getEnrage()) cout << "Enraged: TRUE" << endl;
    else cout << "Enraged: FALSE" << endl;
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
    // Mage m;
    // //printCharacterAttributes(&m);
    // printMageAttributes(&m);
    
    // testMageSetters(&m, "elemental", "WAnd", true);

    // cout << "Test Paramertized Mage Constructor" << endl;
    // Mage m2 = Mage("Kyle", "HUMAN", 1000, 2000, 3000, false, "elemental", "WAnd", true);
    // printMageAttributes(&m2);

    // cout << "\nTest Scoundrel" << endl;
    // Scoundrel s;
    // printScoundrelAttributes(&s);

    // cout << "Test Paramertized SCoundrel Constructor" << endl;
    // Scoundrel s2 = Scoundrel("Kyle", "HUMAN", 1000, 2000, 3000, false, "iron", "shadowblade", true);
    // printScoundrelAttributes(&s2);

    // cout << "\nTest Ranger" << endl;
    // Ranger r;
    // printRangerAttributes(&r);

    // testRangerSetters(&r, "fire", 5, "water", true);
    
    // cout << "Test Paramertized Ranger Constructor" << endl;
    // Arrows testArrow;
    // testArrow.type_ = "poison";
    // testArrow.quantity_ = 25;

    // vector<Arrows> testQuiver;
    // testQuiver.push_back(testArrow);

    // vector<string> testAffinities;
    // testAffinities.push_back("FIRE");

    // Ranger r2 = Ranger("Kyle", "HUMAN", 1000, 2000, 3000, false, testQuiver, testAffinities, true);
    // printRangerAttributes(&r2);

    // cout << "Test Default Paramertized Ranger Constructor" << endl;
    // Ranger r3 = Ranger("Kyle");
    // printRangerAttributes(&r3);

    // cout << "Test Barbarian: " << endl;
    // Barbarian b;
    // printBarbarianAttributes(&b);
    // testBarbarianSetters(&b, "deez", "nuts", true);

    // cout << "Test Paramertized Barbarian Constructor" << endl;
    // Barbarian b2 = Barbarian("Kyle", "HUMAN", 1000, 2000, 3000, false, "yo", "mama", true);
    // printBarbarianAttributes(&b2);

    Mage m;
    testMutators(&m, "defaultMage", "ELF" , 5,3,2, true);
    printCharacterAttributes(&m);

    Mage m2 = Mage("SPYNACH", "ELF", 6, 4, 4, false, "ILLUSION", "WAND", true);
    printMageAttributes(&m2);

    //cout << "\nTest Scoundrel" << endl;
    Scoundrel s;
    testMutators(&s, " defaultScoundrel", "HUMAN",6,4,3,true);
    printCharacterAttributes(&s);

    //cout << "Test Paramertized SCoundrel Constructor" << endl;
    Scoundrel s2 = Scoundrel("FLEA", "DWARF", 12, 7, 5, false, "ADAMANT", "Cutpurse", true);
    printScoundrelAttributes(&s2);

    //cout << "\nTest Ranger" << endl;
    Ranger r;
    testMutators(&r, " defaultRanger", "UNDEAD",8,4,5,true);
    printCharacterAttributes(&r);

    
    // cout << "Test Paramertized Ranger Constructor" << endl;
    Arrows testArrow1;
    testArrow1.type_ = "Wood";
    testArrow1.quantity_ = 30;

    
    Arrows testArrow2;
    testArrow2.type_ = "Fire";
    testArrow2.quantity_ = 5;

    Arrows testArrow3;
    testArrow3.type_ = "Water";
    testArrow3.quantity_ = 5;

    Arrows testArrow4;
    testArrow4.type_ = "Poison";
    testArrow4.quantity_ = 5;

    vector<Arrows> testQuiver;
    testQuiver.push_back(testArrow1);
    testQuiver.push_back(testArrow2);
    testQuiver.push_back(testArrow3);
    testQuiver.push_back(testArrow4);

    vector<string> testAffinities;
    testAffinities.push_back("FIRE");
    testAffinities.push_back("Poison");

    Ranger r2 = Ranger("MARROW", "UNDEAD", 9, 6, 5, true, testQuiver, testAffinities, true);
    printRangerAttributes(&r2);

    cout << "Test Barbarian: " << endl;
    Barbarian b;
    testMutators(&b, "defaultBarbarian", "HUMAN", 10,5,5, true);
    printCharacterAttributes(&b);

    //cout << "Test Paramertized Barbarian Constructor" << endl;
    Barbarian b2 = Barbarian("BONK", "HUMAN", 11, 5, 5, true, "MACE", "ANOTHERMACE", true);
    printBarbarianAttributes(&b2);
}