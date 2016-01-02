#include "matrix.h"
#include "vector.h"
#include <vector>
#include "fraction.h"

using namespace std;

// constructors

Matrix::Matrix(int *array, const int r, const int c): AbstractMatrix(array, r, c){}
Matrix::Matrix(Fraction **array, const int r, const int c): AbstractMatrix(array, r, c){}
Matrix::Matrix(vector<Fraction> &v, const int r, const int c): AbstractMatrix(v, r, c){}
Matrix::Matrix(const Matrix &other){
	AbstractMatrix(other);
}

void Matrix::checkBounds(const Matrix &other){
	if(this->numRows != other.numRows || this->numCols != other.numCols) 
		throw invalid_argument("Matrices must be of the same size for use of operator");
}

// returns the column at given index
Vector Matrix::operator[](const int index){
	Fraction **array = new Fraction*[getNumRows()];
	
	for(int i = 0; i < getNumRows(); i++){
		array[i] = this->theGrid[i * getNumColumns() + (index - 1)];
	}

	return Vector(array, getNumRows()); 
}

// TODO: use guass jordan elimination to complete method
Matrix &Matrix::rowReduce(){
	return *this;
}

// returns copies of entries (not the actual entries)
SpanningSet Matrix::getColumnSpace() const{
	
}

SpanningSet Matrix::getRowSpace() const{

}

// TODO: look at all leading ones after copy
int Matrix::getRank() const{
	Matrix copy = *this;
	copy.rowReduce();

	// loop through rows
}

// throws exception if matrices are of different sizes
Matrix Matrix::operator+(const Matrix &other) const{
	checkBounds(other);
	const int size = this->numRows * this->numCols;
	
	Fraction **array = new Fraction *[size];
	for(int i = 0; i < size; i++){
		array[i] = new Fraction(*this->theGrid[i] + *other.theGrid[i]);
	}	
	
	return Matrix(array, this->numRows, this->numCols);
}

Matrix Matrix::operator-(const Matrix &other) const{
	checkBounds(other);

	const int size = this->numRows * this->numCols;
	
	Fraction **array = new Fraction *[size];
	for(int i = 0; i < size; i++){
		array[i] = new Fraction(*this->theGrid[i] - *other.theGrid[i]);
	}

	return Matrix(array, this->numRows, this->numCols);
}

// TODO
Matrix Matrix::operator*(const Matrix &other) const{
	
}

Matrix &Matrix::operator+=(const Matrix &other){
	*this = *this + other;
	return *this;
}

Matrix &Matrix::operator-=(const Matrix &other){
	*this = *this - other;
	return *this;
}

// TODO
Matrix &Matrix::operator*=(const AbstractMatrix &other){

}

// TODO
Matrix &Matrix::transpose(){
	
}

// TODO
bool Matrix::hasRightInverse() const{

}

// TODO
bool Matrix::hasLeftInverse() const{

}

// TODO
Matrix Matrix::getInverse() const{
	
}

// TODO
bool Matrix::isInvertible() const{
	
}

// TODO
bool Matrix::isRREF() const{

}

bool Matrix::operator==(const Matrix &other) const{
	if(this->numRows != other.numRows || this->numCols != other.numCols) return false;	

	const int size = this->numRows * this->numCols;

	for(int i = 0; i < size; i++){
		if(*this->theGrid[i] != *other.theGrid[i]) return false;
	}

	return true;
}

Matrix &Matrix::operator=(const Matrix &other){
	AbstractMatrix::operator=(other);
}

bool Matrix::operator!=(const Matrix &other) const{
	return !(*this == other);
}

// TODO
Matrix Matrix::getSubMatrix(const int startRow, const int startCol) const{

}

// TODO
Fraction Matrix::getDeterminant() const{

}

// TODO
bool Matrix::isUpperTriangular() const{
	
}

// TODO
bool Matrix::isLowerTriangular() const{

}

// TODO
Matrix &Matrix::rotateRight(){
	return *this;
}

// TODO
Matrix &Matrix::rotateLeft(){
	return *this;
}

// TODO
Fraction Matrix::getCofactor(const int i, const int j) const{

}

// TODO
Fraction Matrix::getAdjugate(const int i, const int j) const{

}

// TODO
bool Matrix::isDiagonal() const{

}

// TODO
bool Matrix::hasEigenVector(const Vector &v) const{

}

// TODO
Fraction Matrix::getEigenValue(const Vector &v) const{

}

// TODO
bool Matrix::isDiagonalizedBy(const Matrix &m) const{

}

// TODO
static Matrix Matrix::getIdentityMatrix(const int n){

}

// TODO
Matrix buildAugmentedMatrix(const AbstractMatrix &ab1, const AbstractMatrix &ab2){

}

// TODO 
Matrix buildDiagonalMatrix(const int *array){

}

// TODO
Matrix buildDiagonalMatrix(const std::vector<Fraction> &v){

}

// TODO
Matrix buildDiagonalMatrix(const Fraction **array){

}

// TODO
bool areRowEquivalent(const Matrix &m1, const Matrix &m2){
	
}
