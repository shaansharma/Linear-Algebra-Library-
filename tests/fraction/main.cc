// Testing program to test fraction
// Use: 
//		1. compile: g++ main.cc fraction.cc -o FractionTestProgram
//		2. run: ../runSuite TESTS.txt FractionTestProgram
//
// Commands: (3 Fractions are available, referred to [num], and 1..5 in test files)
//				* [fraction] is a string either a/b or a where a and b are integers
//				1. n [num] [fraction] (creates new fraction)
//				2. d [num] (deletes fraction [num])
//				3. a [num] [num] [num] (adds two fractions in new location (location is first number))
//				4. m [num] [num] [num] (multiplies two fractions, stores in first fraction)
//				5. w [num] (prints whether fraction is whole)
//				6. = [num] [num] (sets first fraction to second)
//				7. p [num] (prints fraction)
//				8. r [num] (makes fraction it's reciprocal)

#include <iostream>
#include "fraction.h"
#include <string>
#include <sstream>

using namespace std;

int main(){
	Fraction **array = new Fraction*[5];
	array[0] = NULL;
	array[1] = NULL;
	array[2] = NULL;
	array[3] = NULL;
	array[4] = NULL;

	string input;
	
	while(true){
		getline(cin, input);
		if(!cin.eof()){
			string command;
			stringstream in(input);
			in >> command;
			int pos1 = 0;
			in >> pos1;
	
			if(command == "n"){
				string fraction;
				in >> fraction;
				delete array[pos1 - 1];
				array[pos1 - 1] = new Fraction(fraction);
			} else if(command == "d"){
				delete array[pos1 - 1];
				array[pos1 - 1] = NULL;
			} else if(command == "a"){
				int pos2;
				int pos3;
				in >> pos2;
				in >> pos3;
				delete array[pos1 - 1];
				array[pos1 - 1] = new Fraction(*array[pos2- 1] + *array[pos3 - 1]);
			} else if(command == "m"){
				int pos2;
				int pos3;
				in >> pos2;
				in >> pos3;
				delete array[pos1 - 1];
				array[pos1 - 1] = new Fraction(*array[pos2- 1] * *array[pos3 - 1]);
			} else if(command == "w"){
				if(array[pos1 - 1]->isWhole()){
					cout << "whole";
				} else {
					cout << "not whole";
				}
				cout << endl;
			} else if(command == "="){
				int pos2;
				in >> pos2;
				delete array[pos1 - 1];
				array[pos1 - 1] = new Fraction(*array[pos2 - 1]);
			} else if(command == "p"){
				cout << array[pos1 - 1]->getNumerator() << "/" << array[pos1 - 1]->getDenominator() << endl;
			} else if(command == "r"){
				*array[pos1 - 1] = array[pos1 - 1]->reciprocal();
			}	
		} else {
			break;
		}
	}

	delete [] array;
}
