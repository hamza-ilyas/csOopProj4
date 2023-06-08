/*****************************************
 **
 ** File: Horse.cpp
 ** Project: CMSC 202, Project 4, Spring 2019
 ** Author: Hamza Ilyas
 ** Date: 04/10/2019
 ** Section: Discussion - 07, Lecture - 25
 ** E-mail: hamza3@umbc.edu
 **
 **
 ** This file is the implementation of the corresponding Horse.h file.
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

#include "Horse.h"



//all single-lined functions defined below

void Horse::setHealth( int health ) { m_health = health; }
bool Horse::battle(Horse* holder)   { return false; } //used as a function to hold place
Training Horse::getTraining()       { return m_training; }
Horse* Horse::specialize()          { return nullptr; } //used as a place holder function
string Horse::getName()             { return m_name; }
int Horse::getHealth()              { return m_health; }
Size Horse::getSize()               { return m_size; }
int Horse::getSpeed()               { return m_speed; }
Horse::Horse()                      { /* Intentionally left empty */ }


//overloaded constructor - used essentially for every horse read in and acquired
Horse::Horse(string name, Size size, int health, int speed){

  m_name = name;
  m_size = size;
  m_health = health;
  m_speed = speed;
  m_training = UNTRAINED;

}


//if the horse is not already a master, then we will
//current level of the horse, and increase it to the next
bool Horse::increaseTraining(){

  if ( getTraining() != MASTER ){

    cout << "Your horse has been trained up a level!" << endl;
    
    if ( m_training == UNTRAINED )    { m_training = SADDLE; return true; }
    if ( m_training == SADDLE )       { m_training = GREEN; return true;}
    if ( m_training == GREEN )        { m_training = INTERMEDIATE; return true;}
    if ( m_training == INTERMEDIATE ) { m_training = EXPERT; return true;}
    if ( m_training == EXPERT )       { m_training = MASTER; return true;}

  }
  
  cout << "Because your horse is already the max level, it was not trained." << endl;
  
  return false;
  
}


//based on the number, return the appropriate string associated with the enum
string Horse::trainingString(Training num){

  //else-ifs may have been used, but ifs were used to
  //maintain code aesthetic
  if ( num == 0 ) { return ( "Untrained" ); }
  if ( num == 1 ) { return ( "Saddle" ); }
  if ( num == 2 ) { return ( "Green" ); }
  if ( num == 3 ) { return ( "Intermediate" ); }
  if ( num == 4 ) { return ( "Expert" ); }
  if ( num == 5 ) { return ( "Master" ); }
  
  return ( "NOT TRAINED" );
}


//simple implementation to determine a random number given a percent like 50%
bool Horse::randomPercentBased(int rightComp){

  int randNum = rand() % 100 + 1;
  
  if ( randNum < rightComp ) { return true; }
  else { return false; }
  
}


//overloaded operator
ostream &operator<< (ostream& output, Horse& aHorse){

  //used equal witdths for clear and aesthetic readablity
  output << setw(25)
	 << aHorse.getName() << setw(25)
	 << aHorse.toString() << setw(25)
	 << aHorse.getHealth() << setw(25)
	 << aHorse.getSpeed() << setw(25)
	 << aHorse.trainingString(aHorse.getTraining()) << setw(25)
	 << endl;
  
  return output;
  
}
