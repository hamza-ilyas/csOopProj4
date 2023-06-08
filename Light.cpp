/*****************************************
 **
 ** File: Light.cpp
 ** Project: CMSC 202, Project 4, Spring 2019
 ** Author: Hamza Ilyas
 ** Date: 04/10/2019
 ** Section: Discussion - 07, Lecture - 25
 ** E-mail: hamza3@umbc.edu
 **
 **
 ** This file is the implementation of the corresponding Light.h file.
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

#include "Light.h"



string Light::toString() { return ( "Light" ); }
Light::Light()           { /* Intentionally left empty */ }


Light::Light( string name, Size size, int health, int speed):
  Warhorse( name, size, health, speed ) {}


int Light::attack(string enemyName, int attackersHealth){
  
  cout << "The light warhorse " << getName() << " attacks " <<  enemyName;

  int hitpoints = ( attackersHealth/6 ) + getTraining();

  cout << " for " << hitpoints << " points, ";
  
  return hitpoints;
  
}




