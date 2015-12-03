#include "NFL_Prototypes.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void printTitle(ostream &output){
	output
		<< "\t This program receives NFL QB statistics from a file," << endl
		<< "\t         calculates various averages and rates," << endl
		<< "\t    and outputs rankings to the console and/or files" << endl << endl;
}

void printMainMenu(ostream &output){
	cout
		<< "\tPlease select an option: " << endl
		<< "A - Print Season Rankings" << endl
		<< "B - Print per Game Rankings" << endl
		<< "C - Exit Program" << endl;
}

void printStatMenu(ostream &output){
	cout
		<< "\tPlease select a stat:" << endl
		<< "A - Completions (raw)" << endl
		<< "B - Attempts" << endl
		<< "C - Completion Percentage" << endl
		<< "D - Yards" << endl
		<< "E - Yards per attempt" << endl
		<< "F - Yards per completion" << endl
		<< "G - Touchdowns" << endl
		<< "H - Attempts per Touchdown" << endl
		<< "I - Interceptions" << endl
		<< "J - Attempts per Interception" << endl
		<< "K - Touchdown : Interception Ratio" << endl
		<< "L - Passer Rating" << endl;
}
