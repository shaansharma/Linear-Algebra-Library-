// Created by Zain Humayun on December 23rd, 2015
// fraction.h: Header for fraction.cc, class definition for Fraction.
//	Purpose: Used for storing numbers as rational expressions, aswell as performing basic operations on them

#ifndef FRACTION_H
#define FRACTION_H
#include <stdexcept>

class Fraction{
	int num, den;
	private:
	// reduces the fraction until num and den are co-prime
	void reduce();
	
	// returns the greatest common divisor of a and b.
	// requires a and b are both positive
	int gcd(const int a, const int b) const;
	
	public:
	Fraction(const int num = 1, const int den = 1);
	Fraction(const Fraction &other);
	
	// getters and setters
	void setNumerator(const int num);
	// throws invalid_argument exception if denom = 0
	void setDenominator(const int denom);

	int getNumerator() const;
	int getDenominator() const; 
	
	// returns true if and only if this fraction is a whole number
	bool isWhole() const;
	
	Fraction &operator=(const Fraction &other);	

	// common math operators
	Fraction &operator+=(const Fraction &other);
	Fraction &operator*=(const Fraction &other);
	Fraction &operator-=(const Fraction &other);
	Fraction &operator/=(const Fraction &other);
	Fraction &operator++();
	Fraction &operator--();

	// returns absolute values
	int abs(const int a) const;
	Fraction getAbsolute() const;
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

// compares two fractions, returns true if f1 < f2
// use: f1 < f2 
bool operator<(const Fraction &f1, const Fraction &f2);
bool operator<(const int a, const Fraction &f1);
bool operator<(const Fraction &f1, const int a);

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
