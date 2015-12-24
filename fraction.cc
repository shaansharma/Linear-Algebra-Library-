#include "fraction.h"

// see fraction.h for documentation
void Fraction::reduce(){
	int gcd = gcd(abs(this->num), abs(this->den));
	this->num /= gcd;
	this->den /= gcd;

	// fix negative signs
	if(
}

int Fraction::gcd(const int a, const int b){
	return b == 0 ? a : gcd(b, a % b);
}

int Fraction::abs(const int a){
	return a < 0 ? -1 * a : a;
}
