
#pragma once

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

	//***MATH FUNCTIONS***

	// These function versions take one Fraction as a parameter and return a new fraction based on
	// the result of the mathematical operation using the original Fraction and parameter Fraction
	Fraction Add(Fraction& f);
	Fraction Subtract(Fraction& f);
	Fraction Multiply(Fraction& f);
	Fraction Divide(Fraction& f);

	// These function versions take two Fractions as a parameter and update the original fraction 
	// based on the result of the mathematical operation using the two parameter fractions
	void Add(Fraction& f1, Fraction& f2);
	void Subtract(Fraction& f1, Fraction& f2);
	void Multiply(Fraction& f1, Fraction& f2);
	void Divide(Fraction& f1, Fraction& f2);

	//***IO FUNCTIONS***
	
	// Gets fraction input from console
	void Input();

	// Outputs fraction to console
	void Print();
};