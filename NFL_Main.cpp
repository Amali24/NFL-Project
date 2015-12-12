// Reads NFL QB Statistics From File, with Various Calculations and Ouputs
// NFL_Project.exe
// Programmer: Andrew Thomas
// As of: 12/2/2015

#include "NFL_Prototypes.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void main(){
	const int	
		QBS = 32,							// Number of QBs
		INPUTTED_STATS = 5,					// Number of stats being read from file
		TOTAL_STATS = 12;					// Number of stats, included those calculated at runtime
	string fileIn, fileOut;					// String for holding filename of input and output
	ifstream statsIn, nameIn;				// Input file
	ofstream statsOut;						// Output file
	char mmChoice, smChoice;				// Menu choices
	double stats[QBS][TOTAL_STATS];			// holds stats indexed by QB number
	string nameQBs[QBS];					// Parallel array to hold names of QBs
	int rankArray[QBS];
	int indexSmChoice, numToRank;

	///////////////////////////////////////////////////////////////////////////////////////////

	printTitle(cout); // Print title block

	cout << "What is the filename of your stats file? ";
	getFileName(statsIn);

	loadStatArray(statsIn, stats); // fill stats array
	addCalcStats(stats);			// Add runtime-calculated stats

	statsIn.close();
	
	cout << "What is the filename of your name file? ";
	getFileName(nameIn);

	loadNameArray(nameIn, nameQBs);

	nameIn.close();

	cout << endl << endl;

	printMainMenu(); // Print main menu after arrays filled
	mmChoice = getLetterBefore('C'); // get a letter

	switch (mmChoice){ // Both A and B get choice from stats menu, specific choice handled later
	
	case 'A':
	
	case 'B': printStatMenu();  smChoice = getLetterBefore('L'); indexSmChoice = getStatIndex(smChoice);				break; // Prints stats menu and gets choice
	
	case 'C': exitProgram(); // Run exit function
	}
	
	cout << "How many players would you like to rank? ";
	numToRank = getInTheRange(0, 32);

	findIndexRanks(stats, rankArray, indexSmChoice, numToRank);

	for (int i = 0; i < 32; i++){
		cout << rankArray[i] << '\n';
	}

	/*for (int q = 0; q < QBS; q++){
		cout << nameQBs[rankArray[q]] << '\n';
		for (int i = 0; i < TOTAL_STATS; i++){
			cout << fixed << setprecision(2) << stats[rankArray[q]][i] << '\t';
		}
		cout << endl;
	}*/

	system("pause");
}