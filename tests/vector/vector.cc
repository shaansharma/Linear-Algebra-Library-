#include "vector.h"
#include "abstractmatrix.h"
#include "fraction.h"
#include <cmath>
#include <stdexcept>
#include <vector>
#include <ostream>

using namespace std;

// constructors

Vector::Vector(int *array, const int r): AbstractMatrix(array, r, 1){}

Vector::Vector(const int r): AbstractMatrix(r, 1){}

Vector::Vector(Fraction **array, const int r): AbstractMatrix(array, r, 1){}

Vector::Vector(vector<Fraction> &v): AbstractMatrix(v, v.size(), 1){}

// copy constructor
Vector::Vector(const Vector &other): AbstractMatrix(other){}

Vector &Vector::operator=(const Vector &other){
	AbstractMatrix::operator=(other);
	return *this;
}

Fraction &Vector::operator[](const int index){
	return *this->theGrid[index - 1];
}

int Vector::getDimension() const{
	return this->numRows;
}

double Vector::getSize() const{
	return sqrt(getSquareSize().toDouble());
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
	Fraction factor = (this->operator*(other)) * other.getSquareSize().reciprocal();
	Vector projection = factor * other;
	return projection;
}

Vector Vector::perpendicularOnto(const Vector &other) const{
	return this->operator-(this->projectionOnto(other));
}

// Scalar Product

Vector Vector::operator*(const int factor) const{
	Fraction f(factor);
	return this->operator*(f);
}

Vector Vector::operator*(const Fraction &f) const{
	Vector newVector = *this;

	for(int i = 0; i < this->numRows; i++){
		*newVector.theGrid[i] *= f;
	}

	return newVector;
}

Vector operator*(const Fraction &f, const Vector &v){
	return v * f;
}

Vector operator*(const int factor, const Vector &v){
	return v * factor;
}

// dot product
Fraction Vector::operator*(const Vector &other) const{
	// throw exception if vectors are not same length
	if(!areSameDimension(*this, other)) throw invalid_argument("Vectors must be of same dimension");

	Fraction sum(0);
	for(int i = 0; i < this->numRows; i++){
		sum += *other.theGrid[i] * *this->theGrid[i];
	}

	return sum;
}

// TODO: cross product for 3-d vector

// Addition
Vector Vector::operator+(const Vector &other) const{
	// throw exception if vectors are not same length
	if(!areSameDimension(*this, other)) throw invalid_argument("Vectors must be of same dimension");

	Fraction **array = new Fraction*[this->numRows];

	for(int i = 0; i < this->numRows; i++){
		Fraction *f = new Fraction(*this->theGrid[i] + *other.theGrid[i]);
		array[i] = f;
	}

	Vector v(array, this->numRows);
	return v;
}

// subtraction
Vector Vector::operator-(const Vector &other) const{
	Vector negative = other * -1;
	return this->operator+(negative);
}

// see .h file
bool areSameDimension(const Vector &v1, const Vector &v2){
	return v1.getNumRows() == v2.getNumRows();
}

// two vectors are orthogonal if their dot product is 0
bool areOrthogonal(const Vector &v1, const Vector &v2){
	return v1 * v2 == 0;
}

ostream &operator<<(ostream &out, Vector &v){
	int size = v.getDimension();

	for(int i = 1; i <= size; i++){
		out << v[i];
		if(i != size){
			out << " ";
		}
	}
	return out;
}
