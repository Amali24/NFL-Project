#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Preconditions : Files must be opened prior to usage
// Postconditions: Prints formatted title block to given ostream object
void printTitle(ostream &output = cout);

// Preconditions : NONE
// Postconditions: Prints a formatted menu
void printMainMenu(ostream &output = cout);

// Preconditions : NONE
// Postconditions: Prints a formatted menu of stats
void printStatMenu(ostream &output = cout);

void exitProgram();