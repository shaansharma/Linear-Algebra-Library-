#include <iostream>
#include "fraction.h"

using namespace std;

void printFraction(const Fraction &);

int main(){
	Fraction f1(3); // same as int f1 = 3
	Fraction f2(3, 4); // represents 3/4
	Fraction f3 = f1 + 1; // 4 

	printFraction(f1);
	printFraction(f2);

	cout << "f1 is whole: " << f1.isWhole() << endl; // true
	cout << "f2 is whole: " << f2.isWhole() << endl; // false

	printFraction(f1++); // f1 is now 4
	printFraction(f2++); // f2 is now 7/4

	printFraction(f1.reciprocal()); // prints 1/4
	printFraction(f2.reciprocal()); // prints 4/7

	f1 = f1 + f2; // f1 is now 4 + 7/4 = 23/4
	printFraction(f1);
	printFraction(f1 * 4); // prints 23/1 (not 92/4)
	printFraction(f1 * f3); // prints 23/1 (not 92/4)
	
	if(f1 < (f1 + 1)){
		cout << "always true" << endl;
	}
	
	if(f1 == f1){
		cout << "always true" << endl;
	}

	if(f1 != f2){
		cout << "f1 does not equal f2" << endl;
	}
}

void printFraction(const Fraction &f){
	cout << f.getNumerator() << "/" << f.getDenominator() << endl;
}
