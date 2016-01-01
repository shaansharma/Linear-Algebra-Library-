#include "spanningset.h"
#include <vector>
#include "vector.h"
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

// TODO: finish method
bool SpanningSet::isLinearlyIndependent() const{
	return true;
}

Vector SpanningSet::at(const int i) const{
	return this->set.at(i);
}

Vector SpanningSet::operator[](const int i) const{
	return at(i);
}

// TODO: finish method
Matrix SpanningSet::toMatrix() const{
	
}

// TODO: finish method
static SpanningSet SpanningSet::getStandardBasis(const int dimension){
	
}
