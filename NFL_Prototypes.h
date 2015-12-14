#include <iostream>
#include <fstream>
using namespace std;

// Preconditions : Files must be opened prior to usage
// Postconditions: Prints formatted title block to given ostream object
void printTitle(ostream &output = cout);

// Preconditions : NONE
// Postconditions: Prints a formatted menu of stats to choose from
void printStatMenu(ostream &output = cout);

// Preconditions : NONE
// Postconditions: Gets valid filename
//				 : Opens file with that name
void getFileName(ifstream &file);

// Preconditions : NONE
// Postconditions: Gets valid filename
//				 : Opens file with that name
void getFileName(ofstream &file);

// Preconditions : 'input' is open
//				 : 'input' formatted according to instructions in 'readme.txt'
// Postconditions: Loads first 5 stats into statsArray
//				 : First dimension is quarterback index number
//				 : Second dimension holds stats
void loadStatArray(istream &input, double statsArray[][12], int numQBs = 32, int numStats = 5);

// Preconditions : 'input' is open
//				 : 'input' formatted according to instructions in 'readme.txt'
// Postconditions: loads a parallel array nameArray to hold corresponding names from 1st dimension of statsArray
void loadNameArray(istream &input, string nameArray[], int numQBs = 32, char c = '|');

// Preconditions : NONE
// Postconditions: Displays confirmation prompt and exits
void exitProgram();

// Preconditions : NONE
// Postconditions: Returns valid letter
//				 : Removes everything from the cin object
char getLetter();

// Preconditions : x is a letter
// Postconditions: Returns x if x is upper
//				 : Otherwise returns uppercase version of x
char makeCaps(char x);

// Preconditions : NONE
// Postconditions: Returns uppercase letter
//				 : Does NOT re-prompt for lower case; performs case switch
char getCapsLetter();

// Preconditions : Unpredictable behavior if 'end' is 'A'
//				 : 'end' is any letter
char getLetterBefore(char end);

// Preconditions : statsArray is pre-loaded with numFileStats values
// Postconditions: Adds runtime stats in indexes 5 through 11 of statsArray
void addCalcStats(double (&statsArray)[32][12], int numQBs = 32, int numFileStats = 5);

// Preconditions : statsArray is full
// Postconditions: Returns first index in dimension one of highest value in indexOfStatToCheck in dimension 2
int findIndexofMax(double statsArray[][12], int indexOfStatToCheck, int numQBs = 32);

// Preconditions : statsArray is full
// Postconditions: Returns first index in dimension one of lowest value in indexOfStatToCheck in dimension 2
int findIndexofMin(double statsArray[][12], int indexOfStatToCheck, int numQBs = 32);

// Preconditions : statsArray is full
// Postconditions: Returns average of values in indexOfStatToCheck in dimension 2 of statsArray
double calcAverageValue(double statsArray[][12], int indexOfStatToCheck, int numQBs = 32);

// Preconditions : 'A' < c < 'M'
// Postconditions: Returns index in dimension 2 of statsArray that correlates to user-selected choice from menu
int getStatIndex(char c);

// Preconditions : 0 <= statIndex < 11
// Postconditions: Returns corresponding label of stat chosen by user
string findStatLabel(int statIndex);

// Preconditions : 0 <= indexSmChoice < 11
//				 : If file used as output, must be open
// Postconditions: Prints statement to output
void printAvg(int indexSmChoice, double avg, ostream &output = cout);

// Preconditions : NONE
// Postconditions: Gets valid (uppercase) 'Y' or 'N'
char getYesNo();

// Preconditions : choice1 and choice2 are options from provided menu
// Postconditions: Returns a character matching one of the given arguments
char getValidMenuChoice(char choice1, char choice2);

// Preconditions : stats[][] contains stat values
//				 : names[][] is parallel to stats' first dimension and holds names
//				 : 0 <= indexSmChoice < 11
//				 : size is logical size of dimension one of stats
//				 : If file used as output, must be open
// Postconditions: Prints formatted list of name and stat value of all entries above' above'
void printValuesAbove(double stats[][12], string names[], int indexSmChoice, double above, int size, ostream &output = cout);

// Preconditions : stats[][] contains stat values
//				 : names[][] is parallel to stats' first dimension and holds names
//				 : 0 <= indexSmChoice < 11
//				 : size is logical size of dimension one of stats
//				 : If file used as output, must be open
// Postconditions: Prints formatted list of name and stat value of all entries below 'below'
void printValuesBelow(double stats[][12], string names[], int indexSmChoice, double below, int size, ostream &output = cout);


// Preconditions : statsArray[][] contains stat values
//				 : names[][] is parallel to statsArray's first dimension and holds names
//				 : maxIndex is the index in statsArray's 1st dimension that corresponds to the max value at index statToCheck of 2nd dimension
//				 : minIndex is the index in statsArray's 1st dimension that corresponds to the min value at index statToCheck of 2nd dimension
//				 : 0 <= statToCheck < 11
//				 : avg is the average value of index statToCheck of second dimension of statsArray
//				 : numQBs is logical size of dimension one of stats
//				 : If file used as output, must be open
// Postconditions: Prints formatted list of name and stat value of all entries below 'below'
void printStats(double statsArray[][12], string names[], int maxIndex, int minIndex, int statToCheck, double avg, int numQBs, ostream &output = cout);

// Preconditions : stats[][] contains stat values
//				 : names[][] is parallel to stats' first dimension and holds names
//				 : 0 <= indexSmChoice < 11
//				 : size is logical size of dimension one of stats
//				 : If file used as output, must be open
// Postconditions: Prints formatted line of name and stat value of max value for stat indexSmChoice
void printMaxValue(double stats[][12], string names[], int maxIndex, int indexSmChoice, ostream &output = cout);

// Preconditions : stats[][] contains stat values
//				 : names[][] is parallel to stats' first dimension and holds names
//				 : 0 <= indexSmChoice < 11
//				 : size is logical size of dimension one of stats
//				 : If file used as output, must be open
// Postconditions: Prints formatted line of name and stat value of min value for stat indexSmChoice
void printMinValue(double stats[][12], string names[], int minIndex, int indexSmChoice, ostream &output = cout);