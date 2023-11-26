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

25 November 2023 22:00 - Mark Ardrey
  Defined function encounters and fighting.
    - Unfinished.

26 November 2023 1:00 - Mark Ardrey & Joshua Rivera
  Finished function fighting and encounters.
 ****************************************************************/

#include <iostream>
#include <ctime>
#include "creatures.h"

using namespace std;

struct initaitveCount{
  int initiative;
  initaitveCount* pointer;
};

int selectQuest()
{
  return -1;
}

void openMenu(player& playerEdit)
{
  //player playerEdit;
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
           << "4 to exit the menu.\n"
           << "5 to exit the game.\n"
           << "Enter answer: ";
      cin >> answer;
      if (answer == 1)
        {
          playerEdit.updateStats();
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
      else if (answer == 5)
        {
          answer = 0;
          while (answer != 1 && answer != 2)
            {
              cout << "\nAre you sure you want to exit?"
                   << "\nAll unsaved progress will be lost."
                   << "\n1 to exit the game."
                   << "\n2 to continue playing."
                   << "\nEnter answer: ";
              cin >> answer;
              if (answer == 1)
                {
                  cout << "\nExiting...";
                  continue;
                }
              else if (answer == 2)
                {
                  cout << "\nContinuing game.";
                }
              else
                {
                  cout << "\nInvalid answer. Enter correct answer.\n";
                }
            }
        }
      else
        {
          cout << "Invalid answer. Enter a valid answer.\n";
        }
    }
}

//this will take user input to determine what they want to do in a turn of combat, returns true if the player has ran
bool playerCombatOptions(creatureType& opponent, player& player){
  bool hasTakenATurn = false;
  bool hasPlayerSucceededForfeit = false;
  string combatOption;
  do{
    cout << "What would you like to do. 1, check your opponents stats. " << endl;
    cout << "2, attack the chosen enemy." << endl;
    cout << "3, heal." << endl;
    cout << "4, run" << endl;
    cout << "What would you like to do: ";
    cin >> combatOption;
    if(combatOption == "stats" || combatOption == "STATS" || combatOption == "Stats"  || 
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
      if(player.healthPotions > 0){
        player.heal();
        player.healthPotions --;
        hasTakenATurn = true;
      }else{
        cout << "You have no health potions." << endl;
      }
        
    }else if(combatOption == "4" || combatOption == "four" || combatOption == "Four" || combatOption == "FOUR" || combatOption == "run"
    || combatOption == "Run" || combatOption == "RUN" || combatOption == "flee"|| combatOption == "Flee" || combatOption == "FLEE"
    || combatOption == "flee" || combatOption == "Flee" || combatOption == "FLEE"){
      hasPlayerSucceededForfeit = player.forfeit();
      if(hasPlayerSucceededForfeit == true){
        return true;
      }
    }else{
      cout << "You have selected an invalid option. " << endl;
    }
  }while(hasPlayerSucceededForfeit == false && hasTakenATurn == false);
  return false;
}

//returns false if the player lived or true if the died
bool fight(creatureType& opponent, player& playerEdit)
{
  playerEdit.rollInitiative();
  opponent.rollInitiative();
  initaitveCount* head = new initaitveCount;
  if(playerEdit.getInitiative() > opponent.getInitiative()){
    head->initiative = playerEdit.getInitiative();
    initaitveCount* temporary = new initaitveCount;
    temporary->initiative = opponent.getInitiative();
    head->pointer = temporary;
    temporary->pointer = head;
  }else{
    head->initiative = opponent.getInitiative();
    initaitveCount* temporary = new initaitveCount;
    temporary->initiative = playerEdit.getInitiative();
    head->pointer = temporary;
    temporary->pointer = head;
  }
  initaitveCount* current = head;
  
  //player playerEdit;
  bool forfeit = false;
  while (playerEdit.dead == false && opponent.dead == false && forfeit == false)
    {
      if(current->initiative == playerEdit.getInitiative()){
        forfeit = playerCombatOptions(opponent, playerEdit);
      }else{
        opponent.creatureLogic(playerEdit);
      }
      current = current->pointer;
    }
    if(playerEdit.dead == true){
      return true;
    }else if(forfeit == true){
      return false;
    }else{
      return false;
    }
}

void encounters(player& playerEdit)
{
  int temp = diceRoll(1, 20); //temp is used to store the dice roll

  if (temp >= 1 && temp < 15)
    {
      //if statement intentionally left blank.
      //nothing happens if the player gets between these values
    }
  else if (temp >= 15 && temp < 20)
    {
      //the player should encounter a monster between these rolls
      if (temp == 20)
        {
          //the player should encounter their target
        }
      else
        {
          temp = diceRoll(1, 10);
          if (temp == 1){
            cout << endl << playerEdit.name << " runs across a skeleton and prepares for combat." << endl;
            skeleton skeleton;
            playerEdit.dead = fight(skeleton, playerEdit);
          }
          else if (temp == 2){
            cout << endl << "You see a zombie roaming about. These forrests are cursed. You prepare for combat." << endl;
            zombie zombie;
            playerEdit.dead = fight(zombie, playerEdit);
          }
          else if (temp == 3){
            cout << endl << "You spot a goblin, with the symbol of the goblin boss." << endl;
            goblin goblin;
            playerEdit.dead = fight(goblin, playerEdit);
          }
          else if (temp == 4){
            cout << endl << playerEdit.name << " comes across an ape. Must be an invasive species... It looks angry." << endl;
            ape ape;
            playerEdit.dead = fight(ape, playerEdit);
          }
          else if (temp == 5){
            cout << endl << "You hear rustling. An unnatural amount. You turn to see a shrub, alive, ready to attack you." << endl;
            awakenedShrub awakenedShrub;
            playerEdit.dead = fight(awakenedShrub, playerEdit);
          }else if (temp == 6){
            cout << endl << "Out of nowhere you reflexively dodge a slam. You turn to see a tree, awakened." << endl;
            awakenedTree awakenedTree;
            playerEdit.dead = fight(awakenedTree, playerEdit);
          }else if (temp == 7){
            cout << endl << playerEdit.name << " runs across a brown bear. Fun!" << endl;
            brownBear brownBear;
            playerEdit.dead = fight(brownBear, playerEdit);
          }else if (temp == 8){
            cout << endl << playerEdit.name << " runs across a black bear. Fun!" << endl;
            blackBear blackBear;
            playerEdit.dead = fight(blackBear, playerEdit);
          }else if (temp == 9){
            cout << endl << "A CROCODILE! Out in the wild in the forrest. It looks hungry. Prepare to fight!" << endl;
            crocodile crocodile;
            playerEdit.dead = fight(crocodile, playerEdit);
          }else{
            cout << endl << "You hear barking. As you're drawn closer to the sound you approach a death dog. The two headed beast snarls at you. You ready yourself." << endl;
            deathDog deathDog;
            playerEdit.dead = fight(deathDog, playerEdit);
          }

        }
    }
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


