// Created by Zain Humayun on December 30th, 2015
// matrix.h: Header file for matrix.cc, class definition for Matrix
// Purpose: Used for representing a Matrix and various methods / functions for operations on matrices.

#ifndef MATRIX_H
#define MATRIX_H
#include "abstractmatrix.h"
#include <vector>

class Vector;
class Fraction;
class SpanningSet;
//class EigenPair;

class Matrix : public AbstractMatrix {
	// throws exception if *this and other have different sizes
	void checkBounds(const Matrix &other);
	
	public:

	// constructors
	Matrix(int *array, const int r, const int c);
	Matrix(Fraction **aray, const int r, const int c);
	Matrix(std::vector<Fraction> &v, const int r, const int c);
	Matrix(const Matrix &other);
	
	// matrix[index] returns the horizontal Vector located at row [index] - 1.
	// operator[] is NOT 0 indexed (to keep consistent with the mathimatical definition).
	// this operator can be used to directly change the value located at this index. 
	Vector operator[](const int index);

	// uses guass jordan elimination to row reduce the matrix, returns a reference to the reduced matrix.
	Matrix &rowReduce();

	// returns the set of vectors that make up the matrix horizontally
	SpanningSet getColumnSpace() const;
	
	// return the set of vectors that make up the matrix vertically
	SpanningSet getRowSpace() const;

	// returns the number of leading ones in the RREF of the matrix.
	int getRank() const;
	
	// returns the addition of Matrices this and other
	Matrix operator+(const Matrix &other) const;

	// returns the substraction of Matrix other from this (this - other).
	Matrix operator-(const Matrix &other) const;

	// returns the multiplication of a Matrix or Vector with this.
	Matrix operator*(const AbstractMatrix &other) const;

	Matrix &operator+=(const Matrix &other);

	Matrix &operator-=(const Matrix &other);
	
	Matrix &operator*=(const AbstractMatrix &other);

	// each element at location (i, j) is now located at (j, i)
	Matrix &transpose();

	// returns true if and only if there exists a matrix B such that this * B = identity matrix
	bool hasRightInverse() const;

	// returns true if and only if there exists a matrix B such that b * this = identity matrix
	bool hasLeftInverse() const;

	// returns the inverse of matrix, throws an exception if one doesnt exist.
	Matrix getInverse() const;

	// returns true if and only if matrix is invertible
	bool isInvertible() const;

	// returns true if and only if matrix is in RREF (Reduced Row-Echelon Form)
	bool isRREF() const;

	// returns true if and only if the two matrices are the same size, and share the same entries for each position
	bool operator==(const Matrix &other) const;

	// sets current matrix to be identical to other 
	Matrix &operator=(const Matrix &other);

	// returns true if and only if the two matrices are NOT equal (==)
	bool operator!=(const Matric &other) const;

	// returns the matrix contained in this, that spans from the given arguments to the bottom right 
	// throws an exception if tbe given arguments are out of bounds
	// throws an exception if the sub matrix is less than 1x1 
	// requires: startRow and startCol > 0.
	Matrix getSubMatrix(const int startRow, const int startCol) const; 

	// returns the determinant of the matrix
	Fraction getDeterminant() const;

	// returns true if and only if all entries below the diagonal of the matrix is 0
	// requires the matrix is nxn (throws exception otherwise)
	bool isUpperTriangular() const;

	// returns true if and only if all entries above the diagonal of the matrix is 0
	// requies the matrix is nxn (throws exception otherwise)
	bool isLowerTriangular() const;

	// rotates the matrix clockwise
	Matrix &rotateRight();

	// rotates the matrix counter-clockwise
	Matrix &rotateLeft();

	Fraction getCofactor(const int i, const int j) const;
	Fraction getAdjugate(const int i, const int j) const;

	// returns true if and only if all entries that are not along the diagonal are 0
	bool isDiagonal() const;

	// returns true if the given vector is a eigen vector of the matrix
	bool hasEigenVector(const Vector &v) const;

	// returns the Eigen value for the given vector, throws an exception if given vector is not
	// an eigen vector of the matrix. 
	Fraction getEigenValue(const Vector &v) const;

	// returns the eigen pair if one exists for the given vector
	// EigenPair getEigenPair(const Vector &v) const;

	// returns true if and only if the given matrix diagnoalizes this matrix
	bool isDiagonalizedBy(const Matrix &m) const;

	// returns a nxn Identity Matrix
	static Matrix getIdentityMatrix(const int n);
};

// returns the concatination (horizontally) of ab1 and ab2
Matrix buildAugmentedMatrix(const AbstractMatrix &ab1, const AbstractMatrix &ab2);

// returns the diagonal matrix with the given params
Matrix buildDiagonalMatrix(const int *array);
Matrix buildDiagonalMatrix(const std::vector<Fraction> &v);
Matrix buildDiagonalMatrix(const Fraction **array);

// returns true if two matrices share the same row space
bool areRowEquivalent(const Matrix &m1, const Matrix &m2);
#endif
