// Reads NFL QB Statistics From File, with Various Calculations and Ouputs
// NFL_Project.exe
// Programmer: Andrew Thomas
// As of: 12/14/2015

#include "NFL_Prototypes.h"
#include <iostream>
#include <fstream>
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
	char menuChoice, menuChoice2;			// Menu choices
	double stats[QBS][TOTAL_STATS];			// holds stats indexed by QB number
	string nameQBs[QBS];					// Parallel array to hold names of QBs
	int indexSmChoice, minIndex, maxIndex;	// index of stat, min value, max value
	double avg;								// average

	///////////////////////////////////////////////////////////////////////////////////////////

	
		printTitle(cout); // Print title block

		cout // Prompt user for custom input files or not
			<< "Default is full 2014 season stats for all 32 Starting QBs" << endl
			<< "(for teams with multiple QBs, the QB with more Attempts was used)" << endl
			<< "Would you like to use custom input files? ";
			
		menuChoice = getYesNo();
		
		if (menuChoice == 'Y'){ // If user chooses custom files, warn of formatting issues and get filename
			cout << "Please see readme.txt for information on formatting input files before using custom inputs." << endl << endl;

			cout << "What is the filename of your stats file? ";
			getFileName(statsIn); // Gets filename and opens once valid

			cout << "What is the filename of your name file? ";
			getFileName(nameIn); // Gets filename and opens once valid

			cout << endl << endl;
		}

		else{
			statsIn.open("stats.txt"); // If user does not have custom inputs, use default files
			nameIn.open("names.txt");
		}
			
		loadStatArray(statsIn, stats); // fill stats array
		
		statsIn.close(); // close stats file ASAP
			
		addCalcStats(stats);			// Add runtime-calculated stats
		
		loadNameArray(nameIn, nameQBs); // load name array
			
		nameIn.close(); // close name file asap

	while (true){
		printStatMenu();  menuChoice = getLetterBefore('M'); // user selects statistic to get rankings
		
		if (menuChoice == 'M'){ // if the user selects M, run exit function
			exitProgram();
		}

		indexSmChoice = getStatIndex(menuChoice); // change letter from menu to index of stat

		cout << "Would you like to print to the console or a file? "; // user dictates print location
		menuChoice2 = getValidMenuChoice('C', 'F'); // only allow c or f as choice

		avg = calcAverageValue(stats, indexSmChoice,QBS);		// Calculate and store average
		maxIndex = findIndexofMax(stats, indexSmChoice, QBS);	// Find and store index of highest in selected stat
		minIndex = findIndexofMin(stats, indexSmChoice, QBS);	// Fine and store index of lowest in selected stat

		if (menuChoice2 == 'C') // If user dictates console, print to console
			printStats(stats, nameQBs, maxIndex, minIndex, indexSmChoice, avg, QBS);

		else{  // Else prompt for output filename
			cout << "Please enter the filename for your output file: ";
			getFileName(statsOut); // Gets filename and opens once valid

			printStats(stats, nameQBs, maxIndex, minIndex, indexSmChoice, avg, QBS, statsOut); // Print to file

			statsOut.close(); // Close file ASAP
		}

		cout << endl << endl;
		system("pause"); // Hold for user input
		system("cls");	 // Clear screen to loop

		printTitle(); // Print title and loop to menu (with same input files - program must be restarted in order to change input files)
	}
}