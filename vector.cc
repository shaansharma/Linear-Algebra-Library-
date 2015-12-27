#include "vector.h"
#include "abstractmatrix.h"
#include "fraction.h"

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
