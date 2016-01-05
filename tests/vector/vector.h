// Created by Zain Humayun on December 25th, 2015
// vector.h: Header for vector.cc, class definition for Vector
// Purpose: Concrete AbstractMatrix that is a Vector

#ifndef VECTOR_H
#define VECTOR_H
#include "abstractmatrix.h"
#include <vector>
#include <ostream>

class Fraction;

class Vector : public AbstractMatrix {
	
	public:
	Vector(int *array = 0, const int r = 1);
	Vector(const int r);
	Vector(Fraction **array = 0, const int r = 1);
	Vector(const Vector &other);
	Vector(std::vector<Fraction> &v);
	
	Vector &operator=(const Vector &other);

	// returns the vector length 
	double getSize() const;
	// returns the square of the size, for the most accurate size
	Fraction getSquareSize() const;

	// projection of *this onto given Vector
	Vector projectionOnto(const Vector &other) const;

	// perpendicular of *this onto given Vector
	Vector perpendicularOnto(const Vector &other) const;

	// scalar product
	Vector operator*(const int factor) const;
	Vector operator*(const Fraction &f) const;

	// dot product
	Fraction operator*(const Vector &other) const;

	// cross product
	Vector operator%(const Vector &other) const;

	// addition
	Vector operator+(const Vector &other) const;

	// subtraction
	Vector operator-(const Vector &other) const;

	// operator[] does not check for bounds, and returns a reference for direct manipulation
	// operator[] is NOT 0 indexed
	Fraction &operator[](const int index);

	// returns the number of rows in vector
	int getDimension() const;
};

// scalar profuct
Vector operator*(const int factor, const Vector &v);
Vector operator*(const Fraction &f, const Vector &v);

// two vectors are orthogonal if the angle between them is 90 degrees (pi/2 radians)
bool areOrthogonal(const Vector &v1, const Vector &v2);

// returns true if and only if two vectors are of the same dimension
bool areSameDimension(const Vector &v1, const Vector &v2);

// operator<< for vectors
std::ostream &operator<<(std::ostream &out, Vector &v);
#endif
