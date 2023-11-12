/*


10/31/23: today I added the stat modifier functionality, these are the ones that are added to rolls

11 November 2023 16:00 - Mark Ardrey
  Commented out the player class to define it in the main program
    for easier manipulation.
    (Note: may re-define player in this file instead, to streamline main.)
*/

#ifndef H_creatures
#define H_creatures

#include <iostream>

class creatureType{
    public:
        int getHealth();
        void setHealth(int hp);

        void changeHealth(int changeFactor);

        int getStrength();
        void setStrength(int str);

        int getLevel();
        void setLevel(int lvl);

        int getDefense();
        void setDefense(int def);

        void unarmedAttack(creatureType& opponent);

        int getCharisma();
        void setCharisma(int cha);

        int getDexterity();
        void setDexterity(int dex);

        int getWisdom();
        void setWisdom(int wis);

        int getIntelligene();
        void setIntelligence(int intell);

        int getConstitution();
        void setConstitution(int con);

        int getStrMod();
        int getChaMod();
        int getDexMod();
        int getWisMod();
        int getIntMod();
        int getConMod();

        int modCalc(int baseStat);

        void setStrMod();
        void setChaMod();
        void setDexMod();
        void setWisMod();
        void setIntMod();
        void setConMod();
    private:
        int health;
        int level;
        int defense;

        int strength;
        int charisma;
        int dexterity;
        int wisdom;
        int intelligence;
        int constitution;

        int strMod;
        int chaMod;
        int dexMod;
        int widMod;
        int intMod;
        int conMod;
};
    int creatureType::getHealth(){
        return this->health;
    }

    void creatureType::setHealth(int hp){
        this->health = hp;
    }

    void creatureType::changeHealth(int changeFactor){
        int tempHealth = getHealth();
        tempHealth += changeFactor;

        setHealth(tempHealth);
    }

    int creatureType::getStrength(){
        return this->strength;
    }

    void creatureType::setStrength(int str){
        this->strength = str;
    }

    int creatureType::getLevel(){
        return this->level;
    }

    void creatureType::setLevel(int lvl){
        this->level = lvl;
    }

    int creatureType::getDefense(){
        return this->health;
    }

    void creatureType::setDefense(int def){
        this->defense = def;
    }

    int creatureType::getCharisma(){
        return this->charisma;
    }

    void creatureType::setCharisma(int cha){
        this->charisma = cha;
    }

    int creatureType::getDexterity(){
        return this->dexterity;
    }

    void creatureType::setDexterity(int dex){
        this->dexterity = dex;
    }

    int creatureType::getWisdom(){
        return this->wisdom;
    }

    void creatureType::setWisdom(int wis){
        this->wisdom = wis;
    }

    int creatureType::getIntelligene(){
        return this->intelligence;
    }

    void creatureType::setIntelligence(int intell){
        this->intelligence = intell;
    }

    int creatureType::getConstitution(){
        return this->constitution;
    }

    void creatureType::setConstitution(int con){
        this->constitution = con;
    }

    int creatureType::getStrMod(){
        return this->strMod;
    }
    int creatureType::getChaMod(){
        return this->chaMod;
    }
    int creatureType::getDexMod(){
        return this->dexMod;
    }
    int creatureType::getWisMod(){
        return this->widMod;
    }
    int creatureType::getIntMod(){
        return this->intMod;
    }
    int creatureType::getConMod(){
        return this->conMod;
    }



    void creatureType::setStrMod(){
        int mod = modCalc(getStrength());
        this->strMod = mod;
    }
    void creatureType::setChaMod(){
        int mod = modCalc(getCharisma());
        this->chaMod = mod;
    }
    void creatureType::setDexMod(){
        int mod = modCalc(getDexterity());
        this->dexMod = mod;
    }
    void creatureType::setWisMod(){
        int mod = modCalc(getWisdom());
        this->widMod = mod;
    }
    void creatureType::setIntMod(){
        int mod = modCalc(getIntelligene());
        this->intMod = mod;
    }
    void creatureType::setConMod(){
        int mod = modCalc(getConstitution());
        this->conMod = mod;
    }


    int creatureType::modCalc(int baseStat){
        int mod = baseStat;
        mod -= 10;
        mod /= 2;
        return mod;
    }


    void creatureType::unarmedAttack(creatureType& opponent){
        int damage = -1 - getStrMod();
        opponent.changeHealth(damage);
    }

/*class player : public creatureType{
    public:
        player();
    private: 
};

player::player(){
    setHealth(5);
    setStrength(2);
    setLevel(1);
    setDefense(1);

    }*/


class wolf : public creatureType{
    public:
        wolf();
}; 

wolf::wolf(){
    setHealth(4);
    setStrength(4);
    setLevel(1);
    setDefense(1);
}

#endif
