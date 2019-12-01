#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

//***CONSTRUCTORS***

// Default constructor, initializes fraction to 0/1
Fraction::Fraction()
	:
	d_numerator(0),
	d_denominator(1)
{}

// Takes 1 int, initializes fraction to numerator/1
Fraction::Fraction(int numerator)
	:
	d_numerator(numerator),
	d_denominator(1)
{}

// Takes 1 double, initializes fraction to (d * 100000 / 100000)
Fraction::Fraction(double d)
	:
	d_numerator(static_cast <int> (d * 100000)),
	d_denominator(100000)
{
	reduce();
}

// Takes 2 ints, initializes fraction to numerator/denominator
Fraction::Fraction(int numerator, int demoninator)
	:
	d_numerator(numerator),
	d_denominator(demoninator)
{
	reduce();
}

//***MATH OPERATOR OVERLOADS***
Fraction Fraction::operator+(const Fraction& f) const
{
	int num = (this->d_numerator * f.d_denominator) + (f.d_numerator * this->d_denominator);
	int denom = this->d_denominator * f.d_denominator;
	return Fraction(num, denom);
}
Fraction Fraction::operator-(const Fraction& f) const
{
	int num = (this->d_numerator * f.d_denominator) - (f.d_numerator * this->d_denominator);
	int denom = this->d_denominator * f.d_denominator;
	return Fraction(num, denom);
}
Fraction Fraction::operator*(const Fraction& f) const
{
	int num = this->d_numerator * f.d_numerator;
	int denom = this->d_denominator * f.d_denominator;
	return Fraction(num, denom);
}
Fraction Fraction::operator/(const Fraction& f) const
{
	// Create reciprocal by switching the numerator and denominator of the divisor
	int rNum = f.d_denominator;
	int rDenom = f.d_numerator;

	// Multiply fraction by reciprocal
	int num = this->d_numerator * rNum;
	int denom = this->d_denominator * rDenom;

	// Return new fraction
	return Fraction(num, denom);
}
Fraction& Fraction::operator+=(const Fraction& f) 
{
	this->d_numerator = (this->d_numerator * f.d_denominator) + (f.d_numerator * this->d_denominator);
	this->d_denominator = this->d_denominator * f.d_denominator;
	reduce();
	return *this;
}

Fraction& Fraction::operator+=(const double d)
{
	Fraction f(d);
	*this += f;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& f)
{
	this->d_numerator = (this->d_numerator * f.d_denominator) - (f.d_numerator * this->d_denominator);
	this->d_denominator = this->d_denominator * f.d_denominator;
	reduce();
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& f)
{
	this->d_numerator *= f.d_numerator;
	this->d_denominator *= f.d_denominator;
	reduce();
	return *this;
}
Fraction& Fraction::operator/=(const Fraction& f)
{
	// Multiply fraction by reciprocal of second fraction
	this->d_numerator *= f.d_denominator;
	this->d_denominator *= f.d_numerator;
	reduce();
	return *this;
}
Fraction& Fraction::operator=(const Fraction& f)
{
	this->d_numerator = f.d_numerator;
	this->d_denominator = f.d_denominator;
	reduce();
	return *this;
}
Fraction Fraction::operator-()	
{
	Fraction frac(d_numerator * -1, d_denominator);
	return frac;
}
Fraction Fraction::operator~()
{
	Fraction frac(d_denominator, d_numerator);
	return frac;
}
Fraction& Fraction::operator++() //pre-increment
{
	this->d_numerator += this->d_denominator; //increment fraction by 1/1
	reduce();
	return *this;
}
Fraction Fraction::operator++(int i) //post-increment, i is a dummy parameter
{
	Fraction temp;
	temp = *this;
	this->d_numerator += this->d_denominator; //increment fraction by 1/1
	reduce();
	return temp; //return value before incrementing
}
Fraction& Fraction::operator--() //pre-decrement
{
	this->d_numerator -= this->d_denominator; //decrement fraction by 1/1
	reduce();
	return *this;
}
Fraction Fraction::operator--(int) //post-decrement
{
	Fraction temp;
	temp = *this;
	this->d_numerator -= this->d_denominator; //decrement fraction by 1/1
	reduce();
	return temp; //return value before decrementing
}
bool Fraction::operator<(const Fraction& f)
{
	Fraction temp = *this - f;
	return (temp.d_numerator < 0);
}
bool Fraction::operator>(const Fraction& f)
{
	Fraction temp = *this - f;
	return (temp.d_numerator > 0);
}
bool Fraction::operator<=(const Fraction& f)
{
	if (d_numerator == f.d_numerator && d_denominator == f.d_denominator)
		return true;
	else if (*this - f < Fraction(0))
		return true;
	else
		return false;
}
bool Fraction::operator>=(const Fraction& f)
{
	if (d_numerator == f.d_numerator && d_denominator == f.d_denominator)
		return true;
	else if (*this - f > Fraction(0))
		return true;
	else
		return false;
}
bool Fraction::operator==(const Fraction& f)
{
	return (d_numerator == f.d_numerator && d_denominator == f.d_denominator);
}
bool Fraction::operator!=(const Fraction& f)
{
	return (d_numerator != f.d_numerator || d_denominator != f.d_denominator);
}
bool Fraction::operator!() 
{
	return (d_numerator == d_denominator); // returns true if fraction is a whole number
}
Fraction::operator float() const
{
	return float(d_numerator) / float(d_denominator);
}
Fraction::operator double() const
{
	return double(d_numerator) / double(d_denominator);
}

//***UTILITIES***

void Fraction::reduce()
{
	try {
		if (d_denominator == 0)
			throw "Divide by 0 error";
		if (d_denominator < 0)  // check if denom is negative, if so multiply by -1/-1
		{
			d_numerator *= -1;
			d_denominator *= -1;
		}
		if (d_numerator == 0)
		{
			d_denominator = 1;
			return;
		}
		int i;
		if (d_numerator < d_denominator)
			i = d_numerator;
		else
			i = d_denominator;
		for (i; i > 1; i--)
		{
			if (d_numerator % i == 0 && d_denominator % i == 0)
			{
				d_numerator /= i;
				d_denominator /= i;
				return;
			}
		}
	}
	catch (...) { throw; } // CLEAN THIS UP
}

istream& operator>>(istream& is, Fraction& f)
{
	int num;
	int denom;

	// Strings used for exception messaging
	const string inputError = "Input error!  Please try again.\n";
	const string divZero = "Divide by zero error!  Please enter a non-zero integer for the denominator.\n";

	try {
		is >> num;
		is.ignore(1, '/'); // ignore / in NN/DD
		is >> denom;
		// if input error occurs (e.g. user enters a char), clear the stream, ignore rest of line and throw exception
		if (!is) {
			is.clear();
			is.ignore(100, '\n');
			throw inputError;
		}
		// if user enters 0 for denominator, throw exception
		else if (denom == 0)
			throw divZero;
		// done will only be set to true if no exceptions are thrown
	}
	// Output appropriate message for input or divide by zero error
	catch (string s) {
		throw s;
	}
	// Default catch statement for any other errors
	catch (...) {
		throw "Error, please try again\n";
	}

	// Set private members of Fraction object based on user input
	f.d_numerator = num;
	f.d_denominator = denom;
	return is;
}

ostream& operator<<(ostream& os, const Fraction& f)
{
	 os << f.d_numerator << "/" << f.d_denominator;
	return os;
}