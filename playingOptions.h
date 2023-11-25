/*****************************************************************
Mark Ardrey and Joshua Rivera

Computer Science II (C++) CSC1061 2H1

CHANGELOG

23 November 2023 8:30 - Mark Ardrey
  Added playingOptions class.
  Added functions talk, attack, selectQuest, and openMenu.

24 November 2023 18:30 - Mark Ardrey
  Removed playingOptions class.
  Removed functions talk and attack.
  Defined function openMenu.

25 November 2023 00:00 - Mark Ardrey
  Added functions encounters, fight, and randomForestDialogue.
  Defined function randomForestDialogue.
 ****************************************************************/

#include <iostream>
#include <ctime>
#include "creatures.h"

using namespace std;

int selectQuest()
{
  return -1;
}

void openMenu()
{
  player playerEdit;
  int answer = 0;
  while (answer != 4)
    {
      cout << "\nMENU:\n"
           << "You are currently level " << playerEdit.getLevel() << ".\n"
           << "You have " << playerEdit.getHealth() << " health.\n"
           << "You have " << playerEdit.getDefense() << " defense.\n"
           << "1 to update your stats.\n"
           << "2 to use healing. You currently have ";
      if (playerEdit.healthPotions == 1)
        cout << playerEdit.healthPotions << " healing potion remaining.\n";
      else
        cout << playerEdit.healthPotions << " healing potions remaining.\n";
      cout << "3 to open inventory.\n"
           << "4 to exit.\n"
           << "Enter answer: ";
      cin >> answer;
      if (answer == 1)
        {
          updateStats();
        }
      else if (answer == 2)
        {
          if (playerEdit.healthPotions > 0)
            {
              cout << "\nAs you drink the health potion, you feel yourself revitalized.\n";
              int healingFactor = diceRoll(1, 8) + 2;
              playerEdit.setHealth(playerEdit.getHealth() + healingFactor);
              cout << "You have regained " << healingFactor << " health.\n"
                   << "You are now at " << playerEdit.getHealth() << " health.\n";
            }
          else
            {
              cout << "\nYou have no healing potions left."
                   << "\nReplenish your stock soon.";
            }
        }
      else if (answer == 3)
        {
          if (playerEdit.specialty == 1)
            {
              cout << "\nYou have a mage's robe, and a spellbook.\n";
            }
          else if (playerEdit.specialty == 2)
            {
              cout << "\nYou have plate armor and a sword.\n";
            }
        }
      else if (answer == 4)
        {
          cout << "Exiting...";
          continue;
        }
      else
        {
          cout << "Invalid answer. Enter a valid answer.\n";
        }
    }
}

void encounters()
{
  player playerEdit;
}

void fight()
{
  player playerEdit;
  while (playerEdit.
}

void randomForestDialogue()
{
  int temp = diceRoll(1, 4);

  if (temp == 1)
    cout << "\nThe very air itself becomes compressing, making it harder to breathe.\n";
  else if (temp == 2)
    cout << "\nThere appears to be a shadow looming over you. Or is that a tree?\n";
  else if (temp == 3)
    cout << "\nThe forest starts to get calmer and quieter. Wait, what are those moving shapes and shadows in the brush?\n";
  else if (temp == 4)
    cout << "\nThe leaves overhead from the trees start to obscure the sun even more. You find it hard to see where you are going. Plus, there seems to be a lot of crunching underneath your feet.\n";
}
