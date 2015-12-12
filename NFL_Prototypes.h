#include <iostream>
#include <fstream>
using namespace std;

// Preconditions : Files must be opened prior to usage
// Postconditions: Prints formatted title block to given ostream object
void printTitle(ostream &output = cout);

void getFileName(ifstream &file);

// Preconditions : NONE
// Postconditions: Prints a formatted menu
void printMainMenu(ostream &output = cout);

// Preconditions : NONE
// Postconditions: Prints a formatted menu of stats
void printStatMenu(ostream &output = cout);

void loadStatArray(istream &input, double statsArray[][12], int numQBs = 32, int numStats = 5);

void loadNameArray(istream &input, string nameArray[], int numQBs = 32);

void exitProgram();

char getLetter();

char makeCaps(char x);

char getCapsLetter();

char getLetterBefore(char end);

void addCalcStats(double (&statsArray)[32][12], int numQBs = 32, int numFileStats = 5);

void findIndexRanks(double statsArray[][12], int (&rankArray)[32], int indexOfStatToCheck = 2, int numToRank = 10, int numQBs = 32);

int getStatIndex(char c);

double getNum();

int getInt();

int getInTheRange(int s, int e);