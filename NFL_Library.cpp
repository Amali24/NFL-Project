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