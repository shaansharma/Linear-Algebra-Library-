// Created by Zain Humayun on December 31st, 2015
// spanningset.h: Header file for spanningset.cc, class definition for SpanningSet
// Purpose: Contains a list of Vectors that are meant to be part of a set. Has methods for linear independance and 
//				standard basis.

#ifndef SPANNING_SET_H
#define SPANNING_SET_H

#include "vector.h"
#include <vector>

class Matrix;

class SpanningSet {
	vector<Vector> set;

	public:
	// throws exception if Vectors are not of same dimension
	SpanningSet(const std::vector<Vector> &v);
	SpanningSet(const SpanningSet &other);

	// returns number of vectors in set
	int getNumVectors() const;

	// returns true if no linear combination of vectors in the set equals another in the set
	bool isLinearlyIndependent() const;

	// returns the vector at location i
	// 0 indexed.
	Vector at(const int i) const;
	Vector operator[](const int i) const;
	
	// converts set to matrix
	Matrix toMatrix() const;
};

static SpanningSet getStandardBasis(const int dimension);
#endif
