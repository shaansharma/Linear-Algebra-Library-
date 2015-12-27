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
	return sqrt(getSquareSum().toDouble());
}

Fraction Vector::getSquareSize() const{
	Fraction sum(0);

	// matrices are not 0 indexed
	for(int i = 1; i <= getNumRows(); i++){
		sum += (at(i) * at(i)); 
	}

	return sum; 
}

Vector Vector::projectionOnto(const Vector &other) const{
	Fraction factor = (*this * other) * other.getSquareSize().reciprocal();
	Vector projection = factor * other;
	return projection;
}

Vector Vector::perpendicularOnto(const Vector &other) const{
	return *this - this->projectionOnto(other);
}

// Scalar Product
