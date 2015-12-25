#include "fraction.h"
#include "abstractmatrix.h"
#include <iostream>

using namespace std;

AbstractMatrix::AbstractMatrix(const int nr, const int nr): numRows(nr), numCols(nc), theGrid(NULL){}

// deletes theGrid
AbstractMatrix::~AbstractMatrix(){
	
}

// deletes theGrid and all of it's contents
void AbstractMatrix::deleteGrid(){
	int size = this->numRows * this->numCols;
	
	for(int i = 0; i < size; i++){
		delete this->theGrid[i];
	}

	delete [] this->theGrid;
}
