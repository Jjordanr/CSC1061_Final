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
  Added function errorOutput.

23 November 2023 16:00 - Mark Ardrey
  Added the opening.

24 November 2023 10:00 - Mark Ardrey
  Finished the inn encounter opening, and the town menu.

24 November 2023 13:00 - Mark Ardrey
  Added class arenas.
  Added functions inn and forest.
  Keeps most of the program in a while loop, until termination.

24 November 2023 23:00 - Mark Ardrey
  Defined function forest.
  Fixed logic in function inn.

25 November 2023 19:00 - Mark Ardrey
  Redefined functions inn and forest.
  Added function blacksmith.

26 November 2023 - Joshua Rivera
  made some last minute changes, added the random encounters and boss fights
  and the win condition
 ****************************************************************/

#include <iostream>
#include <ctime>
#include "creatures.h"
#include "weapons.h"
#include "diceRoll.h"
#include "playingOptions.h"

using namespace std;

class invalidInput
{
  //class definition intentionally left blank
};

  

class arenas
{
public:
  //used to determine if the player has already spoken to these characters
  bool knownBartender = false;
  bool knownSoldier = false;
  bool knownBlacksmith = false;
  bool acceptedSoldier = false;
  bool questCompleted = false;
  bool enteredForest = false;

  

  void inn(player& playerEdit);
  void inn(bool knownForest, player& playerEdit); //used to overload inn
  void forest(player& playerEdit);
  void blacksmith();
};

void errorOutput();

bool wolfDead = false;
  bool goblinBossDead = false;
  bool dragonWyrmDead = false;
  bool playerDead = false;

//unfinished
//need to get the story in, and the actual game.
int main()
{
  srand(time(NULL));
  //answer is used for any answer that the player might encounter
  int answer = 0;

  player playerEdit;
  arenas playingAreas;
  
  cout << diceRoll(1,20) << " " << diceRoll(1,20)<< " " << diceRoll(1,20) << " " << diceRoll(1,20) << endl;

  //openMenu();

  //gets the player started with their character
  cout << "Welcome, player. To get started, you will require a character.\n";
  cout << "First you will begin with selecting your class.\n\n";
  //calls the function to create the character
  playerEdit.characterCreation();

  //playingAreas.forest();

  //opening
  while (answer != 3)
    {
      cout << "\nYou wake up in the room of an inn you reserved the night before.";
      cout << "\nThere is a dresser, and a door.\n";
      cout << "1 to open the dresser.\n"
           << "2 to open the menu.\n"
           << "3 to exit the room.\n"
           << "Enter answer: ";
      cin >> answer;
      if (answer == 1)
        {
          cout << "There is nothing of note in the dresser.\n";
        }
      else if (answer == 2)
        {
          openMenu(playerEdit);
        }
      else if (answer == 3)
        {
          cout << "You walk down the stairs into the main bar.\n";
        }
      else
        {
          errorOutput();
        }
    }
  playingAreas.inn(playerEdit);

  //used for when the player is outside of the town.
  while (answer != -1)
    {
      if(playerDead == true){
        break;
      }else if(wolfDead == true && goblinBossDead == true && dragonWyrmDead == true){
        break;
      }
      cout << "\n1 to enter the inn."
           << "\n2 to enter the forest."
           << "\n3 to open the menu."
           << "\nEnter answer: ";
      cin >> answer;
      if (answer == 1)
        playingAreas.inn(playingAreas.enteredForest, playerEdit);
      else if (answer == 2)
        playingAreas.forest(playerEdit);
      else if (answer == 3)
        openMenu(playerEdit);
    }
  if(playerDead == true){
    cout << endl << "You died, failing to save the small town." << endl;
  }else{
    cout << endl << "Congrats you won and saved the vilage." << endl;
  }
  
}

void errorOutput()
{
  cout << "Invalid answer. Enter correct answer.\n";
}

void arenas::inn(player& playerEdit)
{
  //player playerEdit;
  arenas innArea;
  int answer;

    cout << "The bartender is there, cleaning shot glasses.\n"
       << "Aside from the bartender, there is a wounded soldier "
       << "polishing his sword.";

  //determines if the player wants to interact with the soldier or
  //  to exit the inn.
  while (answer != 4)
    {
      cout << "\n\n1 to talk with the bartender."
           << "\n2 to talk with the wounded soldier."
           << "\n3 to enter the room."
           << "\n4 to exit the inn."
           << "\nEnter answer: ";
      cin >> answer;

      if (answer == 1)
        {
          if (!innArea.knownBartender)
            {
              cout << "\n[Bartender]: Good morning, and hello again.";
              cout << "\n[Bartender]: Sorry, the bar is currently closed for the morning."
                   << "\n[Bartender]: You can come by after noon to get some ales "
                   << "if you desire."
                   << "\n[Bartender]: In the meantime, I suggest you talk to the soldier in the corner there.";
              innArea.knownBartender = true;
            }
          else if (innArea.knownBartender == true)
            {
              cout << "\n[Bartender]: I'm sorry, I still don't have any ales for sale yet. Come back after noon for those.";
            }
        }
      else if (answer == 2)
        {
          //used to speak with the soldier.
          if (!innArea.acceptedSoldier && !innArea.knownSoldier)
            {
              innArea.knownSoldier = true;
              cout << "\nAs you walk up closer to the man, you can start to clearly make "
                   << "out his wounds. He has bandages wrapped around his leg."
                   << "\n[Wounded Soldier]: Hello there.";

              cout << "\n[Wounded Soldier]: I can tell from your gear that you are "
                   << "an adventurer."
                   << "\n[Wounded Soldier]: I used to be an adventurer like you, until I took an arrow to the knee.";

              cout << "\n\n[Wounded Soldier]: Anyways, without me to protect the town, I need you to delve "
                   << "into the forest to defeat potential threats.\n"
                   << "[Wounded Soldier]: You look tough enough to handle it."
                   << " Do you accept?";
              answer = 0;
              while (answer != 1 && answer != 2)
                {
                  cout << "\n1 to accept.\n2 to decline.\nEnter answer: ";
                  cin >> answer;
                  if (answer == 1)
                    {
                      cout << "\n[Wounded Soldier]: Thank you, the town and myself are grateful for your kindness.";
                      cout << "\n[Wounded Soldier]: You may take your time on this, but there are reports of a wolf out there terrorizing farms. I would ask you to go deal with it.";
                      cout << "\n[Wounded Soldier]: The forest is also a very easy place to get lost. I recommend you take notes on where you are going.";
                      innArea.acceptedSoldier = true;
                    }
                  else if (answer == 2)
                    {
                      cout << "\n[Wounded Soldier]: Alas, not everyone has the fighting spirit. I hope you find safe travels.";
                      innArea.acceptedSoldier = false;
                    }
                  else
                    {
                      cout << "[Wounded Soldier]: I don't understand what you are saying."
                           << "\n[Wounded Soldier]: Do you accept? ";
                    }
                }
            }
          else if (!innArea.acceptedSoldier && innArea.knownSoldier == true)
            {
              cout << "\n[Wounded Soldier]: Have you changed your mind?";
              answer = 0;
              while (answer != 1 && answer != 2)
                {
                  cout << "\n1 to accept.\n2 to decline.\nEnter answer: ";
                  cin >> answer;
                  if (answer == 1)
                    {


                      cout << "\n[Wounded Soldier]: Thank you, the town and myself are grateful for your kindness.";
                      cout << "\n[Wounded Soldier]: You may take your time on this, but there are reports of a wolf out there terrorizing farms. I would ask you to go deal with it.";
                      innArea.acceptedSoldier = true;
                    }
                  else if (answer == 2)
                    {
                      cout << "\n[Wounded Soldier]: You have every right to not want to go on these quests."
                           << "\n[Wounded Soldier]: Safe travels.";
                      innArea.acceptedSoldier = false;
                    }
                  else
                    {
                      cout << "[Wounded Soldier]: I don't understand what you are saying."
                           << "\n[Wounded Soldier]: Do you accept?";
                    }
                }
            }
          else if (innArea.acceptedSoldier == true && innArea.knownSoldier == true)
            {
              cout << "\n[Wounded Soldier]: The town, and myself especially, are grateful for your kind mercy."
                   << "\n[Wounded Soldier]: However, time is ticking, the wolf is still on the loose.";
            }
        }
      else if (answer == 3)
        {
          openMenu(playerEdit);
        }
      else if (answer == 4)
        {
          cout << "\nAs you exit the inn, you find yourself in a small town."
               << "\nMost of the doors are locked however, as people "
               << "do not take kindly to strangers walking into their house."
               << "\n\nThough, there are two places that are not unlocked.";
        }
      else
        {
          errorOutput();
        }
    }
}

void arenas::inn(bool knownForest, player& playerEdit){
  //player playerEdit;
  arenas innArea;
  int answer = 0;
  if (knownForest == false)
    innArea.inn(playerEdit);

  else
    {
      while (answer != 4)
        {
          cout << "\n\n1 to talk with the bartender."
               << "\n2 to talk with the wounded soldier."
               << "\n3 to enter the room."
               << "\n4 to exit the inn."
               << "\nEnter answer: ";
          cin >> answer;

          if (answer == 1)
            {

            }

          else if (answer == 2)
            {

            }

          else if (answer == 3)
            {
              cout << "\nYou head up to your reserved room.";
              answer = 0;
              while (answer != 2)
                {
                  cout  << "\n1 to sleep in the bed."
                        << "\n2 to exit the room."
                        << "\nEnter answer: ";
                  cin >> answer;

                  if (answer == 1)
                    {
                      
                    }

                  else if (answer == 2)
                    {

                    }
                }
            }

          else if (answer == 4)
            {
              cout << "\nYou exit the inn, into the fresh air of the town.\n";
            }
    }
}
}

void arenas::forest(player& playerEdit){
  //player playerEdit;
  arenas area;
  int lengthOfVenture = 1; //lengthOfVenture is used to determine how far the player has to go back to return to the town
  int facing = 1; //facing is used to determine where the player is headed in the forest.
              //1 for away from the town, 2 for towards the town.
  int answer = 0;

  

  area.enteredForest = true;

  cout << "\nAs you head into the forest, it starts getting darker, as the leaves "
       << "block out the sun."
       << "\nYou feel an unsettling chill settle down across your spine.";
  while (lengthOfVenture > 0)
    {
      cout << "\n\n1 to continue deeper."
           << "\n2 to turn around."
           << "\nEnter answer: ";
      cin >> answer;
 
      if (answer == 1)
        {
          randomForestDialogue();

          //determines how far the player moves
          if (facing == 1){
            lengthOfVenture ++; 
          }
          else if (facing == 2){
            lengthOfVenture --;
          }
          cout << lengthOfVenture << '\n';
        }
      else if (answer == 2)
        {
          cout << "\nYou turn around, however it is hard to determine if you truly turned around.\n";
          if (facing == 1)
            facing = 2;
          else if (facing == 2)
            facing = 1;
        }
      else
        {
          errorOutput();
        }

      if(lengthOfVenture>=8 && lengthOfVenture<=11 && wolfDead == false){
        cout << "The player encounters a wolf, one of the targets." << endl;
        wolf wolf;
        playerDead = fight(wolf, playerEdit);
        if(playerDead == false){
          wolfDead = true;
          playerEdit.levelUp();
        }
      }else if(lengthOfVenture>=15 && lengthOfVenture<=18 && goblinBossDead == false){
        cout << "The player encounters the goblin boss, one of the targets." << endl;
        goblinBoss goblinBoss;
        playerDead = fight(goblinBoss, playerEdit);
        if(playerDead == false){
          goblinBossDead = true;
        }
      }else if(lengthOfVenture>=21 && lengthOfVenture<=24 && dragonWyrmDead == false){
        cout << "The player encounters the goblin boss, one of the targets." << endl;
        redDragonWyrm dragonWyrm;
        playerDead = fight(dragonWyrm, playerEdit);
        if(playerDead == false){
          dragonWyrmDead = true;
        }
      }else{
        encounters(playerEdit);
        playerDead = playerEdit.dead;
      }

      if(playerDead==true){
        lengthOfVenture =-1;
      }else if(wolfDead == true && goblinBossDead == true && dragonWyrmDead == true){
        lengthOfVenture =-1;
        cout << endl << "The player heads back, having slayed each of their targets." << endl;
      }
      //used to determine if the player encounters an enemy
      //encounters();
    }
}
