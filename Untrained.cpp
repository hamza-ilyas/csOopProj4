/*****************************************
 **
 ** File: Untrained.cpp
 ** Project: CMSC 202, Project 4, Spring 2019
 ** Author: Hamza Ilyas
 ** Date: 04/10/2019
 ** Section: Discussion - 07, Lecture - 25
 ** E-mail: hamza3@umbc.edu
 **
 **
 ** This file is the implementation of the corresponding Untrained.h file.
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

#include "Untrained.h"



//all single line functions declared at top
string Untrained::toString() { return ( "Unknown" ); }
bool Untrained::train()      { cout << "This horse type must be specialized before training." << endl; return false; }
Untrained::Untrained()       { /* Intentionally left empty */ }


Untrained::Untrained( string name, Size size, int health, int speed ):
  Horse(name, size, health, speed ) {} //use of parent constructor


//takes unknown type and converts to appropriate specialized horse
Horse* Untrained::specialize(){
  
  string horseName = getName();
  Size size = getSize();
  int health = getHealth();
  int speed = getSpeed();
  string type = toString();
  
  if ( type == "Unknown" ) {
    cout << "Your horse has now been specialized!" << endl;
    
    if( size == 0 ) {      
      Light *upgradedHorse = new Light( horseName, size, health, speed );
      return upgradedHorse;
    }

    if( size == 1 ) {
      
      Medium *upgradedHorse = new Medium( horseName, size, health, speed );
      return upgradedHorse;
    }
    
    if( size == 2 ) {
      
      Heavy *upgradedHorse = new Heavy( horseName, size, health, speed );
      return upgradedHorse;
    }
    
  }
  return nullptr;

}



int Untrained::attack( string name, int attack ) {

  cout << "Untrained horses may not attack. " << endl;
  
  return 0;
  
}
