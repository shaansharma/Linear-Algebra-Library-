// Created by Zain Humayun on December 24th, 2015
// abstractmatrix.h: Header for abstractmatrix.cc, class definition for AbstractMatrix.
// Purpose: Base Abstract Class for Matrix and Vector classes

#ifndef ABSTRACT_MATRIX_H
#define ABSTRACT_MATRIX_H
class Fraction;

class AbstractMatrix{
	protected:	
   int numRows, numCols;
	Fraction **theGrid;

	void deleteGrid();
	void checkBounds(const int row, const int col) const;

	public:
	// takes in number of rows and columns, should be positive integers.
	AbstractMatrix(const int nr, const int nc);
	
	// deletes all heap allocated memory
	virtual ~AbstractMatrix() = 0;

	// overwrites theGrid, but tries to delete it before overwriting
	void setData(const int *array, const int r, const int c);
	void setData(Fraction **array, const int r, const int c);

	// throws exception if row or col are out of bounds
	Fraction at(const int row, const int col = 0) const;
	
	
	void replace(const Fraction &f, const int row, const int col = 0);
	void replace(const int i, const int row, const int col = 0);

	// getters
	int getNumRows() const;
	int getNumColumns() const;

	// setters
	void setNumRows(const int r);
	void setNumColumns(const int c);
};

#endif
