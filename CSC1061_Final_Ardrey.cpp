/*****************************************************************
Mark Ardrey and Joshua Rivera

Computer Science II (C++) CSC1061 2H1

CHANGELOG

27 October 2023 9:00 - Mark Ardrey
  Program CSC1061_Final_Ardrey.cpp created.
  Functions main and diceRoll are created.

11 November 2023 15:00 - Mark Ardrey
  Class item, and player created.
  Function character creation modified to work properly.
  Included .h file "creatures.h"
  Functions updateStats and playingOptions created.

21 November 2023 19:00 - Mark Ardrey
  Updated main to better link into character creation used in creatures.h .

22 November 2023 9:30 - Mark Ardrey
  Class player derived from creatureType removed.
  Functions characterCreation and updateStats removed.
  Function playingOptions defined.
    - However, I do not believe that it is really working. Each action type
      should be defined in different functions, separately. This should be done
      because attacking would require more input variables than a dialogue option.

23 November 2023 8:30 - Mark Ardrey
  Removed the functions diceRoll and playingOptions.
    - These two functions are moved into their own .h files.

23 November 2023 9:30 - Mark Ardrey
  Added files diceRoll.h and playingOptions.h .

23 November 2023 16:00 - Mark Ardrey
  Added the opening.
 ****************************************************************/

#include <iostream>
#include <ctime>
#include "creatures.h"
#include "diceRoll.h"
#include "playingOptions.h"

using namespace std;

class invalidInput
{
  //class definition intentionally left blank
};

void errorOutput();

//unfinished
//need to get the story in, and the actual game.
int main()
{
  //answer is used for any answer that the player might encounter
  int answer = 0;

  player playerEdit;

  //gets the player started with their character
  cout << "Welcome, player. To get started, you will require a character.\n";
  cout << "First you will begin with selecting your class.\n\n";
  //calls the function to create the character
  characterCreation();

  //opening
  while (answer != 2)
    {
      cout << "\nYou wake up in the room of an inn you reserved the night before.";
      cout << "\nThere is a dresser, and a door.\n";
      cout << "1 to open the dresser.\n"
           << "2 to exit the room.\n"
           << "Enter answer: ";
      cin >> answer;
      if (answer == 1)
        {
          cout << "There is nothing of note in the dresser.\n";
        }
      else if (answer == 2)
        {
          cout << "You walk down the stairs into the main bar.\n";
        }
      else
        {
          errorOutput();
        }
    }
  cout << "The bartender is there, polishing shot glasses.\n"
       << "Aside from the bartender, there is a wounded soldier "
       << "polishing his sword.";

  //determines if the player wants to interact with the soldier or
  //  to exit the inn.
  while (answer != 3)
    {
      cout << "\n\n1 to talk with the bartender."
           << "2 to talk with the wounded soldier."
           << "\n3 to exit the inn."
           << "Enter answer: ";
      cin >> answer;

      if (answer == 1)
        {
          cout << "[Bartender]: Good morning, and hello again.";
        }
      else if (answer == 2)
        {
          //used to speak with the soldier.
          cout << "As you walk up closer to the man, you can start to clearly make "
               << "out his wounds. He has bandages wrapped around his leg."
               << "\n[Wounded Soldier]: Hello there.";

          cout << '[' << playerEdit.name << "]: Hello.";

          cout << "\n[Wounded Soldier]: I can tell from your gear that you are "
               << "an adventurer."
               << "\nI used to be an adventurer like you, until I took an arrow "
               << "to the knee.";

          cout << "\n\n[Wounded Soldier]: Anyways, without me to protect the town, I need you to delve "
               << "into the forest to defeat potential threats.\n"
               << "[Wounded Soldier]:You look tough enough to handle it."
               << "\n\tDo you accept?"
               << "\n1 to accept.\n2 to decline.\nEnter answer: ";
          cin >> answer;
          while (answer != 1)
            {
              if (answer == 1)
                {
                  cout << "\n[Wounded Soldier]: Thank you, the town and myself are grateful for your kindness.";
                }
              else if (answer == 2)
                {
                  cout << "\n[Wounded Soldier]: Alas, not everyone has the fighting spirit. I hope you find safe travels.";
                }
              else
                {
                  cout << "[Wounded Soldier]: I don't understand what you are saying."
                       << "\n[Wounded Soldier]: Do you accept? ";
                }
            }
        }
      else if (answer == 3)
        {
          cout << "\nAs you exit the inn, you find yourself in a small town."
               << "\nMost of the doors are locked however, as people "
               << "do not take kindly to strangers walking into their house."
               << "\n\nHowever, there are three places that are not unlocked.";
        }
      else
        {
          errorOutput();
        }
    }
  
}

void errorOutput()
{
  cout << "Invalid answer. Enter correct answer.\n";
}
