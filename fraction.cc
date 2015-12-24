#include "fraction.h"
#include <stdexcept>

using namespace std;

// see fraction.h for documentation
void Fraction::reduce(){
	int gcd = gcd(abs(this->num), abs(this->den));
	this->num /= gcd;
	this->den /= gcd;

	// fix negative signs
	if(this->den < 0){
		this->num *= -1;
		this->den *= -1;
	}
}

int Fraction::gcd(const int a, const int b){
	return b == 0 ? a : gcd(b, a % b);
}

int Fraction::abs(const int a){
	return a < 0 ? -1 * a : a;
}

// ctors
Fraction::Fraction(const int num = 1, const int den = 1): num(num), den(den){}

Fraction::Fraction(const Fraction &other): num(other.num), den(other.den){}

// getters and setters
void Fraction::setNumerator(const int num){
	this->num = num;
	reduce();
}

// requires denom is not 0
void Fraction::setDenominator(const int denom){
	if(denom == 0) throw invalid_argument("Cannot give denominator value of 0");
	this->den = denom;
	reduce();
}

int Fraction::getNumerator() const{
	return this->num;
}

int Fraction::getDenominator() const{
	return this->den;
}

bool Fraction::isWhole() const{
	return this->den == 1;
}



