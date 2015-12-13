#include "NFL_Prototypes.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printTitle(ostream &output){
	output
		<< "\t This program receives NFL QB statistics from a file," << endl
		<< "\t         calculates various averages and rates," << endl
		<< "\t    and outputs rankings to the console and/or files" << endl << endl;
}

void getFileName(ifstream &file){
	string input;
	getline(cin, input); // Get user input for input file
	file.open(input); // Open input file

	while (!file){ // If file not found, re-prompt
		cout
			<< "File not found." << endl
			<< "Try again: "; // error message for file not located

		getline(cin, input); // re-try new file
		file.open(input);
	}
}


void printStatMenu(ostream &output){
	cout
		<< "\tPlease select a stat or 'M' to exit:" << endl
		<< "A - Completions (raw)" << endl
		<< "B - Attempts" << endl
		<< "C - Completion Percentage" << endl
		<< "D - Yards" << endl
		<< "E - Yards per attempt" << endl
		<< "F - Yards per completion" << endl
		<< "G - Touchdowns" << endl
		<< "H - Touchdowns per Attempt" << endl
		<< "I - Interceptions" << endl
		<< "J - Interception per Attempt" << endl
		<< "K - Touchdown : Interception Ratio" << endl
		<< "L - Passer Rating" << endl
		<< "M - Exit Program" << endl;
}

char getLetter(){
	char x;

	cin >> x;		cin.ignore(80, '\n');
	while (x < 'A' || x > 'z' || x > 'Z' && x < 'a'){
		cout
			<< "\tPlease enter a letter." << endl
			<< "\tTry again:" << endl;
		cin >> x;		cin.ignore(80, '\n');
	}
	return x;
}

char makeCaps(char x){
	if (x >= 'a' && x <= 'z'){
		x += 'A' - 'a';
	}
	return x;
}

char getLetterBefore(char end){
	char x = getCapsLetter();
	while (x > 'L'){
		cout << x << " is not a valid choice. Try again: ";
		x = getCapsLetter();
	}
	return x;
}

char getCapsLetter(){
	char x = getLetter();
	
	x = makeCaps(x);
	
	return x;
}

void loadStatArray(istream &input, double statsArray[][12], int numQBs, int numStats){
	for (int q = 0; q < numQBs; q++){
		for (int i = 0; i < numStats; i++){
			input >> statsArray[q][i];
		}
	}
}

void loadNameArray(istream &input, string nameArray[], int numQBs){
	for (int i = 0; i < numQBs; i++)
		getline(input, nameArray[i]);
}


void addCalcStats(double (&statsArray)[32][12], int numQBs, int numFileStats){
	for (int q = 0; q < numQBs; q++){
		statsArray[q][5] = statsArray[q][0] / statsArray[q][1];			// Completion Percentage
		statsArray[q][6] = statsArray[q][2] / statsArray[q][1];			// Yards per attempt
		statsArray[q][7] = statsArray[q][2] / statsArray[q][0];			// Yards per completion
		statsArray[q][8] = statsArray[q][3] / statsArray[q][1];			// Touchdowns per Attempt
		statsArray[q][9] = statsArray[q][4] / statsArray[q][1];			// Interceptions per Attempt
		statsArray[q][10] = statsArray[q][3] / statsArray[q][4];		// Touchdown : Interception Ratio
		statsArray[q][11] = ((((statsArray[q][5] - .3) * 5) + ((statsArray[q][6] - 3) * .25) + (statsArray[q][8] * 20) + (2.375 - (statsArray[q][9] * 25))) / 6) * 100;					// Passer Rating
	}
}

char getYesNo(){
	char c = getCapsLetter();
	while (c != 'Y' && c != 'N'){
		cout << "Please enter \'Y\' or \'N\'. Try again: ";
		c = getCapsLetter();
	}
	return c;
}

void exitProgram(){
	cout << "Are you sure you want to exit? ";
	char yesNo = getYesNo();
	if (yesNo == 'Y')
		exit(0);
}

int getStatIndex(char c){
	switch (c){
	case 'A': return 0;		break; // Completions
	case 'B': return 1;		break; // Attempts
	case 'C': return 5;		break; // Completion Percentage
	case 'D': return 2;		break; // Yards
	case 'E': return 6;		break; // YpA
	case 'F': return 7;		break; // YpC
	case 'G': return 3;		break; // Touchdowns
	case 'H': return 8;		break; // TDpA
	case 'I': return 4;		break; // Int
	case 'J': return 9;		break; // Int/A
	case 'K': return 10;	break; // TD : INT
	case 'L': return 11;	break; // Passer Rating
	}
}

void findIndexRanks(double statsArray[][12], int (&rankArray)[32], int indexOfStatToCheck, int numToRank, int numQBs){
		bool swapped = true;
		while (swapped) {
			swapped = false;
			for (int i = 0; i < numToRank; i++) {
				if (statsArray[i][indexOfStatToCheck] > statsArray[i + 1][indexOfStatToCheck]) {
					rankArray[i] = i;
					rankArray[i + 1] = i + 1;
					swapped = true;
				}
			}
		}
	
	/* for (int i = 0; i < numToRank; i++)
		for (int q = 0; q < numQBs; q++)
			if (statsArray[q][indexOfStatToCheck] > statsArray[rankArray[i]][indexOfStatToCheck] && q != rankArray[i])
				rankArray[i] = q; */
}

double getNum() {
	double x;
	while (!(cin >> x)) { // While non-number inputted
		cin.clear();		cin.ignore(80, '\n'); // Reset cin object and clear buffer
		cout // Print error message if non-number inputted
			<< "\tPlease no inappropriate characters!" << endl
			<< "\tTry again: ";
	}
	cin.ignore(80, '\n'); // Clear keyboard buffer again once number obtained
	return x; // returns validated double
}

int getInt() {
	double x = getNum(); // Validate number

	while (int(x) != x) { // Validate number is int
		cout
			<< "\tYour number is not an integer!" << endl
			<< "\tTry again: ";
		x = getNum();
	}
	return int(x); // return validated int (typecasted to avoid warning message when storing double result in int variable)
}

int getInTheRange(int s, int e) {
	int i = getInt();

	while (i < s || i > e) {
		cout
			<< "\tYour number must be "
			<< (i < s ? "greater " : "less ")
			<< "than or equal to "
			<< (i < s ? s : e) << endl
			<< "\tTry again: ";
		i = getInt();
	}

	return i;
}