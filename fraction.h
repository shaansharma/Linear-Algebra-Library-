// Created by Zain Humayun on December 23rd, 2015
// fraction.h: Header for fraction.cc, class definition for Fraction.
//	Purpose: Used for storing numbers as rational expressions, aswell as performing basic operations on them

#ifndef FRACTION_H
#define FRACTION_H
#include <stdexcept>
#include <string>

class Fraction{
	int num, den;
	private:
	
	// returns the greatest common divisor of a and b.
	// requires a and b are both positive
	int gcd(const int a, const int b) const;
	
	public:
	static const Fraction Zero;

	Fraction(const int num = 0, const int den = 1);
	Fraction(const std::string &s);
	Fraction(const Fraction &other);
	
	// getters and settersi
	void setNumerator(const int num);
	// throws invalid_argument exception if denom = 0
	void setDenominator(const int denom);

	int getNumerator() const;
	int getDenominator() const; 
	
	// returns true if and only if this fraction is a whole number
	bool isWhole() const;

	// reduces fraction
	void reduce();
	
	Fraction &operator=(const Fraction &other);	

	// common math operators
	Fraction &operator+=(const Fraction &other);
	Fraction &operator*=(const Fraction &other);
	Fraction &operator-=(const Fraction &other);
	Fraction &operator/=(const Fraction &other);
	Fraction &operator++(int i);
	Fraction &operator--(int i);

	// returns absolute values
	int abs(const int a) const;
	Fraction getAbsolute() const;
	
	// if fraction is a/b, returns a new fraction that is b/a
	Fraction reciprocal() const;

	// returns a/b as a double
	double toDouble() const;
};

// common math operators

// adds two fractions
// use: f1 + f2 + f3 ...
Fraction operator+(const Fraction &f1, const Fraction &f2);

// subtracts a fraction from another 
// use: f1 - f2 - f3 ...
Fraction operator-(const Fraction &f1, const Fraction &f2);

// multiplies two fractions together
// use: f1 * f2 * f3 ...
Fraction operator*(const Fraction &f1, const Fraction &f2);
Fraction operator*(const Fraction &f, const int factor);
Fraction operator*(const int factor, const Fraction &f);

// divides two fractions
Fraction operator/(const Fraction &f1, const Fraction &f2);

// compares two fractions, returns true if f1 < f2
// use: f1 < f2 
bool operator<(const Fraction &f1, const Fraction &f2);

// compares two fractions, returns true if f1 > f2
// use: f1 > f2
bool operator>(const Fraction &f1, const Fraction &f2);

// compares two fractions, returns true if f1 == f2
// use: f1 == f2
bool operator==(const Fraction &f1, const Fraction &f2);

// compares two fractions, returns true if f1 != f2
// use: f1 != f2
bool operator!=(const Fraction &f1, const Fraction &f2);

// compares two fractions, returns true if f1 <= f2
// use: f1 <= f2
bool operator<=(const Fraction &f1, const Fraction &f2);

// compares two fractions, returns true if f1 >= f2
// use: f1 >= f2
bool operator>=(const Fraction &f1, const Fraction &f2);
#endif
