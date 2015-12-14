#include "NFL_Prototypes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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

void getFileName(ofstream &file){
	string input;
	getline(cin, input); // Get user input for input file
	file.open(input); // Open input file

	while (!file){ // If file not found, re-prompt
		cout
			<< "Invalid File Name." << endl
			<< "Try again: "; // error message for file not located

		getline(cin, input); // re-try new file
		file.open(input);
	}
}

void printStatMenu(ostream &output){
	output
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

	cin >> x;		cin.ignore(80, '\n'); // get character from keyboard
	while (x < 'A' || x > 'z' || x > 'Z' && x < 'a'){
		cout
			<< "\tPlease enter a letter." << endl // reprompt if not letter
			<< "\tTry again:" << endl;
		cin >> x;		cin.ignore(80, '\n');
	}
	return x;
}

char makeCaps(char x){
	if (x >= 'a' && x <= 'z') // if letter lower
		x += 'A' - 'a'; // make upper
	return x;
}

char getLetterBefore(char end){
	char x = getCapsLetter(); // get caps
	while (x > end){ // if letter higher than end, 
		cout << x << " is not a valid choice. Try again: "; // reprompt
		x = getCapsLetter();
	}
	return x;
}

char getCapsLetter(){
	char x = getLetter(); // get letter
	
	x = makeCaps(x); // make it caps
	
	return x;
}

void loadStatArray(istream &input, double statsArray[][12], int numQBs, int numStats){
	for (int q = 0; q < numQBs; q++){ // for each QB
		for (int i = 0; i < numStats; i++){ // load 5 stats
			input >> statsArray[q][i];
		}
	}
}

void loadNameArray(istream &input, string nameArray[], int numQBs, char c){
	for (int i = 0; i < numQBs; i++) // load names into string array
		getline(input, nameArray[i], c);
}


void addCalcStats(double (&statsArray)[32][12], int numQBs, int numFileStats){
	for (int q = 0; q < numQBs; q++){
		statsArray[q][5] = statsArray[q][0] / statsArray[q][1];			// Completion Percentage
		statsArray[q][6] = statsArray[q][2] / statsArray[q][1];			// Yards per attempt
		statsArray[q][7] = statsArray[q][2] / statsArray[q][0];			// Yards per completion
		statsArray[q][8] = statsArray[q][3] / statsArray[q][1];			// Touchdowns per Attempt
		statsArray[q][9] = statsArray[q][4] / statsArray[q][1];			// Interceptions per Attempt
		statsArray[q][10] = statsArray[q][3] / statsArray[q][4];		// Touchdown : Interception Ratio
		statsArray[q][11] = ((((statsArray[q][5] - .3) * 5) + ((statsArray[q][6] - 3) * .25)
			+ (statsArray[q][8] * 20) + (2.375 - (statsArray[q][9] * 25))) / 6) * 100;		
																		// Passer Rating
	}
}

char getYesNo(){
	char c = getCapsLetter(); // get uppercase letter
	
	while (c != 'Y' && c != 'N'){ // if letter isn't 'Y' or 'N'
		cout << "Please enter \'Y\' or \'N\'. Try again: "; // reprompt
		c = getCapsLetter();
	}
	return c;
}

void exitProgram(){
	cout << "Are you sure you want to exit? ";
	char yesNo = getYesNo(); // confirm intent to exit
	
	if (yesNo == 'Y') // exit
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
	default:  return -1; // error code
	}
}

int findIndexofMax(double statsArray[][12], int indexOfStatToCheck, int numQBs){
	int maxIndex = 0;

	for (int i = 0; i < numQBs; i++){ // check full array for largest value
		if (statsArray[i][indexOfStatToCheck] > statsArray[maxIndex][indexOfStatToCheck])
			maxIndex = i;
	}

	return maxIndex;
}

int findIndexofMin(double statsArray[][12], int indexOfStatToCheck, int numQBs){
	int minIndex = 0;
	
	for (int i = 0; i < numQBs; i++){ // check full array for largest value
		if (statsArray[i][indexOfStatToCheck] < statsArray[minIndex][indexOfStatToCheck])
			minIndex = i;
	}
	return minIndex;
}

double calcAverageValue(double statsArray[][12], int indexOfStatToCheck, int numQBs){
	double sum = 0;
	int i = 0;
	
	for (; i < numQBs; i++){ // add all values into sum
		sum += statsArray[i][indexOfStatToCheck];
	}
	
	return sum / i; // return average
}

string findStatLabel(int statIndex){
	switch (statIndex){
	case 0:  return "Completions";						break; // Completions
	case 1:  return "Attempts";							break; // Attempts
	case 5:  return "Completion Percentage";			break; // Completion Percentage
	case 2:  return "Yards";							break; // Yards
	case 6:  return "Yards per Attempt";				break; // YpA
	case 7:  return "Yards per Completion";				break; // YpC
	case 3:  return "Touchdowns";						break; // Touchdowns
	case 8:  return "Touchdowns per Attempt";			break; // TDpA
	case 4:  return "Interceptions";					break; // Int
	case 9:  return "Interceptions per Attempt";		break; // Int/A
	case 10: return "Touchdown : Interception Ratio";	break; // TD : INT
	case 11: return "Passer Rating";					break; // Passer Rating
	default: return "Stat not found"; // error code
	}
}

void printAvg(int indexSmChoice, double avg, ostream &output){
	output << fixed << showpoint; // force decimal
	if (indexSmChoice == 8 || indexSmChoice == 9)
		output << setprecision(3); // small number stats require 3 decimal places

	else
		output << setprecision(2); // larger one only require two
	
	output << "The league average in " << findStatLabel(indexSmChoice) << " was ";

	if (indexSmChoice == 5)
		output << avg * 100 << "%"; // percentage logic

	else
		output << avg;

	output << ".";
}

char getValidMenuChoice(char choice1, char choice2){
	char menuChoice = getCapsLetter();

	while (menuChoice != choice1 && menuChoice != choice2){
		cout << "Please make a valid selection: ";
		menuChoice = getCapsLetter();
	}

	return menuChoice;
}

void printValuesAbove(double stats[][12], string names[], int indexSmChoice, double above, int size, ostream &output){
	output << "The following QBs were above average in " << findStatLabel(indexSmChoice) << ": " << endl << endl; // intro statement
	
	for (int i = 0; i < size; i++){
		if (stats[i][indexSmChoice] > above){ // if a QB is below average, print his stat
			output << left << setw(18) << names[i];
			output << right << fixed << showpoint << "\t"; // force decimal (more stats require it than don't)

			if (indexSmChoice == 5 || indexSmChoice == 11) // one decimal for larger numbers
				output << setprecision(1);

			else if (indexSmChoice == 6 || indexSmChoice == 7 || indexSmChoice == 10) // two for medium numbers
				output << setprecision(2);

			else if (indexSmChoice == 8 || indexSmChoice == 9) // three for smallest numbers
				output << setprecision(3);

			else
				output << noshowpoint << setprecision(0); // remove decimal for integer stats

			if (indexSmChoice == 5) // percentage logic
				output << stats[i][indexSmChoice] * 100 << "%";

			else
				output << stats[i][indexSmChoice];

			output << endl;
		}
	}
	
	for (int k = 0; k < 78; k++) // seperator line
		output << "-";
		
	}

void printValuesBelow(double stats[][12], string names[], int indexSmChoice, double below, int size, ostream &output){
	output << "The following QBs were below average in " << findStatLabel(indexSmChoice) << ": " << endl << endl; // see"above" function for full description, they're nearly identical

	for (int i = 0; i < size; i++){
		if (stats[i][indexSmChoice] < below){
			output << left << setw(18) << names[i];
			output << right << fixed << showpoint << "\t";

			if (indexSmChoice == 5 || indexSmChoice == 11)
				output << setprecision(1);

			else if (indexSmChoice == 6 || indexSmChoice == 7 || indexSmChoice == 10)
				output << setprecision(2);

			else if (indexSmChoice == 8 || indexSmChoice == 9)
				output << setprecision(3);

			else
				output << noshowpoint << setprecision(0);

			if (indexSmChoice == 5)
				output << stats[i][indexSmChoice] * 100 << "%";

			else
				output << stats[i][indexSmChoice];

			output  << endl;
		}
	}

	for (int k = 0; k < 78; k++)
		output << "-";
}

void printStats(double statsArray[][12], string names[], int maxIndex, int minIndex, int statToCheck, double avg, int numQBs, ostream &output){

	output << endl;

	printMaxValue(statsArray, names, maxIndex, statToCheck, output); // print highest
	
	output << endl;

	printMinValue(statsArray, names, minIndex, statToCheck, output); // print lowest
	
	output << endl << endl;

	printAvg(statToCheck, avg, output); // print average

	output << endl << endl;

	printValuesAbove(statsArray, names, statToCheck, avg, numQBs, output); // print QBs above average

	output << endl << endl;

	printValuesBelow(statsArray, names, statToCheck, avg, numQBs, output); // print QBs below average
}

void printMaxValue(double stats[][12], string names[], int maxIndex, int indexSmChoice, ostream &output){
	output // use index found from findMaxIndex to determine the individual and print it using above decimal handling
		<< fixed << showpoint
		<< "The highest QB in " << findStatLabel(indexSmChoice) << " was " << names[maxIndex] << " with ";

	if (indexSmChoice == 5 || indexSmChoice == 11)
		output << setprecision(1);

	else if (indexSmChoice == 6 || indexSmChoice == 7 || indexSmChoice == 10)
		output << setprecision(2);

	else if (indexSmChoice == 8 || indexSmChoice == 9)
		output << setprecision(3);

	else
		output << noshowpoint << setprecision(0);

	if (indexSmChoice == 5)
		output << stats[maxIndex][indexSmChoice] * 100 << "%";

	else
		output << stats[maxIndex][indexSmChoice];
}

void printMinValue(double stats[][12], string names[], int minIndex, int indexSmChoice, ostream &output){
	output		// Ditto above, but lowest
		<< "The lowest QB in " << findStatLabel(indexSmChoice) << " was " << names[minIndex] << " with ";

	if (indexSmChoice == 5 || indexSmChoice == 11)
		output << setprecision(1);

	else if (indexSmChoice == 6 || indexSmChoice == 7 || indexSmChoice == 10)
		output << setprecision(2);

	else if (indexSmChoice == 8 || indexSmChoice == 9)
		output << setprecision(3);

	else
		output << noshowpoint << setprecision(0);

	if (indexSmChoice == 5)
		output << stats[minIndex][indexSmChoice] * 100 << "%";

	else
		output << stats[minIndex][indexSmChoice];
}