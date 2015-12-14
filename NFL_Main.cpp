// Reads NFL QB Statistics From File, with Various Calculations and Ouputs
// NFL_Project.exe
// Programmer: Andrew Thomas
// As of: 12/11/2015

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
	char menuChoice, menuChoice2;				// Menu choices
	double stats[QBS][TOTAL_STATS];			// holds stats indexed by QB number
	string nameQBs[QBS];					// Parallel array to hold names of QBs
	int indexSmChoice, temp;
	double avg;

	///////////////////////////////////////////////////////////////////////////////////////////

	
		printTitle(cout); // Print title block

		cout << "Would you like to input custom files? ";
		menuChoice = getYesNo();
		
		if (menuChoice == 'Y'){
			cout << "What is the filename of your stats file? ";
			getFileName(statsIn);

			cout << "What is the filename of your name file? ";
			getFileName(nameIn);

			cout << endl << endl;
		}

		else{
			statsIn.open("stats.txt");
			nameIn.open("names.txt");
		}
			
		loadStatArray(statsIn, stats); // fill stats array
		
		statsIn.close();
			
		addCalcStats(stats);			// Add runtime-calculated stats
		
		loadNameArray(nameIn, nameQBs);
			
		nameIn.close();

	while (true){
		printStatMenu();  menuChoice = getLetterBefore('M');
		
		if (menuChoice == 'M'){
			exitProgram();
		}

		indexSmChoice = getStatIndex(menuChoice);

		cout << "Would you like to get the highest, lowest or average value? ";
		menuChoice = getValidMenuChoice('H', 'L', 'A');


			switch (menuChoice){
		case 'H': temp = findIndexofMax(stats, indexSmChoice);			 break;
		case 'L': temp = findIndexofMin(stats, indexSmChoice);			 break;
		case 'A': avg  = calcAverageValue(stats, indexSmChoice);		 break;
		}

		cout << "Would you like to print to the console or a file? ";
		menuChoice2 = getValidMenuChoice('C', 'F');

		if (menuChoice2 == 'C'){
			if (menuChoice == 'H' || menuChoice == 'L')
				printOutput(menuChoice, stats, indexSmChoice, temp, nameQBs);
			else
				printOutput(indexSmChoice, avg);
		}

		else{
			getFileName(statsOut);

			if (menuChoice == 'H' || menuChoice == 'L')
				printOutput(menuChoice, stats, indexSmChoice, temp, nameQBs, statsOut);
			else
				printOutput(indexSmChoice, avg, statsOut);

			statsOut.close();
		}

		cout << endl << endl;
		system("pause");
		system("cls");

		printTitle();
	}
}