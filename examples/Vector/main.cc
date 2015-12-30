#include "vector.h"
#include "fraction.h"
#include <vector>
#include <iostream>

using namespace std;

void printVector(const Vector &v);
void printFraction(const Fraction &f);

int main(){
	// v1 contains:
	//		1/2
	//		3/4
	//		5/1
	vector<Fraction> v1;
	v1.push_back(Fraction(1, 2)); 
	v1.push_back(Fraction(3, 4));
	v1.push_back(Fraction(5));

	Vector vector1(v1);
	printVector(vector1);

	// v1 conatains:
	// 	2/1
	// 	8/3
	// 	1/10
	vector<Fraction> v2;
	v2.push_back(Fraction(2));
	v2.push_back(Fraction(8, 3));
	v2.push_back(Fraction(1, 10));

	Vector vector2(v2);
	printVector(v2);

	// v3 conatins:
	// 	1/2 + 2/1 = 5/2
	//		3/4 + 8/3 = 41/12
	//		5/1 + 1/10 = 51/10
	Vector vector3 = vector1 + vector2;
	printVector(vector3);

	cout << "magnitude of vector1: " << vector1.getSize() << endl;

	// projection of vector1 onto vector2
	printVector(vector1.projectionOnto(vector2));

	// perpendicular of vector1 onto vector2
	printVector(vector1.perpendicularOnto(vector2));

	printVector(vector1 * 4);
	
	// dot product
	printFraction(vector1 * vector2);
	cout << endl;

	if(areOrthogonal(vector2, vector3)){
		cout << "vector2 and vector3 are othogonal" << endl;
	} else {
		cout << "vector2 and vector3 are NOT orthogonal" << endl;
	}

	cout << "vector1 and vector1 * 3 are scalar multiples: " << vector1.isScalarMultipleOf(vector1 * 3) << endl;
}

void printVector(const Vector &v){
	int length = v.getNumRows();
	
	// vectors are NOT 0 indexed. 
	// this is to keep it consistent with the mathematical definition of a vector
	for(int i = 1; i <= length; i++){
		printFraction(v.at(i));
		cout << "  ";
	}
	cout << endl;
}


void printFraction(const Fraction &f){
	cout << f.getNumerator() << "/" << f.getDenominator();
}

