//This header file will be used to define the classes of the creatures in the game.
// It uses an abstract creature class that holds the stats and logic for said class which each creature will then inherent. 
//Creatures using weapons attacks use composition having a weapon. 

//10/31/23: today I added the stat modifier functionality, these are the ones that are added to rolls
//11/12/23: today i added dice roll functionality to the attacks and added a max health stat


#ifndef H_creatures
#define H_creatures

#include <iostream>
#include "diceRoll.h"
#include "weapons.h"

using namespace std;

//this is the abstract class for each creature
class creatureType{
    public:
        //these functions handle health and max health
        //hp being the value that will be manipulated in combat
        //and the private maxhp is use to reset that after healing
        int getHealth();
        void setHealth(int hp);
        void initializeHealth();

        int getMaxHealth();
        void setMaxHealth(int hp);

        //changes the current health by a certain amount
        void changeHealth(int changeFactor);

        //these functions are simply used to retrive and assing the stats 
        int getStrength();
        void setStrength(int str);

        int getLevel();
        void setLevel(int lvl);

        int getDefense();
        void setDefense(int def);

        //this function generates a random amount of damage and changes another creature object by that amount

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

        //these functions get and set the modifiers of the stats. The modifiers are little weird but these are the stats that
        //are actually added to the rolls
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

        int savingRoll(int mod);
        int initiative();

        string name;
    private:
        int health;
        int level;
        int defense;
        int maxHealth;

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

    void creatureType::initializeHealth(){
        this->health = this->maxHealth;
    }

    void creatureType::changeHealth(int changeFactor){
        int tempHealth = getHealth();
        tempHealth += changeFactor;

        setHealth(tempHealth);
    }

    int creatureType::getMaxHealth(){
        return this->maxHealth;
    }
    void creatureType::setMaxHealth(int hp){
        this->maxHealth = hp;
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

    int creatureType::savingRoll(int mod){
        int roll = diceRoll(1,20);
        roll += mod;
        return roll;
    }

    int creatureType::initiative(){
        int roll = diceRoll(1,20);
        roll += getDexMod();
        return roll;
    }


    void creatureType::unarmedAttack(creatureType& opponent){
        int attackCheck = diceRoll(1,20);
        attackCheck += getStrMod();
        if(attackCheck >= opponent.getDefense()){
            int damage = diceRoll(1,4);
            damage = -1*(damage+getStrMod());
            cout << name << "hits " << opponent.name << "dealing " << damage << "damage." << endl;
            if(damage > opponent.getHealth()){
                opponent.setHealth(0);
            }
            opponent.changeHealth(damage);
            cout << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }

//a beta player class used currently just for testing, the actual player would be in the main cpp file
//since it can be more easily manipulated
class player : public creatureType{
    public:
        player();
        void heal();
        bool forfeit();

    private: 
};

void player::heal(){
    int healAmount = diceRoll(1,8);
    cout << "The player drinks a health potion, healing " << healAmount << " health" << endl;
    changeHealth(healAmount);
}

bool player::forfeit(){
    char choice;
    cout << "Would you like to run away. You will have to roll a 4 or above to succeed. Type y or n: ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y'){
        int forfeitRoll = diceRoll(1, 6);
        cout << "You rolled a " << forfeitRoll << endl;
        if(forfeitRoll >= 4){
            cout << "You sucessfully flee." << endl;
            return true;
        }else{
            cout << "You're attempt to run fails." << endl;
            return false
        }
    }else{
        return false;
    }
}

player::player(){
    setMaxHealth(8);
    initializeHealth();
    setStrength(12);
    setLevel(1);
    setDefense(1);
    setStrMod();
    setChaMod();
    setDexMod();
    setWisMod();
    setIntMod();
    setConMod();
}

//a wolf enemy class
class wolf : public creatureType{
    public:
        wolf();
        void bite(creatureType& opponent);
}; 

void wolf::bite(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrMod();
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(2,4);
        cout << "The wolf lunges at " << opponent.name << "dealing " << damage << "damage" << endl;
        damage = -1*(damage+getStrMod());
        if(damage > opponent.getHealth()){
            opponent.setHealth(0);
        }
        opponent.changeHealth(damage);
        cout << "The player has " << opponent.getHealth() << " health left." << endl;
    }else{
        cout << "The wolves attack miss " << opponent.name << endl;
    }
    
}

wolf::wolf(){
    setMaxHealth(11);
    initializeHealth();
    setStrength(12);
    setLevel(1);
    setDefense(13);
    setCharisma(5);
    setDexterity(6);
    setWisdom(6);
    setIntelligence(3);
    setConstitution(13);

    setStrMod();
    setChaMod();
    setDexMod();
    setWisMod();
    setIntMod();
    setConMod();
}

class zombie: public creatureType{
    public:
        zombie();
        void slam(creatureType& opponent);
        void undeadFortitude();
};

zombie::zombie(){
    setMaxHealth(22);
    initializeHealth();
    setStrength(13);
    setLevel(1);
    setDefense(8);
    setCharisma(5);
    setDexterity(6);
    setWisdom(6);
    setIntelligence(3);
    setConstitution(16);

    setStrMod();
    setChaMod();
    setDexMod();
    setWisMod();
    setIntMod();
    setConMod();
}

void zombie::slam(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrMod();
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1,6);
        damage = -1*(damage+getStrMod());
        if(damage > opponent.getHealth()){
            opponent.setHealth(0);
        }
        opponent.changeHealth(damage);
    }
}

void zombie::undeadFortitude(){
    int reviveCheck = diceRoll(1,20);
    reviveCheck += savingRoll(getConMod());
    if(reviveCheck > 10){
        setHealth(1);
    }
}

class skeleton: public skeleton{
    public:
    
};



#endif