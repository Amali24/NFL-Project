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
	const int QBS = 32, STATS = 5;
	string fileName;
	ifstream statsIn;
	char char1;
	int stats[QBS][STATS];

	printTitle(cout);

	cout << "What is the filename of your stats file? ";
	getline(cin, fileName);
	
	statsIn.open(fileName);

	while (!statsIn){
		cout
			<< "File not found." << endl
			<< "Try again: ";
			
		getline(cin, fileName);
		statsIn.open(fileName);
	}
	
	for (int q = 0; q < QBS; q++){
		for (int i = 0; i < STATS; i++){
			statsIn >> stats[q][i];
		}
	}

	printMainMenu();
	cin >> char1;		cin.ignore(80, '\n');
	
	switch (char1){
	case 'A': 
	case 'B': printStatMenu();		break;
	case 'C': exitProgram();		break;
	default: 
		cout << "Please enter 1, 2, or 3: ";
		cin >> char1;		cin.ignore(80, '\n');
	}

	statsIn.close();
	system("pause");
}

/*
1  - Brees
2  - Roeth
3  - Luck
4  - PFM
5  - Ryan
6  - Eli
7  - Rodgers
8  - Rivers
9  - Stafford
10 - Brady
11 - Tannehill
12 - Flacco
13 - Cutler
14 - Romo
15 - Wilson
16 - Dalton
17 - Kaep
18 - Hoyer
19 - Carr
20 - Smith
21 - Newton
22 - Orton
23 - Bridgewater
24 - Bortles
25 - Geno
26 - Fitz
27 - Sanchez
28 - McCown
29 - Davis
30 - Stanton
31 - Cousins
32 - Mettenberger
*/