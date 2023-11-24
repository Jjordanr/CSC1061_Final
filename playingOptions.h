/*****************************************************************
Mark Ardrey and Joshua Rivera

Computer Science II (C++) CSC1061 2H1

CHANGELOG

23 November 2023 8:30 - Mark Ardrey
  Added playingOptions class.
  Added functions talk, attack, selectQuest, and openMenu.
 ****************************************************************/

#include <iostream>
#include <ctime>
#include "creatures.h"

using namespace std;

class playingOptions
{
 public:
  string talk(); //returns a string to 'talk'
  int attack(); //returns a damage value, or -1 if the hit was unsuccessful
  int selectQuest();
  void openMenu();
 private:
  //private intentionally left blank
};

string talk()
{
  return "failure";
}

int attack()
{
  return -1;
}

int selectQuest()
{
  return -1;
}

void openMenu()
{
  player playerEdit;
  int answer = -1;
  while (answer != -1)
    {
      cout << "MENU:\n"
           << "You are currently level " << playerEdit.getLevel() << ".\n"
           << "You have " << playerEdit.getHealth() << " health.\n"
           << "You have " << playerEdit.getDefense() << " defense.\n"
           << "1 to update your stats.\n"
           << "2 to use healing.\n"
           << "3 to open inventory.\n"
           << "4 to exit.\n"
           << "Enter answer: ";
      cin >> answer;
      if (answer == 1)
        {
          updateStats();
        }
      else if (answer == 2)
        {
          //will update when healing is added
        }
      else if (answer == 3)
        {
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
