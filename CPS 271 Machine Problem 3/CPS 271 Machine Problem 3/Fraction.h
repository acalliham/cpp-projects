
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fraction
{
	int d_numerator;
	int d_denominator;

public:
	//***CONSTRUCTORS***

	// Default constructor, initializes fraction to 0/1
	Fraction();

	// Takes 1 int, initializes fraction to numerator/1
	Fraction(int numerator);

	// Takes 1 double, initializes fraction to (d * 100000 / 100000)
	Fraction(double d);

	// Takes 2 ints, initializes fraction to numerator/denominator
	Fraction(int numerator, int demoninator);

	//***MATH OPERATOR OVERLOADS***
	Fraction operator+(const Fraction&) const;
	Fraction operator-(const Fraction&) const;
	Fraction operator*(const Fraction&) const;
	Fraction operator/(const Fraction&) const;
	Fraction& operator+=(const Fraction&);
	Fraction& operator-=(const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator/=(const Fraction&);
	Fraction& operator=(const Fraction&);
	Fraction operator-();
	Fraction operator~();
	Fraction& operator++(); //pre-increment
	Fraction operator++(int); //post-increment
	Fraction& operator--(); //pre-increment
	Fraction operator--(int); //post-increment
	bool operator<(const Fraction&);
	bool operator>(const Fraction&);
	bool operator<=(const Fraction&);
	bool operator>=(const Fraction&);
	bool operator==(const Fraction&);
	bool operator!=(const Fraction&);
	bool operator!();
	operator float() const;
	operator double() const;
	Fraction& operator+=(const double d);


	//***UTILITIES***
	void reduce();  // Reduces fraction and normalizes how negative & positive fractions are formatted
	friend istream& operator>>(istream&, Fraction&);
	friend ostream& operator<<(ostream&, const Fraction&);
};