/*
Changelog:

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
*/

#ifndef H_creatures
#define H_creatures

#include <iostream>
#include <string>

using namespace std;

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

class player:creatureType
{
public:
  //constructor player();
  void editInventory();
  int updateStats(int statPointsTotal);
  void characterCreation();
private:
  int inventory[10]; //the player has 10 inventory slots
  int specialty; //1 for mage, 2 for fighter
  //string spell; //used if player has selected mage
  int statPointsTotal;
};

//BEGINNING OF PLAYER FUNCTIONS

/*
  constructor definition
player::player(){
    setHealth(5);
    setStrength(2);
    setLevel(1);
    setDefense(1);

    }*/

//unfinished, still needs to be able to modify the player's stats, and need to work out
//  how to get the player to choose what they need.
void updateStats(int statPointsTotal)
{
  player playerEdit;
  bool correctAnswer = false;
  int answer;

  while (!correctAnswer)
    {
      cout << "1 to view current stats.\n2 to update stats.\n3 to exit.\nYou have "
           << statPointsTotal << " stat points left.\n";
      cout << "Enter answer: ";
      cin >> answer;

      if (answer == 1)
        {
          cout << "Strength - " << getStrength()
               << "\nDexterity - "
               << "\nConstitution - "
               << "\nIntelligence - "
               << "\nWisdom - "
               << "\nCharisma - "
               << "\n\n";
        }
      else if (answer == 2)
        {
          cout << "Caution! All edits made to stat points are final.\nChoose wisely.\n";
          if (statPointsTotal > 0)
            {
          //correctAnswer here is used to determine if the player wants to exit.
          while (statPointsTotal > 0 || correctAnswer == false)
            {
              cout << "1 to upgrade strength.\n"
                   << "2 to upgrade dexterity.\n"
                   << "3 to upgrade constitution.\n"
                   << "4 to upgrade intelligence.\n"
                   << "5 to upgrade wisdom.\n"
                   << "6 to upgrade charisma.\n"
                   << "7 to exit.\n";
                   << "Enter answer: ";
              cin >> answer;

              if (answer == 1)
                {

                }
              else if (answer == 2)
                {

                }
              else if (answer == 3)
                {

                }
              else if (answer == 4)
                {

                }
              else if (answer == 5)
                {

                }
              else if (answer == 6)
                {
                  cout << "You have selected to upgrade charisma.\n";
                  setCharisma(getCharisma() + 1);
                }
              else if (answer == 7)
                {
                  cout << "Exiting...\n";
                }
              else
                {
                  cout << "Invalid response. Enter a correct response.\n"
                }
            }
          cout << "You have finished updating your skills.\n";
            }
          else
            cout << "You have no stat points to upgrade your skills.\n";
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

//unfinished
void characterCreation()
{
  //defines an object player
  player playerEdit;
  int answer;
  bool correctAnswer = false;

  //player determines if they want to create their own, or to have a random one
  cout << "1 to create your own character\n"
       << "2 to randomly generate a character.\nEnter answer:";
  cin >> answer;

  if (answer == 1)
    {
      while (!correctAnswer)
        {
          cout << "Press 1 for mage, or 2 for fighter: ";
          cin >> answer;

          if (answer == 1)
            {
              cout << "You have selected mage.\n";
              correctAnswer = true;
            }
          else if (answer == 2)
            {
              cout << "You have selected fighter.\n";
              correctAnswer = true;
            }
          else
            {
              cout << "Invalid answer, please try again.\n";
              correctAnswer = false;
            }
        }

      //resets correctAnswer for the next question.
      correctAnswer = false;

      //determines stats
      cout << "You are allowed to increase your base stats.\n";
      updateStats(6);
    }

  //creates a random character
  else if (answer == 2)
    {
      //determines the player's class
      if (true)
        cout << "Congratulations, you are a mage!\n";
      else
        cout << "Congratulations, you are a fighter!\n";
    }
  else
    {
      cout << "Error encountered: Invalid input.\n";
    }
}

//END OF PLAYER FUNCTIONS

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
