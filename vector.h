// Created by Zain Humayun on December 25th, 2015
// vector.h: Header for vector.cc, class definition for Vector
// Purpose: Concrete AbstractMatrix that is a Vector

#ifndef VECTOR_H
#define VECTOR_H
#include "abstractmatrix.h"
class Fraction;

class Vector : public AbstractMatrix {
	
	public:
	Vector(int *array, const int r);
	Vector(const int r);
	Vector(Fraction **array, const int r);
	Vector(const Vector &other);
	
	Vector &operator=(const Vector &other);

	// returns the vector length 
	double getSize() const;

	// projection of *this onto given Vector
	Vector projectionOnto(const Vector &other);

	// perpendicular of *this onto given Vector
	Vector perpendicularOnto(const Vector &other);
};

// scalar product
Vector operator*(const int factor, const Vector &v);
Vector operator*(const Vector &v, const int factor);
Vector operator*(const Fraction &f, const Vector &v);
Vector operator*(const Vector &v, const Fraction &f);

// dot product
int operator*(const Vector &v1, const Vector &v2);

// cross product
Vector operator%(const Vector &v1, const Vector &v2);

// addition
Vector operator+(const Vector &v1, const Vector &v2);

// two vectors are orthogonal if the angle between them is 90 degrees (pi/2 radians)
bool areOrthogonal(const Vector &v1, const Vector &v2);
#endif
