/*****************************************
 **
 ** File: War.cpp
 ** Project: CMSC 202, Project 4, Spring 2019
 ** Author: Hamza Ilyas
 ** Date: 04/10/2019
 ** Section: Discussion - 07, Lecture - 25
 ** E-mail: hamza3@umbc.edu
 **
 **
 ** This file is the implementation of the corresponding War.h file.
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

#include "War.h"



War::War() { srand (time ( NULL ) ); }


War::~War(){

  //destructor traverse both stables and remove
  int enemySize = m_enemyStable.size();
  int mySize = m_myStable.size();

  for ( int i = 0; i < enemySize; i++ ) {

    delete m_enemyStable[ i ];
    m_enemyStable[ i ] = nullptr; }

  for ( int j = 0; j < mySize; j++ ) {

    delete m_myStable[ j ];
    m_myStable[ j ] = nullptr; }

}


int War::chooseHorse(){

  //chooses a valid horse from do-while loop
  int choice;
  int size = m_myStable.size();
  displayMyHorses();
  
  if ( m_myStable.size() != 0 ){
    
    cout << "\nWhich horse would you like to choose from your stable? Enter number: ";

    do {cin >> choice; if ( choice > size || choice < 1 ) { cout << "INVALID CHOICE! TRY AGAIN: "; } }
    while( choice > size || choice < 1 );

    cout << "\n";
    
    return ( choice - 1 ); }
    
  return -1;

}



void War::loadHorses(char* filename){

  cout << "Welcome to UMBC War" << endl;

  //open the file and validate
  ifstream file;
  file.open( filename );

  //make sure file actually opened
  if ( file.is_open() ) { cout << "File located and opened successfully!" << endl; }

  else{
    
    cout << "\nUnfortunately, the file referenced with the parameters of the executable was not located." << endl;
    cout << "Please enter a new file: ";
    cin >> filename; 
    
    do
      { file.open(filename);
	
	if ( file.is_open() != true ) {
	  cout << "The file entered is still not located. Try again: ";
	  cin >> filename; }
	
      }
    
    while(file.is_open() != true);
    
    cout << "\nFile located and opened successfully!" << endl;
    
  }

  //variables declared for parameters of constructor
  string horseName;
  int sizeInt;
  int health;
  int speed;

  //continue file reading until null read

  while( file >> horseName >> sizeInt >> health >> speed ) {

    Size size;
    //assign a size based on the read in size
    if ( sizeInt == 0 ) { size = SMALL; }
    if ( sizeInt == 1 ) { size = MEDIUM; }
    if ( sizeInt == 2 ) { size = LARGE; }
      
    //dynamically allocate a light, medium, or heavy based on size  
    if ( size == SMALL ) {
	Light *newLight = new Light( horseName, size, health, speed ); 
        m_enemyStable.push_back(newLight);
    }      

    if ( size == MEDIUM ){
	Medium *newMedium = new Medium( horseName, size, health, speed );
        m_enemyStable.push_back( newMedium);
    }	  

    if ( size == LARGE ){
	Heavy *newHeavy = new Heavy( horseName, size, health, speed );
        m_enemyStable.push_back( newHeavy);
    }
      
  }
  
  file.close();

}


void War::mainMenu(){

  //initial display
  cout << "\nWelcome, what would you like to do? " << endl;
  cout << "1. Display Friendly Stable " << endl;
  cout << "2. Display Enemy Stable " << endl;
  cout << "3. Acquire Horse " << endl;
  cout << "4. Train Horse " << endl;
  cout << "5. Battle " << endl;
  cout << "6. Quit \n" << endl;

  int choice;

  do { cout << "Enter valid choice: "; cin >> choice; } while (choice > 6 || choice < 1); //validate input

  //until quit choice
  while( choice != 6 && m_enemyStable.size() != 0 ){

      //action based on user choice
      if ( choice == 1 ) { displayMyHorses(); }
      if ( choice == 2 ) { displayEnemyHorses(); }
      if ( choice == 3 ) { acquireHorse(); }
      if ( choice == 4 ) { trainHorse(); }
      if ( choice == 5 ) { startBattle(); }
      
      if ( m_enemyStable.size() == 0 )
	//player wins if all horses defeated, where size of enemy stable is 0.
	{ cout << "\nCongratulations, you've defeated every horse! Thanks for playing! " << endl; }
      
      if ( m_enemyStable.size() != 0) {
	//updated display
	cout << "\nWhat would you like to do next? " << endl;
	cout << "1. Display Friendly Stable " << endl;
	cout << "2. Display Enemy Stable " << endl;
	cout << "3. Acquire Horse " << endl;
	cout << "4. Train Horse " << endl;
	cout << "5. Battle " << endl;
	cout << "6. Quit \n" << endl;

	do { cout << "Enter valid choice: "; cin >> choice; } while ( choice > 6 || choice < 1 ); //revalidate input
	
      }
  }
  
  if ( choice == 6 ) {cout << "\nThanks for playing Warhorses\n" << endl; }

}


void War::displayEnemyHorses(){

  int size = m_enemyStable.size();

  //use a heading for easier readability
  cout << setw  (5 ) << "\nNUMBER"
       << setw( 25 ) << "HORSENAME"
       << setw( 25 ) << "SIZE"
       << setw( 25 ) << "HEALTH"
       << setw( 25 ) << "SPEED"
       << setw( 25 ) << "TRAINING\n" <<  endl;
  
  for( int i = 0; i < size; i++ ){
    
    //traverse for each horse
    cout << setw( 5 ) << i + 1;
    cout << *m_enemyStable[i]; }
  
}


void War::displayMyHorses(){
  
  int size = m_myStable.size();

  //nothing displayed if empty stable
  if ( size == 0 ) { cout << "\nYour stable is currently empty!" << endl; }

  else
    {
      //same implementation as displayEnemyHorses
      cout << setw ( 5 ) << "\nNUMBER"
	   << setw( 25 ) << "HORSENAME"
	   << setw( 25 ) << "SIZE"
	   << setw( 25 ) << "HEALTH"
	   << setw( 25 ) << "SPEED"
	   << setw( 25 ) << "TRAINING\n" << right <<  endl;

      for ( int i = 0 ; i < size ; i++ ) {

	  //traverse for each horse
	  cout << setw( 5 ) << i + 1;
	  cout << *m_myStable[i]; }

    }
}


void War::acquireHorse(){
  
  string name;
  
  cout << "\nWhat would you like to name your horse? Enter: ";
  cin >> name;

  Size size;
  int randSize = rand() % 3 + 1;

  //new horse will be according to size numbers
  if ( randSize == 1 ) { size = SMALL; }
  if ( randSize == 2 ) { size = MEDIUM; }
  if ( randSize == 3 ) { size = LARGE; }
  
  int randHealth;
  int randSpeed;

  //based on size, new health and speed will be generated
  if ( randSize == 1 ) {
    randHealth = rand() % (LT_MAX_HEALTH - LT_MIN_HEALTH)+ LT_MIN_HEALTH;
    randSpeed = rand() % (LT_MAX_SPEED - LT_MIN_SPEED) + LT_MIN_SPEED;
  }

  if ( randSize == 2 ) {  
    randHealth = rand() % (MD_MAX_HEALTH - MD_MIN_HEALTH) + MD_MIN_HEALTH;
    randSpeed = rand() % (MD_MAX_SPEED - MD_MIN_SPEED) + MD_MIN_SPEED;
  }

  if ( randSize == 3 ) {   
    randHealth = rand() % (HV_MAX_HEALTH - HV_MIN_HEALTH)+ HV_MIN_HEALTH;
    randSpeed = rand() % (HV_MAX_SPEED - HV_MIN_SPEED) + HV_MIN_SPEED;
  }
  
  //dynamically allocate horse and add to stable
  Untrained *newHorse = new Untrained( name, size, randHealth, randSpeed );
  
  cout << "You have now acquired a horse with random stats named: " << name << endl;

  m_myStable.push_back(newHorse);
    
}


void War::trainHorse(){

  int choice = chooseHorse();

  //if list is not empty and the horse is unknown only
  if ( choice != -1 && m_myStable[ choice ] -> toString() == "Unknown" ) {
    
      Horse *temp = m_myStable[ choice ];
      m_myStable[ choice ] = m_myStable[ choice ] -> specialize();
      delete temp;
      temp = nullptr; }

  
  //if list isn't empty, 50% increase chance in training
  else if ( choice != -1 ) {
    
      if ( m_myStable[ choice ] -> train()) //if 50% chance succeeds,
	{ m_myStable[ choice ] -> increaseTraining(); } //increase the training

      else
	{ cout << "50%... so close yet so far. Your horse was not trained, try again!" << endl; }

  }
}


void War::startBattle() {

  int choice = chooseHorse();

  if ( choice != -1 ) {
    
    Training training = m_myStable[ choice ] -> getTraining();
    bool horseIsUntrained = training == 0;

    //check if training is Untrained
    
    if ( horseIsUntrained ) { cout << "Horses must reach saddle before battling!" << endl; }
    
    else{
      
	bool win = m_myStable[ choice ] -> battle( m_enemyStable [ 0 ] );
	
	if ( win == true ) {
	  //if user horse wins, delete first horse in enemy stable
	  Horse* temp = m_enemyStable[ 0 ];
	  delete temp;
	  temp = nullptr;
	  m_enemyStable.erase( m_enemyStable.begin() ); }

	else{
	  //if enemy horse wins, delete the selected horse of user
	  Horse* temp = m_myStable[ choice ];
	  delete temp;
	  temp = nullptr;
	  m_myStable.erase( m_myStable.begin() + choice );}
	
    }
  }
}
