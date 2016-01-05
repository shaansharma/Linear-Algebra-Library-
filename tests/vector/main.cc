#include "vector.h"
#include <vector>
#include "fraction.h"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

int main(){
	// Vector 1 contains 
	//	1, 2, 3
	vector<Fraction> temp;
	temp.push_back(Fraction(1));
	temp.push_back(Fraction(2));
	temp.push_back(Fraction(3));

	Vector v1(temp);

	// conatins same elements as v1
	Vector v2 = v1;

	// check vectors are the same
	assert(v2.getSquareSize() == v1.getSquareSize());
	assert(v2.getDimension() == v1.getDimension());

	for(int i = 1; i <= v1.getDimension(); i++){
		assert(v1[i] == v2[i]);
	}
	return 0;
	// make sure a seperate copy is made, i.e vectors are not sharing same memory
	//	assert(&(v1[0]) != &(v2[0]));

	v2[0] = Fraction(3);
	v2[1] = Fraction(2);
	v2[2] = Fraction(1);

	assert(v1[0] != v2[0]);

	cout << v1 << endl << v2 << endl;
	Vector v3 = v1.projectionOnto(v2);

	assert(v3[0] == Fraction(15, 7));
	assert(v3[1] == Fraction(10, 7));
	assert(v3[2] == Fraction(5, 7));
}
