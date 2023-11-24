//This header file is used to define an abstract class for weapons. 
//These have the stats and logic of the weapons. 
//Each weapon then inherits the weapon type each with there own attack string.

//11/12/23: The creation of this file, quickly defining the weapon class that each on will inheret

#ifndef H_weapons
#define H_weapons
#include "diceRoll.h"

using namespace std;

class weaponBase{
    public:
        int getDamage();
        int getDice();
        int getDiceAmount();
        string getDamageText();
        string getMissText();

        void setDiceType(int dice);
        void setDiceAmount(int amount);

        void setName(string name);
        void setDamageText(string damageText);
        void setMissText(string missText);
        
    private:
        int diceType;
        int amountOfDice;
        string name;
        string damageText;
        string missText;
        
};

int weaponBase::getDice(){
    return this->diceType;
}

int weaponBase::getDiceAmount(){
    return this->amountOfDice;
}

int weaponBase::getDamage(){
    int damage = diceRoll(getDiceAmount(), getDice());
    return damage;
}

void weaponBase::setDiceType(int dice){
    this->diceType = dice;
}

void weaponBase::setDiceAmount(int amount){
    this->amountOfDice = amount;
}

void weaponBase::setName(string name){
    this->name = name;
}

void weaponBase::setDamageText(string damageText){
    this->damageText = damageText;
}

void weaponBase::setMissText(string missText){
    this->missText = missText;
}

string weaponBase::getDamageText(){
    return this->damageText;
}

string weaponBase::getMissText(){
    return this->missText;
}

class club: public weaponBase{
    public:
    club();
};

club::club(){
    setDiceType(4);
    setDiceAmount(1);
    setName("club");
    setDamageText("The club bashes into the side of ");
    setMissText("The club whiffs, missing its target.\n");
}

class dagger: public weaponBase{
    public:
    dagger();
};

dagger::dagger(){
    setDiceType(4);
    setDiceAmount(1);
    setName("dagger");
    setDamageText("The dagger jabs into ");
    setMissText("The dagger cuts through the air, missing.\n");
}

class greatclub: public weaponBase{
    public:
    greatclub();
};

greatclub::greatclub(){
    setDiceType(8);
    setDiceAmount(1);
    setName("greatclub");
    setDamageText("The greatclub bashes into the side of ");
    setMissText("The greatclub whiffs, missing its target.\n");
}

class handaxe: public weaponBase{
    public:
    handaxe();
};

handaxe::handaxe(){
    setDiceType(6);
    setDiceAmount(1);
    setName("handaxe");
    setDamageText("The axe slashes ");
    setMissText("The axe clashes with the air, missing its target.\n");
}

class javelin: public weaponBase{
    public:
    javelin();
};

javelin::javelin(){
    setDiceType(6);
    setDiceAmount(1);
    setName("javelin");
    setDamageText("The javelin pierces into ");
    setMissText("The javelin pierces the air, missing its target.\n");
}

class lightHammer: public weaponBase{
    public:
    lightHammer();
};

lightHammer::lightHammer(){
    setDiceType(4);
    setDiceAmount(1);
    setName("light hammer");
    setDamageText("The light hammer bashes into ");
    setMissText("The light hammer whiffs, missing its target.\n");
}

class mace: public weaponBase{
    public:
    mace();
};

mace::mace(){
    setDiceType(6);
    setDiceAmount(1);
    setName("mace");
    setDamageText("The mace bashes into the side of ");
    setMissText("The mace whiffs, missing its target.\n");
}

class sword: public weaponBase{
    public:
    sword();
};

sword::sword(){
    setDiceType(6);
    setDiceAmount(1);
    setName("sword");
    setDamageText("The sword slashes the ");
    setMissText("The sword misses, dealing no damage.\n");
}

class scimitar: public weaponBase{
    public:
    scimitar();
};

scimitar::scimitar(){
    setDiceType(6);
    setDiceAmount(1);
    setName("scimitar");
    setDamageText("The scimitar slashes the ");
    setMissText("The scimitar misses, dealing no damage.\n");
}

#endif