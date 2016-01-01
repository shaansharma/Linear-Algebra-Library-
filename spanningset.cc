#include "spanningset.h"
#include <vector>
#include "vector.h"
#include "fraction.h"
#include <stdexcept>

using namespace std;

// constructors
SpanningSet::SpanningSet(const vector<Vector> &v){
	const int size = v.size();
	if(size > 0){
		const int dimension = v.at(0).getDimension();
		for(int i = 1; i < size; i++){
			if(v.at(i).getDimension() != dimension) throw invalid_argument("Vectors must be of same dimension");
		}
	}
	this->set = other.set; 
}

SpanningSet::SpanningSet(const SpanningSet &other): set(other.set){}

int SpanningSet::getNumVectors() const{
	return this->set.size();
}

// TODO: finish method; -> convert to matrix -> row reduce -> check rank
bool SpanningSet::isLinearlyIndependent() const{
	return true;
}

Vector SpanningSet::at(const int i) const{
	return this->set.at(i);
}

Vector SpanningSet::operator[](const int i) const{
	return at(i);
}


Matrix SpanningSet::toMatrix() const {
	const int numCols = getNumVectors();
	const int numRows = this->set.at(0).getDimension();

	Fraction **array = new Fraction*[numCols * numRows];	
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			array[i * numCols + j] = new Fraction(this->set.at(j).at(i + 1));	
		}
	}
	return Matrix(array, numRows, numCols);
}

static SpanningSet getStandardBasis(const int dimension){
	vector<Vector> v; // store vectors in this, give to constructor
	
	for(int i = 0; i < dimension; i++){
		Fraction **array = new Fraction*[dimension];
		for(int j = 0; j < dimension; j++){
			// fraction is either 1 if and only if i == j
			array[j] = new Fraction(i == j ? 1 : 0);
			v.push_back(Vector(array), dimension);
		}
	}
	return SpanningSet(v);
}
