#include "fraction.h"
#include "abstractmatrix.h"
#include <iostream>
#include <stdexcept>

using namespace std;

AbstractMatrix::AbstractMatrix(const int nr, const int nc): numRows(nr), numCols(nc), theGrid(new Fraction*[nr * nc]){}

// deletes theGrid
AbstractMatrix::~AbstractMatrix(){
	deleteGrid();	
}

AbstractMatrix::AbstractMatrix(const AbstractMatrix &other){
	this->theGrid = new Fraction *[other.numRows * other.numCols];
	this->numRows = other.numRows;
	this->numCols = other.numRows;
	
	const int size = this->numRows * this->numCols;
	for(int i = 0; i < size; i++){
		this->theGrid[i] = new Fraction(*other.theGrid[i]);
	}
}

AbstractMatrix &AbstractMatrix::operator=(const AbstractMatrix &other){
	deleteGrid();
	this->theGrid = new Fraction *[other.numRows * other.numCols];
	this->numRows = other.numRows;
	this->numCols = other.numRows;
	
	const int size = this->numRows * this->numCols;
	for(int i = 0; i < size; i++){
		this->theGrid[i] = new Fraction(*other.theGrid[i]);
	}
}

// deletes theGrid and all of it's contents
void AbstractMatrix::deleteGrid(){
	int size = this->numRows * this->numCols;
	
	for(int i = 0; i < size; i++){
		delete this->theGrid[i];
		this->theGrid[i] = NULL;
	}

	delete [] this->theGrid;
	this->theGrid = NULL;
}

// setData(...) tries to delete theGrid and then constructs a new Fraction array from the given integer array
void AbstractMatrix::setData(const int *array, const int r, const int c){
	deleteGrid();
	this->theGrid = new Fraction *[r * c];
	this->numRows = r;
	this->numCols = c;
	
	const int size = r * c;
	for(int i = 0; i < size; i++){
		this->theGrid[i] = new Fraction(array[i]);
	}
}

void AbstractMatrix::setData(Fraction **array, const int r, const int c){
	deleteGrid();
	this->theGrid = array;
	this->numRows = r;
	this->numCols = c;
}

void AbstractMatrix::checkBounds(const int row, const int col) const{
	if(row < 1 || col < 1) throw out_of_range("Cannot access entry that is less than 1");
	if(row > this->numRows || col > this->numCols) throw out_of_range("Row/Col out of range");
}

// at(...) returns a new Fraction object at the location of the given row and column
// throws and exception if the given row and column are out of bounds
// use: at(r, c) for Matrix
//		  at(r) for Vector
Fraction AbstractMatrix::at(const int row, const int col) const{
	checkBounds(row, col);	
	return *this->theGrid[(row-1) * this->numCols + (col-1)];
}


void AbstractMatrix::replace(const Fraction &f, const int row, const int col){
	checkBounds(row, col);
	delete this->theGrid[(row-1) * this->numCols + (col-1)];
	this->theGrid[(row-1) * this->numCols + (col-1)] = new Fraction(f);
}

void AbstractMatrix::replace(const int i, const int row, const int col){
	checkBounds(row, col);
	delete this->theGrid[(row-1) * this->numCols + (col-1)];
	this->theGrid[(row-1) * this->numCols + (col-1)] = new Fraction(i);
}

// getters
int AbstractMatrix::getNumRows() const{
	return this->numRows;
}

int AbstractMatrix::getNumColumns() const{
	return this->numCols;
}

// setters
void AbstractMatrix::setNumRows(const int r){
	if(r < 0) throw out_of_range("Cannot set row below 0");
	this->numRows = r;
}

void AbstractMatrix::setNumColumns(const int c){
	if(c < 0) throw out_of_range("Cannot set column below 0");
	this->numCols = c;
}


