#ifndef H_diceRoll
#define H_diceRoll

#include <ctime>
#include <iostream>

int diceRoll(int diceAmount, int diceType)
{
  //sets up the time to be used as the seed
  srand(std::time(NULL));

  int diceTotal = 0, diceRoll = 0;

  //'rolls' the dice by using a random number generator
  for (int i = 0; i < diceAmount; i++)
    {
      //random number generator, and adds the total to the total roll
      diceRoll = 1 + (std::rand() % diceType) ;
      diceTotal += diceRoll;
    }

  return diceTotal;
}

#endif