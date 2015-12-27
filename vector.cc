#include "vector.h"
#include "abstractmatrix.h"
#include "fraction.h"
#include <cmath>

// constructors

Vector::Vector(int *array, const int r): AbstractMatrix(r, 1){
	setData(array, r, 1);
}

Vector::Vector(const int r): AbstractMatrix(r, 1){}

Vector::Vector(Fraction **array, const int r): AbstractMatrix(r, 1){
	setData(array, r, 1);
}

// copy constructor
Vector::Vector(const Vector &other): AbstractMatrix(other){}

Vector &Vector::operator=(const Vector &other){
	AbstractMatrix::operator=(other);
	return *this;
}

double Vector::getSize() const{
	Fraction sum(0);
	
	for(int i = 0; i < getNumRows(); i++){
		sum += at(i) * at(i);
	}

	return sqrt(sum.toDouble());
}
