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

        int savingRoll(int mod);
        int initiative();

        void weaponAttack(creatureType& opponent, weaponBase& weaponBase);

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
        if(tempHealth > getMaxHealth()){
            initializeHealth();
        }else{
            setHealth(tempHealth);
        }
        
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

    int creatureType::savingRoll(int mod){
        int roll = diceRoll(1,20);
        roll += mod;
        return roll;
    }

    int creatureType::initiative(){
        int roll = diceRoll(1,20);
        roll += getDexterity();
        return roll;
    }


    void creatureType::unarmedAttack(creatureType& opponent){
        int attackCheck = diceRoll(1,20);
        attackCheck += getStrength();
        if(attackCheck >= opponent.getDefense()){
            int damage = diceRoll(1,4);
            damage = -1*(damage+getStrength());
            cout << "The " << name << " hits " << opponent.name << "dealing " << -damage << " damage." << endl;
            if(-damage >= opponent.getHealth()){
                opponent.setHealth(0);
                cout << "The " << opponent.name << "dies";
            }else{
                opponent.changeHealth(damage);
                cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
            }
        }
    }

    void creatureType::weaponAttack(creatureType& opponent, weaponBase& weaponBase){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = weaponBase.getDamage();
        damage = -1*(damage+getStrength());
        cout << weaponBase.getDamageText() << opponent.name << " dealing " << -damage << " damage." << endl;
        if(-damage >= opponent.getHealth()){
            opponent.setHealth(0);
            cout << "The " << opponent.name << "dies";
        }else{
            opponent.changeHealth(damage);
            cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << weaponBase.getMissText();
    }
}

//a beta player class used currently just for testing, the actual player would be in the main cpp file
//since it can be more easily manipulated
class player : public creatureType{
    public:
        player();
        player(int strength, int dex, int intell, int wis, int cha, int con);
        //void weaponAttack(creatureType& opponent);
        void fireBolt(creatureType& opponent);
        void heal();
        bool forfeit();
        void levelUp();
        bool fighter = true;
        bool mage = false;

        int fireBoltAmount = 1;

        int healAmount = 1;
        sword sword;

    private: 
};

void player::heal(){
    int healAmount = diceRoll(healAmount,10);
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
            return false;
        }
    }else{
        return false;
    }
}

/*void player::weaponAttack(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = sword.getDamage();
        damage = -1*(damage+getStrength());
        cout << sword.getDamageText() << opponent.name << " dealing " << -damage << " damage." << endl;
        if(-damage >= opponent.getHealth()){
            opponent.setHealth(0);
            cout << "The " << opponent.name << "dies";
        }else{
            opponent.changeHealth(damage);
            cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << sword.getMissText();
    }
}*/

void player::fireBolt(creatureType& opponent){
    int savingRoll = opponent.savingRoll(opponent.getDexterity());
    if(savingRoll > 11){
        int damage = diceRoll(fireBoltAmount, 8);
        damage = -1*(damage);
        cout << "The fire bolt singes the " << opponent.name << "dealing " << -damage << "damage." << endl;
        if(damage > opponent.getHealth()){
            opponent.setHealth(0);
            cout << "The " << opponent.name << "dies";
        }else{
            opponent.changeHealth(damage);
            cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The fire misses." << endl;
    }
}

void player::levelUp(){
        if(fighter == true){
            sword.setDiceAmount(sword.getDiceAmount()+1);
        }else if(mage == true){
            fireBoltAmount ++;
        }
        
        //increasing 2 of player stats

        setMaxHealth(getMaxHealth()+15);
        initializeHealth();

        healAmount ++;
}

player::player(){
    name = "player";
    setMaxHealth(12);
    initializeHealth();
    setStrength(2);
    setLevel(1);
    setDefense(1);
    setDexterity(1);
    setWisdom(1);
    setCharisma(1);
    setConstitution(1);
    setIntelligence(1);
}

player::player(int strength, int dex, int intell, int wis, int cha, int con){
    setMaxHealth(12);
    initializeHealth();
    setStrength(strength);
    setLevel(1);
    setDefense(1);
    setDexterity(dex);
    setWisdom(wis);
    setCharisma(cha);
    setConstitution(con);
    setIntelligence(intell);
}

//a wolf enemy class
class wolf : public creatureType{
    public:
        wolf();
        void bite(creatureType& opponent);
}; 

void wolf::bite(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(2,4);
        cout << "The wolf lunges at the " << opponent.name << "biting them, dealing " << -damage << "damage." << endl;
        damage = -1*(damage+getStrength());
        if(damage > opponent.getHealth()){
            opponent.setHealth(0);
            cout << "The " << opponent.name << "dies";
        }else{
            opponent.changeHealth(damage);
            cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The wolf's attack miss the " << opponent.name << "."<<endl;
    }
    
}

wolf::wolf(){
    name = "wolf";
    setMaxHealth(11);
    initializeHealth();
    setStrength(1);
    setLevel(1);
    setDefense(1);
    setCharisma(-3);
    setDexterity(-2);
    setWisdom(-2);
    setIntelligence(-4);
    setConstitution(1);
}

class zombie: public creatureType{
    public:
        zombie();
        void slam(creatureType& opponent);
        void undeadFortitude();
};

zombie::zombie(){
    name = "zombie";
    setMaxHealth(22);
    initializeHealth();
    setStrength(1);
    setLevel(1);
    setDefense(8);
    setCharisma(-3);
    setDexterity(-2);
    setWisdom(-2);
    setIntelligence(-4);
    setConstitution(3);

}

void zombie::slam(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1,6);
        damage = -1*(damage+getStrength());
         cout << "The zombie bites the " << opponent.name << "dealing " << -damage << "damage." << endl;
        if(damage > opponent.getHealth()){
            opponent.setHealth(0);
            cout << "The " << opponent.name << "dies";
        }else{
            opponent.changeHealth(damage);
            cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The zombie misses." << endl;
    }
}

void zombie::undeadFortitude(){
    int reviveCheck = diceRoll(1,20);
    reviveCheck += savingRoll(getConstitution());
    if(reviveCheck > 10){
        cout << "The zombie revives, regaining 1 hit point." << endl;
        setHealth(1);
    }
}

class skeleton: public creatureType{
    public:
    skeleton();
    void weaponAttack(creatureType& opponent);
    sword sword;

};

/*void skeleton::weaponAttack(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = sword.getDamage();
        damage = -1*(damage+getStrength());
        cout << sword.getDamageText() << opponent.name << " dealing " << -damage << " damage." << endl;
        if(damage > opponent.getHealth()){
            opponent.setHealth(0);
            cout << "The " << opponent.name << " dies";
        }else{
            opponent.changeHealth(damage);
            cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << sword.getMissText();
    }
}*/

skeleton::skeleton(){
    name = "skeleton";
    setMaxHealth(13);
    initializeHealth();
    setStrength(0);
    setLevel(1);
    setDefense(13);
    setCharisma(-3);
    setDexterity(2);
    setWisdom(-1);
    setIntelligence(-2);
    setConstitution(2);
}

class dragon: public creatureType{
    public:
        int amountOfFireDice;
        int amountOfBiteDice;
        int amountOfClawDice;
        void fireBreath(creatureType& opponent);
        void bite(creatureType& opponent);
        void claw(creatureType& opponent);
};

void dragon::fireBreath(creatureType& opponent){
    int savingRoll = opponent.savingRoll(opponent.getDexterity());
    int damage = diceRoll(7, 6);
    if(savingRoll < 13){
        cout << "The " << opponent.name << " succeeds in dodging, reducing the damage of the breath attack." << endl;
        damage /= 2;
    }
    damage = -1*damage;
    cout << "The " << name << " exhales fire on the " << opponent.name << " dealing " << -damage << " damage." << endl;
    opponent.changeHealth(damage);
        if(-damage >= opponent.getHealth()){
            opponent.setHealth(0);
            cout << "The " << opponent.name << " dies";
        }else{
            cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
}

void dragon::bite(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1, 10);
        damage = -1*(damage+getStrength());
        cout << "The " << name << " lunges at the " << opponent.name << " biting them, dealing " << -damage << " damage." << endl;
        if(damage > opponent.getHealth()){
            opponent.setHealth(0);
            cout << "The " << opponent.name << "dies";
        }else{
            opponent.changeHealth(damage);
            cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The " << name << " bites the air."<<endl;
    }
}

void dragon::claw(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1, 6);
        damage = -1*(damage+getStrength());
        cout << "The " << name << " claws at the " << opponent.name << " slashing them, dealing " << -damage << " damage." << endl;
        if(damage > opponent.getHealth()){
            opponent.setHealth(0);
            cout << "The " << opponent.name << "dies";
        }else{
            opponent.changeHealth(damage);
            cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The " << name << " fails their attack."<<endl;
    }
}

class redDragonWyrm: public dragon{
    public:
        redDragonWyrm();
        int amountOfFireDice = 7;
        int amountOfClawDice = 1;
        int amountOfBiteDice = 1;
};

redDragonWyrm::redDragonWyrm(){
    name = "red dragon wyrmling";
    setMaxHealth(75);
    initializeHealth();
    setStrength(4);
    setLevel(1);
    setDefense(13);
    setCharisma(2);
    setDexterity(0);
    setWisdom(0);
    setIntelligence(1);
    setConstitution(3);
}

class goblin: public creatureType{
    public:
    goblin();
    scimitar scimitar;
};

goblin::goblin(){
    name = "goblin";
    setMaxHealth(7);
    initializeHealth();
    setStrength(-1);
    setLevel(1);
    setDefense(15);
    setCharisma(-1);
    setDexterity(2);
    setWisdom(-1);
    setIntelligence(0);
    setConstitution(0);
}

class goblinBoss: public goblin{
    public:
    goblinBoss();
    void multiattack();
};

goblinBoss::goblinBoss(){
    name = "goblin";
    setMaxHealth(21);
    initializeHealth();
    setStrength(0);
    setLevel(1);
    setDefense(17);
    setCharisma(-1);
    setDexterity(2);
    setWisdom(-1);
    setIntelligence(0);
    setConstitution(0);
}

void goblinBoss::multiattack(creatureType& opponent, weaponBase& weaponBase){
    weaponAttack(opponent, scimitar);
    int roll = diceRoll(1,20);
    if(roll>= opponent.getDefense()){
        weaponAttack(opponent, scimitar);
    }else{
        cout << weaponBase.getMissText;
    }
}


#endif