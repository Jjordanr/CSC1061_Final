//This header file holds a function that rolls a random amount of numbers added together
//the logic made by Mark Ardrey

#ifndef H_diceRoll
#define H_diceRoll

#include <ctime>
#include <iostream>

using namespace std;

int diceRoll(int diceAmount, int diceType)
{
  //sets up the time to be used as the seed
  //srand(time(0));

  int diceTotal = 0, diceRoll = 0;

  //'rolls' the dice by using a random number generator
  for (int i = 0; i < diceAmount; i++)
    {
      //random number generator, and adds the total to the total roll
      diceRoll = 1 + (rand() % diceType) ;
      //cout << diceRoll;
      diceTotal += diceRoll;
    }

    //cout << diceTotal;
  return diceTotal;
}

#endif