#include "fraction.h"
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

const Fraction Fraction::Zero = Fraction(0,1);

// see fraction.h for documentation
void Fraction::reduce(){
	int GCD = gcd(abs(this->num), abs(this->den));
	this->num /= GCD;
	this->den /= GCD;

	// fix negative signs
	if(this->den < 0){
		this->num *= -1;
		this->den *= -1;
	}
}

double Fraction::toDouble() const{
	return static_cast<double>(this->num)/this->den;
}

Fraction Fraction::reciprocal() const{	
	if(this->den == 0) throw logic_error("0 has no real reciprocal");
	return Fraction(this->den, this->num);
}

int Fraction::gcd(const int a, const int b) const{
	return b == 0 ? a : gcd(b, a % b);
}

int Fraction::abs(const int a) const{
	return a < 0 ? -1 * a : a;
}

Fraction Fraction::getAbsolute() const {
	return Fraction(abs(this->num), abs(this->den));
}

// ctors
Fraction::Fraction(const int num, const int den): num(num), den(den){
	reduce();
}

Fraction::Fraction(const Fraction &other): num(other.num), den(other.den){}

// expects a valid fraction as string
Fraction::Fraction(const string &s){
	stringstream in(s);
	
	in >> this->num;
	char garbage;
	in >> garbage;
	
	// read denominator
	if(!in.eof()){
		in >> this->den;
	} else {
		this->den = 1;
	}
	reduce();
}

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


Fraction &Fraction::operator=(const Fraction &other){
	this->num = other.num;
	this->den = other.den;
}


Fraction &Fraction::operator+=(const Fraction &other){
	*this = *this + other;
	return *this;	
}

Fraction &Fraction::operator*=(const Fraction &other){
	*this = *this * other;
	return *this;
}

Fraction &Fraction::operator-=(const Fraction &other){
	*this = *this - other;
	return *this;
}

Fraction &Fraction::operator/=(const Fraction &other){
	*this = *this * other.reciprocal();
	return *this;
}

Fraction &Fraction::operator++(int i){
	this->num += this->den;
	reduce();
	return *this;
}

Fraction &Fraction::operator--(int i){
	this->num -= this->den;
	reduce();
	return *this;
}

// common math operators (non member functions)

// a/b + c/d = (ad + cb)/bd
Fraction operator+(const Fraction &f1, const Fraction &f2){
	Fraction f3((f1.getNumerator() * f2.getDenominator()) + 
					(f2.getNumerator() * f1.getDenominator()), 
					f1.getDenominator() * f2.getDenominator());
	f3.reduce();
	return f3;
}

Fraction operator-(const Fraction &f1, const Fraction &f2){
	return f1 + (f2 * -1);
}

// a/b * c/d = ac/bd
Fraction operator*(const Fraction &f1, const Fraction &f2){
	Fraction f3(f1.getNumerator() * f2.getNumerator(), f1.getDenominator() * f2.getDenominator());
	f3.reduce();
	return f3;
}

Fraction operator*(const Fraction &f, const int factor){
	Fraction f2(f.getNumerator() * factor, f.getDenominator());
	f2.reduce();
	return f2;
}

Fraction operator*(const int factor, const Fraction &f){
	return f * factor;
}

Fraction operator/(const Fraction &f1, const Fraction &f2){
	return f1 * f2.reciprocal();
}

bool operator<(const Fraction &f1, const Fraction &f2){
	if(f1.getDenominator() == f2.getDenominator()){
		return f1.getNumerator() < f2.getNumerator();
	}

	long n1 = f1.getNumerator() * f2.getDenominator();
	long n2 = f2.getNumerator() * f1.getDenominator();
	return n1 < n2;
}

bool operator>(const Fraction &f1, const Fraction &f2){
	return f2 < f1;
}

bool operator==(const Fraction &f1, const Fraction &f2){
	// assumes f1, and f2 are already reduced
	return f1.getNumerator() == f2.getNumerator() && f1.getDenominator() == f2.getDenominator();
}

bool operator!=(const Fraction &f1, const Fraction &f2){
	return !(f1 == f2);
}

bool operator<=(const Fraction &f1, const Fraction &f2){
	return f1 < f2 || f1 == f2;
}

bool operator>=(const Fraction &f1, const Fraction &f2){
	return f1 > f2 || f1 == f2;
}


