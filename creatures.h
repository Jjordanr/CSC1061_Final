/*
Mark Ardrey and Joshua Rivera

Computer Science II (C++) CSC1061 2H1

CHANGELOG

10/31/23: today I added the stat modifier functionality, these are the ones that are added to rolls

11 November 2023 16:00 - Mark Ardrey
  Commented out the player class to define it in the main program
    for easier manipulation.
    (Note: may re-define player in this file instead, to streamline main.)

15 November 2023 14:00 - Mark Ardrey
  Uncommented out the player class, and added functions updateStats
    and characterCreation.
  Modified updateStats to function as intended.

16 November 2023 23:00 - Mark Ardrey
  Almost completed characterCreation except for the randomly generated character.
  Might delete randomly generating a character and instead force the player
    to make their own.

17 November 2023 22:20 - Mark Ardrey
  Defined the player constructor.

21 November 2023 18:30 - Mark Ardrey
  Redefined the player constructor.
    - Removed the playerEdit object in player constructor.
  The updateStats function now works as intended.
  The characterCreation function now works as intended.
  Commented out the stats modifiers.
    - These should be useless, as we could probably simplify the process
      by just using the base stats as the modifier value.
  Begun working on the main file.

23 November 2023 10:00 - Mark Ardrey
  Edited the characterCreation and updateStats functions to make it more
    user friendly.

23 November 2023 20:00 - Mark Ardrey
  Removed inventory.
  Added integer variable gold to creatureType.
    - If the player defeats a monster, they recieve their gold amount.
  Added string variable weapon to player.
    - It should just be used to determine what their weapon is in text.

25 November 2023 1:00 - Mark Ardrey
  Integrated stuff done by Joshua into the file.
*/

#ifndef H_creatures
#define H_creatures

#include <iostream>
#include <string>
#include <iomanip>
#include "diceRoll.h"
#include "weapons.h"

using namespace std;

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

        int getIntelligence();
        void setIntelligence(int intell);

        int getConstitution();
        void setConstitution(int con);

        int savingRoll(int mod);
        int initiative();

        void weaponAttack(creatureType& opponent, weaponBase& weaponBase);

        string name;

        int gold; //gold is used

  /*
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
  */
    private:
        int health;
        int level;
        int defense;
        int maxHealth;

        int strength;
        int charisma; //maybe get rid of charisma
        int dexterity; //maybe get rid of dexterity
        int wisdom; //maybe get rid of wisdom
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
        return this->defense;
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

    int creatureType::getIntelligence(){
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

class player : public creatureType
{
public:
  //constructor
  player();
  void editInventory();
  int updateStats();
  void characterCreation();
  void fireBolt(creatureType& opponent);
  void heal();
  bool forfeit();
  void levelUp();

  int fireBoltAmount = 1;
  int healAmount = 1;
  sword swordWeapon;

  int statPointsTotal = 2; //the player starts with one stat point.
  int healthPotions = 1;
  string weapon;
  int specialty; //1 for mage, 2 for fighter
  string spell; //used if player has selected mage
};

//BEGINNING OF PLAYER FUNCTIONS

//constructor definition
player::player(){
  creatureType playerModify;

  //sets each base stat that the player might use
  setHealth(5);
  setStrength(1);
  setDexterity(1);
  setConstitution(1);
  setWisdom(1);
  setIntelligence(1);
  setCharisma(1);
  setLevel(1);
  setDefense(1);
}

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
        if(specialty == 1){
            swordWeapon.setDiceAmount(swordWeapon.getDiceAmount()+1);
        }else if(specialty == 2){
            fireBoltAmount ++;
        }

        //increasing 2 of player stats

        setMaxHealth(getMaxHealth()+15);
        initializeHealth();

        healAmount ++;
}

//finished
void updateStats()
{
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

//almost finished, have to figure out why the program exits after executing updateStats()
void characterCreation()
{
  //defines an object player
  player playerEdit;
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
          playerEdit.specialty = 1;
          correctAnswer = true;
        }
      else if (answer == 2)
        {
          cout << "You have selected fighter.\n";
          playerEdit.specialty = 2;
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

  if (playerEdit.specialty == 2)
    {
      cout << "\nAs a fighter you currently have a standard sword.\n"
           << "It currently has no special properties...\n"
           << "You also have access to standard heavy armor.\n\n";
      playerEdit.setHealth(14 + (playerEdit.getConstitution() * 2));
      playerEdit.setDefense(5 + playerEdit.getConstitution());
      playerEdit.weapon = "Sword";
    }
  else if (playerEdit.specialty == 1)
    {
      cout << "\nAs a mage you have a spellbook with firebolt.\n"
           << "It is currently not a powerful spell...\n"
           << "You also have access to wizard robes. "
           << "Though they offer no protection in a fight, "
           << "they look dashing on you.\n\n";
      playerEdit.setHealth(8 + (playerEdit.getConstitution() * 2));
      playerEdit.setDefense(1 + playerEdit.getConstitution());
    }

  cout << "Now you are almost ready to adventure.\n"
       << "However, you require a name, adventurer.\n"
       << "Enter name: ";
  cin >> playerEdit.name;

  if (playerEdit.specialty == 1)
    cout << "Well, " << playerEdit.name << " the Mage, it appears now you are ready to adventure.\n";
  else if (playerEdit.specialty == 2)
    cout << "Well, " << playerEdit.name << " the Fighter, it appears now you are ready to adventure.\n";
}

//END OF PLAYER FUNCTIONS

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

//a zombie enemy class
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

//this kicks in when the zombie is reduced to zero hit points
void zombie::undeadFortitude(){
    int reviveCheck = diceRoll(1,20);
    reviveCheck += savingRoll(getConstitution());
    if(reviveCheck > 10){
        cout << "The zombie revives, regaining 1 hit point." << endl;
        setHealth(1);
    }
}

//a skeleton enemy class
class skeleton: public creatureType{
    public:
    skeleton();
    void weaponAttack(creatureType& opponent);
    sword swordWeapon;

};

void skeleton::weaponAttack(creatureType& opponent){
  sword swordWeapon;
  int attackCheck = diceRoll(1,20);
  attackCheck += getStrength();
  if(attackCheck >= opponent.getDefense()){
    int damage = swordWeapon.getDamage();
    damage = -1*(damage+getStrength());
    cout << swordWeapon.getDamageText() << opponent.name << " dealing " << -damage << " damage." << endl;
    if(damage > opponent.getHealth()){
      opponent.setHealth(0);
      cout << "The " << opponent.name << " dies";
    }else{
      opponent.changeHealth(damage);
      cout << "The " << opponent.name << " has " << opponent.getHealth() << " health left." << endl;
    }
  }else{
    cout << swordWeapon.getMissText();
  }
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
    scimitar scimitarWeapon;
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
  void multiattack(creatureType& opponent, weaponBase& weaponBase);
};

/*
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
*/


#endif
