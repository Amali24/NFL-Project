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
	const int QBS = 32, STATS = 5; // Number of individuals, and stats per individual
	string fileIn, fileOut; // String for holding filename of input and output
	ifstream statsIn; // ifstream for input file
	ofstream statsOut; // ofstream for output file
	char char1, char2; // character variables for menu choices
	int stats[QBS][STATS]; // 2 dimensional array holds stats

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

	for (int q = 0; q < QBS; q++){ // read from file 5 stats per each of 32 QBs
		for (int i = 0; i < STATS; i++){
			statsIn >> stats[q][i];
		}
	}

	cout << "\n";
	printMainMenu(); // Print main menu after array filled
	char1 = getLetter(); // get a letter
	char1 = makeCaps(char1); // make that letter uppercase if it is not

	while (char1 != 'A' && char1 != 'B' && char1 != 'C'){  // If invalid choice entered, re-prompt
	cout << "Please enter 'A', 'B', or 'C': ";
	char1 = getLetter();
}

	switch (char1){ // Both A and B display stats menu, specific choice handled later
	
	case 'A': printStatMenu();		break;
	
	case 'B': printStatMenu();		break;
	
	case 'C': statsIn.close(); exitProgram(); break; // Close file and run exit function
	}

	system("pause");
}

/*
case 1 : Drew Brees
case 2 : Ben Roethlisberger
case 3 : Andrew Luck
case 4 : Peyton Manning
case 5 : Matt Ryan
case 6 : Eli Manning			
case 7 : Aaron Rodgers
case 8 : Phillip Rivers
case 9 : Matt Stafford
case 10: Tom Brady
case 11: Ryan Tannehill
case 12: Joe Flacco
case 13: Jay Cutler
case 14: Tony Romo
case 15: Russell Wilson
case 16: Andy Dalton
case 17: Colin Kaepernick
case 18: Brian Hoyer
case 19: Derek Carr
case 20: Alex Smith
case 21: Cam Newton
case 22: Kyle Orton
case 23: Teddy Bridgewater
case 24: Blake Bortles
case 25: Geno Smith
case 26: Ryan Fitzpatrick
case 27: Mark Sanchez
case 28: Josh McCown (TB)
case 29: Austin Davis (STL)
case 30: Drew Stanton (ARI)
case 31: Kirk Cousins
case 32: Zach Mettenberger (TEN)
*/