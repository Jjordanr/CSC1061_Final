//This header file will be used to define the classes of the creatures in the game.
// It uses an abstract creature class that holds the stats and logic for said class which each creature will then inherent. 
//Creatures using weapons attacks use composition having a weapon. 

//10/31/23 Joshua: today I added the stat modifier functionality, these are the ones that are added to rolls
//11/12/23 Joshua: today i added dice roll functionality to the attacks and added a max health stat
//11/15/23 Joshua: I finalized the wolf class today and the combat logic for the player like initiative and saving rolls
//11/17/23 Joshua; I added a zombie class, skeleton class, and typed out more of the weapons, adding a few of them for composition into the Player and Skeleton classes
//11/20/23 Joshua: I added the firebolt spell and added the logic for leveling up
//11/23/23 Joshua: I consolidated the weapon attack into the place player class, fixed some issues regarding getting the actual defense stats
//11/24/23 Joshua: I added a dragon child class and a goblin child class. These derived my functions and weapons for another dragon class and a goblin boss
//11/24/23 Joshua: I added some functionality to print a creatures stats
//11/25/23 Joshua: I added the classes of the Ape, Awakened Tree, Awakened Shrub and multiple others
//11/25/23 Joshua: For combat I added a creature logic function thats overrided by each subclass
//11/26/23 Joshua: Made some final touches, added a function that returns the creatures initiative and a boolean variable of whether the creature is alive



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

        //functions for getting and setting the characters stats

        int getCharisma();
        void setCharisma(int cha);

        int getDexterity();
        void setDexterity(int dex);

        int getWisdom();
        void setWisdom(int wis);

        int getIntelligence();
        void setIntelligence(int intell);

        int getConstitution();
        void setConstitution(int con);

        //this function returns a random number between 1 and 20 and adds a stat to the roll
        int savingRoll(int mod);

        //this stat rolls an initiative used to determine turn order
        int rollInitiative();

        int getInitiative();

        //a function that deals damage to a player based on a weapons stats

        void weaponAttack(creatureType& opponent, weaponBase& weaponBase);

        //the name of the object
        string name;

        //displays the stats of a creature
        void displayInfo();

        //
        virtual void creatureLogic(creatureType& opponent);

        int gold; //gold is used

        bool dead = false;
    private:
        int health;
        int level;
        int defense;
        int maxHealth;
        int initiative;

        int strength;
        int charisma;
        int dexterity;
        int wisdom;
        int intelligence;
        int constitution;

};
    //returns the current health
    int creatureType::getHealth(){
        return this->health;
    }

    

    //sets the current health to the max health
    void creatureType::initializeHealth(){
        this->health = this->maxHealth;
    }

    //changes the health by the given amount, if its greater then the max health it sets it to the max health
    void creatureType::changeHealth(int changeFactor){
        int tempHealth = getHealth();
        tempHealth += changeFactor;
        if(tempHealth > getMaxHealth()){
            initializeHealth();
        }else{
            setHealth(tempHealth);
        }
        
    }

    //sets the current health to the given integer
    void creatureType::setHealth(int hp){
        if(hp > getMaxHealth()){
            initializeHealth();
        }else{
            this->health = hp;
        }
    }

    //returns the max amount of health
    int creatureType::getMaxHealth(){
        return this->maxHealth;
    }

    //sets the max amount of health
    void creatureType::setMaxHealth(int hp){
        this->maxHealth = hp;
    }

    //returns the strength stat
    int creatureType::getStrength(){
        return this->strength;
    }

    //sets the strength stat
    void creatureType::setStrength(int str){
        this->strength = str;
    }

    //returns the current level
    int creatureType::getLevel(){
        return this->level;
    }

    //sets the current level
    void creatureType::setLevel(int lvl){
        this->level = lvl;
    }

    //gets the defense 
    int creatureType::getDefense(){
        return this->defense;
    }

    //sets the defense
    void creatureType::setDefense(int def){
        this->defense = def;
    }

    //gets the charisma stat
    int creatureType::getCharisma(){
        return this->charisma;
    }

    //sets the charisma stat
    void creatureType::setCharisma(int cha){
        this->charisma = cha;
    }

    //gets the dexterity stat
    int creatureType::getDexterity(){
        return this->dexterity;
    }

    //sets the dexterity stat
    void creatureType::setDexterity(int dex){
        this->dexterity = dex;
    }

    //gets the wisdom stat
    int creatureType::getWisdom(){
        return this->wisdom;
    }

    //sets the wisdom stat
    void creatureType::setWisdom(int wis){
        this->wisdom = wis;
    }

    //reutnrs the intelligence stat
    int creatureType::getIntelligence(){
        return this->intelligence;
    }

    //sets the intelligence stat
    void creatureType::setIntelligence(int intell){
        this->intelligence = intell;
    }

    //returns the constitution stat
    int creatureType::getConstitution(){
        return this->constitution;
    }

    //sets the constitution stat
    void creatureType::setConstitution(int con){
        this->constitution = con;
    }

    //returns a random number between 1 and 20 and adds the mod integer
    int creatureType::savingRoll(int mod){
        int roll = diceRoll(1,20);
        roll += mod;
        return roll;
    }

    //returns a number between 1 and 20 + the intiative stat
    int creatureType::rollInitiative(){
        int roll = diceRoll(1,20);
        roll += getDexterity();
        this->initiative = roll;
        cout << "The " << name << " rolled a " << roll << "." << endl;
        return roll;
    }

    //returns the creatures current initiative
    int creatureType::getInitiative(){
        return this->initiative;
    }

    //rolls a random number and if its higher then the other creature types defense then it deals damage
    void creatureType::unarmedAttack(creatureType& opponent){
        //rolls an attack check, plus the strength stat of the creature
        int attackCheck = diceRoll(1,20);
        attackCheck += getStrength()+3;
        cout << "A " << attackCheck << " was rolled." << endl;
        //if the attack roll is greater or equal to the opponent creatures defense it deals damage, otherwise it prints a miss
        if(attackCheck >= opponent.getDefense()){
            //calculates damage then changes the opponents health by the damage
            int damage = diceRoll(1,4);
            damage = -1*(damage+getStrength());
            cout << "The " << name << " hits " << opponent.name << " dealing " << -damage << " damage." << endl;
            //sets the health to 0 if the damage is greater then the current health, meaning the creature died
            opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
                
                //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
            }
        }
    }

    //the weapon attack is like unarmed attack instead it takes the stats of the weapon to deal damage
    //and prints its unique weapon miss and damage text
    void creatureType::weaponAttack(creatureType& opponent, weaponBase& weaponBase){
        int attackCheck = diceRoll(1,20);
        attackCheck += getStrength() + 3;
        cout << "A " << attackCheck << " was rolled." << endl;
        if(attackCheck >= opponent.getDefense()){
            int damage = weaponBase.getDamage();
            damage = -1*(damage+getStrength());
            cout << weaponBase.getDamageText() << opponent.name << " dealing " << -damage << " damage." << endl;
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
        }else{
            cout << weaponBase.getMissText();
        }
    }

    void creatureType::creatureLogic(creatureType& opponent){
        unarmedAttack(opponent);
    }

    //displays the stats of a creature
    void creatureType::displayInfo(){
        cout << "The " << name << " is level " << getLevel() << "." << endl;
        cout << "STATS" << endl;
        cout << "Health: " << getHealth() << endl;
        cout << "Def: " << getDefense() << endl;
        cout << "Str: " << getStrength() << endl;
        cout << "Dex: " << getDexterity() << endl;
        cout << "Con: " << getConstitution() << endl;
        cout << "Int: " << getIntelligence() << endl;
        cout << "Wis: " << getWisdom() << endl;
        cout << "Cha: " << getCharisma() << endl;
    }

//a beta player class used currently just for testing, the actual player would be in the main cpp file
//since it can be more easily manipulated
class player : public creatureType{
    public:
        
        player();
        //this constructor takes in integers to assign each stat in the player stat)
        player(int strength, int dex, int intell, int wis, int cha, int con);
        //void weaponAttack(creatureType& opponent);
        void fireBolt(creatureType& opponent);
        //heals the player
        void heal();
        //returns true if a player suceeds to run
        bool forfeit();
        //increases a players stats
        void levelUp();
        //these booleans determine the class of the player, used to determined whats leveled up and what abilities the players can use
        bool fighter;
        bool mage;

        void editInventory();
        void updateStats();
        void characterCreation();

        //determines the amount of dice rolled by the firebolt spell, increased by level up
        int fireBoltAmount = 1;

        //determines the amount of dice rolled by the healing potion
        int healAmount = 1;
        int healthPotions = 1;
        //the weapon the player has
        sword sword;

        int statPointsTotal = 2; //the player starts with one stat point.
        
        int specialty; //1 for mage, 2 for fighter
        string spell; //used if player has selected mage

    private: 
};

//this function heals a player by a random amount.
void player::heal(){
    int healAmount = diceRoll(healAmount,10);
    cout << "The player drinks a health potion, healing " << healAmount << " health" << endl;
    changeHealth(healAmount);
}

//this function returns true if a player suceeds a roll above a 4 or a false if they roll below a 4 or cancels the forfeit
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

//this function deals damage to a creature
void player::fireBolt(creatureType& opponent){
    //this gets a random number between 1 to 20 plus the opponents dexterity
    int savingRoll = opponent.savingRoll(opponent.getDexterity());
    //if the opponent creature rolls above an 11 it takes no damage, otherwise it takes a random amount,
    if(savingRoll <= 11){
        int damage = diceRoll(fireBoltAmount, 8);
        damage = -1*(damage);
        cout << "The fire bolt singes the " << opponent.name << " dealing " << -damage << "damage." << endl;
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The fire misses." << endl;
    }
}

void player::levelUp(){
        if(specialty == 2){
            sword.setDiceAmount(sword.getDiceAmount()+1);
        }else if(specialty == 1){
            fireBoltAmount ++;
        }
        setLevel(getLevel() + 1);
        //increasing 2 of player stats

        setMaxHealth(getMaxHealth()+15);
        initializeHealth();

        statPointsTotal += 2;
        healAmount ++;
}

player::player(){
    creatureType playerModify;

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
    setIntelligence(2);
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

void player::updateStats(){
  creatureType creatureModify; //player modify is used to edit the member variables of creatureType
  player playerEdit;
  bool correctAnswer = false;
  int answer;

  while (!correctAnswer)
    {
      cout << "1 to view current stats.\n2 to update stats.\n3 to exit.\nYou have ";
      if (playerEdit.statPointsTotal == 1)
        cout << playerEdit.statPointsTotal << " stat point left.\n";
      else
        cout << playerEdit.statPointsTotal << " stat points left.\n";
      cout << "Enter answer: ";
      cin >> answer;

      if (answer == 1)
        {
          cout << "\nStrength - " << playerEdit.getStrength()
               << "\n    Used for increasing melee attack damage."
               << "\nDexterity - " << playerEdit.getDexterity()
               << "\n    Used for dodging attacks."
               << "\nConstitution - " << playerEdit.getConstitution()
               << "\n    Used for increasing health and defense."
               << "\nIntelligence - " << playerEdit.getIntelligence()
               << "\n    Used for increasing spell attack damage."
               << "\nWisdom - " << playerEdit.getWisdom()
               << "\n    Used for increasing spell hit chance."
               << "\nCharisma - " << playerEdit.getCharisma()
               << "\n    Used for better prices, and better quests."
               << "\n\n";
        }
      else if (answer == 2)
        {
          cout << "\nCaution! All edits made to stat points are final.\nChoose wisely.\n";
          if (playerEdit.statPointsTotal > 0)
            {
              //updates the player's stats
              while (playerEdit.statPointsTotal > 0 && answer != 7)
                {
                  cout << "1 to upgrade strength.\n"
                       << "2 to upgrade dexterity.\n"
                       << "3 to upgrade constitution.\n"
                       << "4 to upgrade intelligence.\n"
                       << "5 to upgrade wisdom.\n"
                       << "6 to upgrade charisma.\n"
                       << "7 to exit.\n"
                       << "Enter answer: ";
                  cin >> answer;

                  if (answer == 1)
                    {
                      cout << "You have selected to upgrade strength.\n"
                           << "You feel vigor coursing through your veins.\n\n";
                      playerEdit.setStrength(playerEdit.getStrength() + 1);
                      playerEdit.statPointsTotal--;
                    }
                  else if (answer == 2)
                    {
                      cout << "You have selected to upgrade dexterity.\n"
                           << "You feel your reflexes get faster.\n\n";
                      playerEdit.setDexterity(playerEdit.getDexterity() + 1);
                      playerEdit.statPointsTotal--;
                    }
                  else if (answer == 3)
                    {
                      cout << "You have selected to upgrade constitution.\n"
                           << "You feel yourself get increasingly tough.\n\n";
                      playerEdit.setConstitution(playerEdit.getConstitution() + 1);
                      playerEdit.statPointsTotal--;
                    }
                  else if (answer == 4)
                    {
                      cout << "You have selected to upgrade intelligence.\n"
                           << "You feel as if you can read a hundred books.\n\n";
                      playerEdit.setIntelligence(playerEdit.getIntelligence() + 1);
                      playerEdit.statPointsTotal--;
                    }
                  else if (answer == 5)
                    {
                      cout << "You have selected to upgrade wisdom.\n"
                           << "You feel sage wisdom filling your mind.\n\n";
                      playerEdit.setWisdom(playerEdit.getWisdom() + 1);
                      playerEdit.statPointsTotal--;
                    }
                  else if (answer == 6)
                    {
                      cout << "You have selected to upgrade charisma.\n"
                           << "Your looks and speechcraft are immediately increased.\n\n";
                      playerEdit.setCharisma(playerEdit.getCharisma() + 1);
                      playerEdit.statPointsTotal--;
                    }
                  else if (answer == 7)
                    {
                      cout << "Exiting...\n\n";
                      continue;
                    }
                  else
                    {
                      cout << "Invalid response. Enter a correct response.\n\n";
                    }
                  if (playerEdit.statPointsTotal == 1)
                    cout << "You have " << playerEdit.statPointsTotal << " stat point left.\n";
                  else
                    cout << "You have " <<playerEdit.statPointsTotal << " stat points left.\n";
                }
              cout << "You have finished updating your skills.\n\n";
            }
          else
            cout << "You have no stat points to upgrade your skills.\n\n";
        }
      else if (answer == 3)
        {
          //exits the while loop
          correctAnswer = true;
        }
      else
        correctAnswer = false;
    }
}

void player::characterCreation()
{
  int answer;
  bool correctAnswer = false;

  //permits the player to select their class
  while (!correctAnswer)
    {
      cout << "1 for mage.\n2 for fighter.\nEnter answer: ";
      cin >> answer;

      if (answer == 1)
        {
          cout << "You have selected mage.\n";
          specialty = 1;
          correctAnswer = true;
        }
      else if (answer == 2)
        {
          cout << "You have selected fighter.\n";
          specialty = 2;
          correctAnswer = true;
        }
      else
        {
          cout << "Invalid answer, please try again.\n";
          correctAnswer = false;
        }
    }

  //determines stats
  cout << "\nYou are allowed to increase your base stats.\n";
  updateStats();

  if (specialty == 2)
    {
      cout << "\nAs a fighter you currently have a standard sword.\n"
           << "It currently has no special properties...\n"
           << "You also have access to standard heavy armor.\n\n";
      setHealth(14 + (getConstitution() * 2));
      setDefense(5 + getConstitution());
      //playerEdit.weapon = "Sword";
    }
  else if (specialty == 1)
    {
      cout << "\nAs a mage you have a spellbook with firebolt.\n"
           << "It is currently not a powerful spell...\n"
           << "You also have access to wizard robes. "
           << "Though they offer no protection in a fight, "
           << "they look dashing on you.\n\n";
      setHealth(8 + (getConstitution() * 2));
      setDefense(1 + getConstitution());
    }

  cout << "Now you are almost ready to adventure.\n"
       << "However, you require a name, adventurer.\n"
       << "Enter name: ";
  cin >> name;

  if (specialty == 1)
    cout << "Well, " << name << " the Mage, it appears now you are ready to adventure.\n";
  else if (specialty == 2)
    cout << "Well, " << name << " the Fighter, it appears now you are ready to adventure.\n";
}

//a wolf enemy class
class wolf : public creatureType{
    public:
        wolf();
        void bite(creatureType& opponent);
        void creatureLogic(creatureType& opponent);

}; 

void wolf::bite(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(2,4);
        cout << "The wolf lunges at the " << opponent.name << " biting them, dealing " << damage << " damage." << endl;
        damage = -1*(damage+getStrength());
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The wolf's attack miss the " << opponent.name << "."<<endl;
    }
    
}

void wolf::creatureLogic(creatureType& opponent){
    bite(opponent);
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
        void creatureLogic(creatureType& opponent);
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
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
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

void zombie::creatureLogic(creatureType& opponent){
    slam(opponent);
}

class skeleton: public creatureType{
    public:
    skeleton();
    //void weaponAttack(creatureType& opponent);
    sword sword;
    void creatureLogic(creatureType& opponent);
};

void skeleton::creatureLogic(creatureType& opponent){
    weaponAttack(opponent, sword);
}

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
        int rechargeTime;
        bool canBreath;
        void fireBreath(creatureType& opponent);
        void bite(creatureType& opponent);
        void claw(creatureType& opponent);
};

void dragon::fireBreath(creatureType& opponent){
    int savingRoll = opponent.savingRoll(opponent.getDexterity());
    int damage = diceRoll(amountOfFireDice, 6);
    if(savingRoll < 13){
        cout << "The " << opponent.name << " succeeds in dodging, reducing the damage of the breath attack." << endl;
        damage /= 2;
    }
    damage = -1*damage;
    cout << "The " << name << " exhales fire on the " << opponent.name << " dealing " << -damage << " damage." << endl;
    opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
}

void dragon::bite(creatureType& opponent){
    int attackCheck = diceRoll(amountOfBiteDice,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1, 10);
        damage = -1*(damage+getStrength());
        cout << "The " << name << " lunges at the " << opponent.name << " biting them, dealing " << -damage << " damage." << endl;
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The " << name << " bites the air."<<endl;
    }
}

void dragon::claw(creatureType& opponent){
    int attackCheck = diceRoll(amountOfClawDice,20);
    attackCheck += getStrength();
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1, 6);
        damage = -1*(damage+getStrength());
        cout << "The " << name << " claws at the " << opponent.name << " slashing them, dealing " << -damage << " damage." << endl;
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The " << name << " fails their attack."<<endl;
    }
}

class redDragonWyrm: public dragon{
    public:
        redDragonWyrm();
        void creatureLogic(creatureType& opponent);
        int amountOfFireDice = 7;
        int amountOfClawDice = 1;
        int amountOfBiteDice = 1;
};

void redDragonWyrm::creatureLogic(creatureType& opponent){
    if(canBreath == true){
        fireBreath(opponent);
        canBreath = false;
        rechargeTime++;
    }else if(rechargeTime % 5 == 0){
        canBreath = true;
        bite(opponent);
    }else{
        bite(opponent);
    }
}

redDragonWyrm::redDragonWyrm(){
    name = "red dragon wyrmling";
    canBreath = true;
    rechargeTime = 5;
    setMaxHealth(75);
    initializeHealth();
    setStrength(4);
    setLevel(4);
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
    void creatureLogic(creatureType& opponent);
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

void goblin::creatureLogic(creatureType& opponent){
    weaponAttack(opponent, scimitar);
}

class goblinBoss: public goblin{
    public:
    goblinBoss();
    void multiattack(creatureType& opponent, weaponBase& weaponBase);
    void creatureLogic(creatureType& opponent);
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
        cout << weaponBase.getMissText();
    }
}

void goblinBoss::creatureLogic(creatureType& opponent){
    multiattack(opponent, scimitar);
}

class ape: public creatureType{
    public:
        ape();
        void fistAttack(creatureType& opponent);
        void rock(creatureType& opponent);
        void creatureLogic(creatureType& opponent);
};

ape::ape(){
    name = "ape";
    setMaxHealth(19);
    initializeHealth();
    setLevel(1);
    setDefense(12);
    setStrength(3);
    setDexterity(2);
    setConstitution(2);
    setIntelligence(-2);
    setWisdom(1);
    setCharisma(-2);
}

void ape::fistAttack(creatureType& opponent){
    for(int i=0; i<2; i++){
        int attackCheck = diceRoll(1,20);
        attackCheck += getStrength()+2;
        if(attackCheck >= opponent.getDefense()){
            int damage = diceRoll(1,6);
            damage =-1*(damage +getStrength());
            cout << "The ape punches the " << opponent.name << " dealing " << -damage << " damage." << endl;
            opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
                opponent.changeHealth(damage);
                //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
            }
        }else{
            cout << "The ape misses their attack."<<endl;
        }
    }
}

void ape::rock(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength()+2;
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1,6);
        damage =-1*(damage +getStrength());
        cout << "The ape throws a rock at the " << opponent.name << " dealing " << -damage << " damage." << endl;
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
     }else{
        cout << "The rock misses it's target."<<endl;
    }
}

void ape::creatureLogic(creatureType& opponent){
    int attack = diceRoll(1,100);
    if(attack >= 50){
        fistAttack(opponent);
    }else{
        rock(opponent);
    }
}

class awakenedShrub: public creatureType{
    public:
        awakenedShrub();
        void rake(creatureType& opponent);
        void creatureLogic(creatureType& opponent);
};

awakenedShrub::awakenedShrub(){
    name = "awakened shrub";
    setMaxHealth(10);
    initializeHealth();
    setLevel(0);
    setDefense(9);
    setStrength(-4);
    setDexterity(-1);
    setConstitution(0);
    setIntelligence(0);
    setWisdom(0);
    setCharisma(-2);
}

void awakenedShrub::rake(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength()+2;
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1,4);
        damage =-1*(damage - 1);
        cout << "The shrub pokes the " << opponent.name << " dealing " << -damage << " damage." << endl;
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else if(damage == 0){
            cout << "The shrub's attack hits but " << opponent.name << " shrugs it off." << endl;
        }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The shrub misses their attack."<<endl;
    }
}

void awakenedShrub::creatureLogic(creatureType& opponent){
    rake(opponent);
}

class awakenedTree: public creatureType{
    public:
        awakenedTree();
        void slam(creatureType& opponent);
        void creatureLogic(creatureType& opponent);
};

awakenedTree::awakenedTree(){
    name = "awakened tree";
    setMaxHealth(59);
    initializeHealth();
    setLevel(2);
    setDefense(13);
    setStrength(4);
    setDexterity(-2);
    setConstitution(2);
    setIntelligence(0);
    setWisdom(0);
    setCharisma(-2);
}

void awakenedTree::slam(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength()+2;
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(3,6);
        damage =-1*(damage +getStrength());
        cout << "The tree slams its branch into the " << opponent.name << " dealing " << -damage << " damage." << endl;
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
     }else{
        cout << "The tree misses it's target."<<endl;
    }
}

void awakenedTree::creatureLogic(creatureType& opponent){
    slam(opponent);
}

class bear: public creatureType{
    public:
        void bite(creatureType& opponent);
        void claw(creatureType& opponent);
        void multiattack(creatureType& opponent);
        void creatureLogic(creatureType& opponent);
};


void bear::bite(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength()+1;
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1,6);
        damage =-1*(damage +getStrength());
        cout << "The bear gnaws on the " << opponent.name << " dealing " << -damage << " damage." << endl;
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
     }else{
        cout << "The bears bite misses."<<endl;
    }
}

void bear::claw(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength()+1;
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(2,4);
        damage =-1*(damage +getStrength());
        cout << "The bear claws at the " << opponent.name << " dealing " << -damage << " damage." << endl;
       opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
     }else{
        cout << "The bears swipe misses."<<endl;
    }
}

void bear::multiattack(creatureType& opponent){
    bite(opponent);
    claw(opponent);
}

void bear::creatureLogic(creatureType& opponent){
    multiattack(opponent);
}

class blackBear: public bear{
    public:
        blackBear();
};

blackBear::blackBear(){
    name = "black bear";
    setMaxHealth(19);
    initializeHealth();
    setLevel(1);
    setDefense(11);
    setStrength(2);
    setDexterity(0);
    setConstitution(2);
    setIntelligence(-4);
    setWisdom(1);
    setCharisma(-2);
}

class brownBear: public bear{
    public:
        brownBear();
};

brownBear::brownBear(){
    name = "brown bear";
    setMaxHealth(34);
    initializeHealth();
    setLevel(1);
    setDefense(11);
    setStrength(4);
    setDexterity(0);
    setConstitution(3);
    setIntelligence(-4);
    setWisdom(1);
    setCharisma(-2);
}

class crocodile: public creatureType{
    public:
        crocodile();
        void bite(creatureType& opponent);
        void creatureLogic(creatureType& opponent);
};

crocodile::crocodile(){
    name = "crocodile";
    setMaxHealth(19);
    initializeHealth();
    setLevel(1);
    setDefense(12);
    setStrength(2);
    setDexterity(0);
    setConstitution(1);
    setIntelligence(-4);
    setWisdom(0);
    setCharisma(-3);
}

void crocodile::bite(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength()+2;
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1,10);
        cout << "The crocodile lunges at the " << opponent.name << " biting them, dealing " << damage << " damage." << endl;
        damage = -1*(damage+getStrength());
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
    }else{
        cout << "The crocodile's attack miss the " << opponent.name << "."<<endl;
    }
    
}

void crocodile::creatureLogic(creatureType& opponent){
    bite(opponent);
}

class deathDog: public creatureType{
    public:
        deathDog();
        void bite(creatureType& opponent);
        void multiattack(creatureType& opponent);
        void creatureLogic(creatureType& opponent);
};

deathDog::deathDog(){
    name = "death dog";
    setMaxHealth(39);
    initializeHealth();
    setLevel(1);
    setDefense(12);
    setStrength(2);
    setDexterity(2);
    setConstitution(2);
    setIntelligence(-4);
    setWisdom(1);
    setCharisma(-2);
}

void deathDog::bite(creatureType& opponent){
    int attackCheck = diceRoll(1,20);
    attackCheck += getStrength()+2;
    if(attackCheck >= opponent.getDefense()){
        int damage = diceRoll(1,6);
        damage =-1*(damage +getStrength());
        cout << "The death dog gnaws on the " << opponent.name << " dealing " << -damage << " damage." << endl;
        opponent.changeHealth(damage);
            if(opponent.getHealth() <= 0){
                opponent.setHealth(0);
                cout << "The " << opponent.name << " dies." << endl;
                opponent.dead = true;
            }else{
            opponent.changeHealth(damage);
            //cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
        }
     }else{
        cout << "The death dogs bite misses."<<endl;
    }
}

void deathDog::multiattack(creatureType& opponent){
    bite(opponent);
    bite(opponent);
}

void deathDog::creatureLogic(creatureType& opponent){
    multiattack(opponent);
}

#endif