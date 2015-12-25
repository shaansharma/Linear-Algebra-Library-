// Created by Zain Humayun on December 24th, 2015
// abstractmatrix.h: Header for abstractmatrix.cc, class definition for AbstractMatrix.
// Purpose: Base Abstract Class for Matrix and Vector classes

#ifndef ABSTRACT_MATRIX_H
#define ABSTRACT_MATRIX_H
class Fraction;

class AbstractMatrix{
	const int numRows, numCols;
	Fraction *theGrid;

	void deleteGrid();

	public:
	// takes in number of rows and columns, should be positive integers.
	AbstractMatrix(const int nr, const int nc);
	
	// deletes all heap allocated memory
	virtual ~AbstractMatrix() = 0;

	// overwrites theGrid, but tries to delete it before overwriting
	void setData(const int *array);
	void setData(const Fraction *array);

	// throws exception if row or col are out of bounds
	Fraction at(const int row, const int col) const;
	
	// returns refrences to the fraction you replace
	Fraction &replace(const Fraction f, const int row, const int col);
	Fraction &replace(const int i, const int row, const int col);

	// getters
	int getNumRows() const;
	int getNumColums() const;
};

#endif
