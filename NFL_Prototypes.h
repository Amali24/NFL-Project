#include <iostream>
#include <fstream>
using namespace std;

// Preconditions : Files must be opened prior to usage
// Postconditions: Prints formatted title block to given ostream object
void printTitle(ostream &output = cout);

void getFileName(ifstream &file);

void getFileName(ofstream &file);

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

int findIndexofMax(double statsArray[][12], int indexOfStatToCheck, int numQBs = 32);

int findIndexofMin(double statsArray[][12], int indexOfStatToCheck, int numQBs = 32);

double calcAverageValue(double statsArray[][12], int indexOfStatToCheck, int numQBs = 32);

int getStatIndex(char c);

string findStatLabel(int statIndex);

void printOutput(char menuChoice, double stats[][12], int indexSmChoice, int index, string names[], ostream &output = cout);

void printOutput(int indexSmChoice, double avg, ostream &output = cout);

char getYesNo();

char getValidMenuChoice(char choice1, char choice2, char choice3);

char getValidMenuChoice(char choice1, char choice2);
