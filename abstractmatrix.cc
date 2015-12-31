#include "fraction.h"
#include "abstractmatrix.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

using namespace std;

AbstractMatrix::AbstractMatrix(const int nr, const int nc): numRows(nr), numCols(nc), theGrid(new Fraction*[nr * nc]){
	const int size = nr * nc;
	for(int i = 0; i < size; i++){
		this->theGrid[i] = NULL;
	}
}

AbstractMatrix::AbstractMatrix(int *array, const int nr, const int nc): numRows(nr), numCols(nc), theGrid(NULL){
	setData(array, nr, nc);
}

AbstractMatrix::AbstractMatrix(Fraction **array, const int nr, const int nc): numRows(nr), numCols(nc), theGrid(NULL){
	setData(array, nr, nc);
}

AbstractMatrix::AbstractMatrix(vector<Fraction> &v, const int nr, const int nc): numRows(nr), numCols(nc), theGrid(NULL){
	setData(v, nr, nc);
}

AbstractMatrix::AbstractMatrix(const string &fileName){
	
}

// deletes theGrid
AbstractMatrix::~AbstractMatrix(){
	deleteGrid();	
}

AbstractMatrix::AbstractMatrix(const AbstractMatrix &other){
	this->theGrid = new Fraction *[other.numRows * other.numCols];
	this->numRows = other.numRows;
	this->numCols = other.numCols;
	
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
	if(this->theGrid == NULL) return;

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

void AbstractMatrix::setData(vector<Fraction> &v, const int r, const int c){
	deleteGrid();
	this->numRows = r;
	this->numCols = c;

	const int size = r * c;
	this->theGrid = new Fraction*[size];

	for(int i = 0; i < size; i++){
		this->theGrid[i] = new Fraction(v.at(i));
	}
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

bool AbstractMatrix::isScalarMultipleOf(const AbstractMatrix &other) const{
	if(this->numRows != other.numRows || this->numCols != other.numCols) return false;
	
	const int size = this->numRows * this->numCols;
	
	if(size <= 0) return false;
	Fraction factor; // initialized to 0
	bool LHSZero = false;	

	if(*this->theGrid[0] != Fraction::Zero && *other.theGrid[0] != Fraction::Zero){
		factor = *this->theGrid[0] / *other.theGrid[0];
	} else if(*this->theGrid[0] == Fraction::Zero){
		LHSZero = true;
	}
	
	for(int i = 1; i < size; i++){
		if(factor == Fraction::Zero){
			if(LHSZero){ // check that the LHS is zero
				if(*this->theGrid[i] != Fraction::Zero) return false;
			} else { // check RHS is zero
				if(*other.theGrid[i] != Fraction::Zero) return false;
			}
		} else { // divide fractions, check factor
			if(factor != *this->theGrid[i] / *other.theGrid[i]) return false;
		}
	}	

	return true;
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


