/*****************************************
 **
 ** File: Warhorse.cpp
 ** Project: CMSC 202, Project 4, Spring 2019
 ** Author: Hamza Ilyas
 ** Date: 04/10/2019
 ** Section: Discussion - 07, Lecture - 25
 ** E-mail: hamza3@umbc.edu
 **
 **
 ** This file is the implementation of the corresponding Warhorse.h file.
 **
 ** Certain functions were defined at the top of some files to maintain
 ** a more aesthetic and minimalistic reading experience
 **
 ** Extra spacing used in certain areas for code readability.
 **
 ** Some curly braces may differ from others. Where a more aesthetic
 ** implementation was possible, it was preferred.
 **
*****************************************/

#include "Warhorse.h"



bool Warhorse::train() { bool chance = randomPercentBased( 50 ); return chance; }
Warhorse::Warhorse()   { /* Intentionally left blank */ }



Warhorse::Warhorse(string name, Size size, int health, int speed):
  Horse(name, size, health, speed) {}


bool Warhorse::battle(Horse* battler) {

  string myName = getName();
  cout << "The mighty horse " << myName << " approaches! " << endl;
  int myHealth = getHealth();

  string enemyName = battler -> getName();
  cout << "Because of the aggression, " << enemyName << " hastens for battle!" << endl;
  int enemyHealth = battler -> getHealth();

  cout << myName << " starts with " << myHealth << " health. " << endl;
  cout << enemyName << " starts with " << enemyHealth << " health. " << endl;

  cout << "\n" << endl;

  //a more detailed implementation for battling was used to show the health every step
  //as opposed to the sample output.
  while( myHealth > 0 && enemyHealth  > 0 ) {

    int subtracted;

    //player goes first
    if ( myHealth > 0 ) {
      
      subtracted = attack( enemyName, enemyHealth );
      enemyHealth -= subtracted;
    }
    
    if ( enemyHealth <= 0 ) {
      cout << "and " << enemyName << " is now completely out of health!" << endl; }
    else {
      cout << "and " << enemyName << " now has " << enemyHealth << " health left!" << endl; }
    
    
    //then enemy attacks

    if ( enemyHealth > 0){
    
      subtracted = battler -> attack( myName, myHealth );
      myHealth -= subtracted;
      
    }
      
    //if ( myHealth <= 0 ) {
    // cout << "and " << myName << " is now completely out of health!" << endl; }
    //else {
    // cout  << "and " << myName << " now has " << myHealth << " health left!" << endl; }
    
    cout << "\n";
    
    //if enemy loses, return true
    if ( enemyHealth <= 0 )
      { cout << "Your warhorse: " <<  '"'
	     << getName() <<  '"' << " won!"
	     << endl;
	return true;

      }

    //if user loses, return false
    if ( myHealth <= 0 )
      { cout << "The enemy warhorse: " << '"'
	     << battler -> getName() << '"' << " won!"
	     << endl;
	return false;

      }
  }
  
  return false;
  
}
