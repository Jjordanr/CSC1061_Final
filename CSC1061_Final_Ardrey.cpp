/*****************************************************************
Mark Ardrey and Joshua Rivera

Computer Science II (C++) CSC1062 2H1

CHANGELOG

27 October 2023 9:00am - Mark Ardrey
  Program CSC1061_Final_Ardrey.cpp created.
  Functions main and diceRoll are created.
 ****************************************************************/

#include <iostream>
#include <ctime>

using namespace std;

//class inventory
class invalidInput
{};
class player
{};

int diceRoll(int diceAmount, int diceType);
void characterCreation();
int playingOptions();

int main()
{
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

  return diceTotal;
}

void characterCreation()
{
  int answer;

  cout << "1 to create your own character\n"
       << "2 to randomly generate yours.\nEnter answer:";
  cin >> answer;

  if (answer == 1)
    {
      
    }
  else if (answer == 2)
    {
      //determines the player's class
      if (diceRoll(1, 2) == 1)
        cout << diceRoll(1, 2);
    }
  else
    {
      cout << "Error encountered: Invalid input.\n";
      throw invalidInput();
    }
}
