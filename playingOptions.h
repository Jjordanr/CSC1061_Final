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

void encounters(creatureType& opponent)
{
  player playerEdit;
  playerCombatOptions(opponent, playerEdit);
}

void fight()
{
  player playerEdit;
  
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

//this will take user input to determine what they want to do in a turn of combat
void playerCombatOptions(creatureType& opponent, player player){
  bool hasTakenATurn = false;
  bool hasPlayerAttacked = false;
  string combatOption;
  do{
    cout << "What would you like to do. 1, check your opponents stats. " << endl;
    cout << "2, attack the chosen enemy." << endl;
    cout << "3, heal." << endl;
    cout << "4, run" << endl;
    cout << "What would you like to do: ";
    cin >> combatOption;
    if(combatOption == combatOption == "stats" || || combatOption == "STATS" || combatOption == "Stats"  || 
    combatOption == "1" || combatOption == "one" || combatOption == "One" || combatOption == "ONE"){
      opponent.displayInfo();
    }else if( combatOption == "2" || combatOption == "two" || combatOption == "Two" || combatOption == "TWO" || combatOption == "fight" ||
    combatOption == "FIGHT" || combatOption == "Fight" || combatOption == "attack" || combatOption == "atk" || combatOption == "ATK" || combatOption == "Atk"
    || combatOption == "Attack" || combatOption == "ATTACK"){
      string attackOption;
      if(player.specialty == 1){
        cout << "Would you like to attack it with a weapon or a fireball: ";
        cin >> attackOption;
        if(attackOption == "fire" || attackOption == "FIRE" || attackOption == "Fire" || attackOption == "firebolt" || attackOption == "fire bolt" ||
        attackOption == "Fire bolt" || attackOption == "Fire Bolt" || attackOption == "fire Bolt" || attackOption == "FIRE BOLT" || attackOption == "FIREBOLT" ||
        attackOption == "Firebolt"){
          player.fireBolt(opponent);
        }else{
          player.weaponAttack(opponent, player.sword);
        }
      }else{
          player.weaponAttack(opponent, player.sword);
      }
      hasTakenATurn = true;
    }else if( combatOption == "3" || combatOption == "three" || combatOption == "Three" || combatOption == "THREE" || combatOption == "heal"
    || combatOption == "Heal" || combatOption == "HEAL"){
        player.heal();
        hasTakenATurn = true;
    }else if(combatOption == "4" || combatOption == "four" || combatOption == "Four" || combatOption == "FOUR" || combatOption == "run"
    || combatOption == "Run" || combatOption == "RUN" || combatOption == "flee"|| combatOption == "Flee" || combatOption == "FLEE"
    || combatOption == "flee" || combatOption == "Flee" || combatOption == "FLEE"){
      hasPlayerSucceededForfeit = player.forfeit();
    }else{
      cout << "You have selected an invalid option. " << endl;
    }
  }while(hasPlayerSucceededForfeit == false && hasTakenATurn == false);
}
