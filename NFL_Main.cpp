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
		QBS = 32,					// Number of QBs
		INPUTTED_STATS = 5,			// Number of stats being read from file
		TOTAL_STATS = 12;			// Number of stats, included those calculated at runtime
	string fileIn, fileOut;			// String for holding filename of input and output
	ifstream statsIn;				// Input file
	ofstream statsOut;				// Output file
	char mmChoice, smChoice;		// Menu choices
	double stats[QBS][TOTAL_STATS];		// holds stats indexed by QB number
	string nameQBs[QBS];			// Parallel array to hold names of QBs

	///////////////////////////////////////////////////////////////////////////////////////////

	printTitle(cout); // Print title block

	cout << "What is the filename of your stats file? ";
	getline(cin, fileIn); // Get user input for input file
	statsIn.open(fileIn); // Open input file

	while (!statsIn){ // If file not found, re-prompt
		cout
			<< "File not found." << endl
			<< "Try again: "; // error message for file not located

		getline(cin, fileIn); // re-try new file
		statsIn.open(fileIn);
	}

	loadStatArray(statsIn, stats, QBS, INPUTTED_STATS); // fill stats array

	cout << endl;

	printMainMenu(); // Print main menu after array filled
	mmChoice = getCapsLetter(); // get a letter

	switch (mmChoice){ // Both A and B get choice from stats menu, specific choice handled later
	
	case 'A':
	
	case 'B': printStatMenu();  smChoice = getCapsLetter();		break; // Prints stats menu and gets choice
	
	case 'C': statsIn.close(); exitProgram();	break; // Close file and run exit function
	}

	switch (smChoice){
	case 'A': // Completions (raw)
	case 'B': // Attempts"
	case 'C': // Completion Percentage
	case 'D': // Yards
	case 'E': // Yards per attempt
	case 'F': // Yards per completion
	case 'G': // Touchdowns
	case 'H': // Attempts per Touchdown
	case 'I': // Interceptions
	case 'J': // Attempts per Interception
	case 'K': // Touchdown : Interception Ratio
	case 'L': // Passer Rating
		break;
	}

	system("pause");
}

/*
Drew Brees
Ben Roethlisberger
Andrew Luck
Peyton Manning
Matt Ryan
Eli Manning			
Aaron Rodgers
Phillip Rivers
Matt Stafford
Tom Brady
Ryan Tannehill
Joe Flacco
Jay Cutler
Tony Romo
Russell Wilson
Andy Dalton
Colin Kaepernick
Brian Hoyer
Derek Carr
Alex Smith
Cam Newton
Kyle Orton
Teddy Bridgewater
Blake Bortles
Geno Smith
Ryan Fitzpatrick
Mark Sanchez
Josh McCown
Austin Davis
Drew Stanton
Kirk Cousins
Zach Mettenberger
*/