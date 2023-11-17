/*****************************************************************
Mark Ardrey and Joshua Rivera

Computer Science II (C++) CSC1062 2H1

CHANGELOG

27 October 2023 9:00 - Mark Ardrey
  Program CSC1061_Final_Ardrey.cpp created.
  Functions main and diceRoll are created.

11 November 2023 15:00 - Mark Ardrey
  Class item, and player created.
  Function character creation modified to work properly.
  Included .h file "creatures.h"
  Functions updateStats and playingOptions created.
 ****************************************************************/

#include <iostream>
#include <ctime>
#include "creatures.h"

using namespace std;

class invalidInput
{

};

class item
{
 public:
  //used for weapons or healing
  int dealDamage();
  int healDamage();
};

/*class player:creatureType
{
private:
  //gives 10 inventory slots
  int inventory[10];
  int specialty; //specialty represents the different class types. 1 for fighter, 2 for mage

public:
  //edits inventory
  void editInventory();
  int updateStats(int statPointsTotal);
  void characterCreation();
  };*/

int diceRoll(int diceAmount, int diceType);
int playingOptions();

//unfinished
//need to get the story in, and the actual game.
int main()
{
  //player playerEdit;

  //placeholder variables (many of these are already defined in creatures.h)
  int level = 1;
  int healthPoints;
  int armorClass;
  int dexterity, charisma, strength, wisdom, intelligence, constitution;
  int diceAmount, diceType;

  //answer is used for any answer that the player might encounter
  int answer = 0;

  //gets the player started with their character
  cout << "Welcome, player. Would you like to set up your own character, "
       << "or randomly generate one?\n1 to create your own character\n"
       << "2 to randomly generate yours.\nEnter answer:";
  //calls the function to create the character
  characterCreation();
  
}

int diceRoll(int diceAmount, int diceType)
{
  //sets up the time to be used as the seed
  srand(std::time(NULL));

  int diceTotal = 0, diceRoll = 0;

  //'rolls' the dice by using a random number generator
  for (int i = 0; i < diceAmount; i++)
    {
      //random number generator, and adds the total to the total roll
      diceRoll = 1 + std::rand() / ((RAND_MAX + 1u) / diceType);
      diceTotal += diceRoll;
    }
  return 0;
}

/*
//unfinished
void player::characterCreation()
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
      if (diceRoll(1, 2) == 1)
        cout << "Congratulations, you are a mage!\n";
      else
        cout << "Congratulations, you are a fighter!\n";
    }
  else
    {
      cout << "Error encountered: Invalid input.\n";
      throw invalidInput();
    }
}

//unfinished, still needs to be able to modify the player's stats, and need to work out
//  how to get the player to choose what they need.
void player::updateStats(int statPointsTotal)
{
  player playerEdit;
  bool correctAnswer = false;
  int answer;

  while (!correctAnswer)
    {
      cout << "1 to view current stats.\n2 to update stats.\n3 to exit.\nYou have "
           << statPointsTotal << " stat points left.\n";
      cin >> answer;

      if (answer == 1)
        {
          cout << "Strength - "
               << "\nDexterity - "
               << "\nConstitution - "
               << "\nIntelligence - "
               << "\nWisdom - "
               << "\nCharisma - "
               << '\n';
        }
      else if (answer == 2)
        {
          cout << "Caution! All edits made to stat points are final.\nChoose wisely.\n";
          while (statPointsTotal > 0)
            {

            }
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
*/
