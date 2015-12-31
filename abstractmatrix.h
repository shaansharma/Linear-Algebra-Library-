// Created by Zain Humayun on December 24th, 2015
// abstractmatrix.h: Header for abstractmatrix.cc, class definition for AbstractMatrix. (NOT 0 based like arrays)
// Purpose: Base Abstract Class for Matrix and Vector classes

#ifndef ABSTRACT_MATRIX_H
#define ABSTRACT_MATRIX_H
#include <vector>
#include <string>
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
	AbstractMatrix(const AbstractMatrix &other);
	
	AbstractMatrix(int *array, const int nr, const int nc);
	AbstractMatrix(Fraction **array, const int nr, const int nc);
	AbstractMatrix(std::vector<Fraction> &v, const int nr, const int nc);
	AbstractMatrix(const std::string &fileName);
	
	AbstractMatrix &operator=(const AbstractMatrix &other);

	// deletes all heap allocated memory
	virtual ~AbstractMatrix() = 0;

	// overwrites theGrid, but tries to delete it before overwriting
	void setData(const int *array, const int r, const int c);
	void setData(Fraction **array, const int r, const int c);
	void setData(std::vector<Fraction> &v, const int r, const int c);	

	// throws exception if row or col are out of bounds
	Fraction at(const int row, const int col = 1) const;
		
	void replace(const Fraction &f, const int row, const int col = 1);
	void replace(const int i, const int row, const int col = 1);

	// getters
	int getNumRows() const;
	int getNumColumns() const;

	// setters
	void setNumRows(const int r);
	void setNumColumns(const int c);

	// returns true if and only if the two matrices are scalar multiples of eachother
	bool isScalarMultipleOf(const AbstractMatrix &other) const;
};

#endif
