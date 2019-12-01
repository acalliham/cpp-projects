#include "Fraction.h"
#include <iostream>

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
	d_numerator(static_cast <int> (d*100000)),
	d_denominator(100000)
{}

// Takes 2 ints, initializes fraction to numerator/denominator
Fraction::Fraction(int numerator, int demoninator)
	:
	d_numerator(numerator),
	d_denominator(demoninator)
{}

//***MATH FUNCTIONS***

// These function versions take one Fraction as a parameter and return a new fraction based on
// the result of the mathematical operation using the original Fraction and parameter Fraction

Fraction Fraction::Add(Fraction &f)
{
	int num = (this->d_numerator * f.d_denominator) + (f.d_numerator * this->d_denominator);
	int denom = this->d_denominator * f.d_denominator;
	return Fraction(num, denom);
}

Fraction Fraction::Subtract(Fraction &f)
{
	int num = (this->d_numerator * f.d_denominator) - (f.d_numerator * this->d_denominator);
	int denom = this->d_denominator * f.d_denominator;
	return Fraction(num, denom);
}

Fraction Fraction::Multiply(Fraction &f)
{
	int num = this->d_numerator * f.d_numerator;
	int denom = this->d_denominator * f.d_denominator;
	return Fraction(num, denom);
}

Fraction Fraction::Divide(Fraction &f)
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

// These function versions take two Fractions as a parameter and update the original fraction 
// based on the result of the mathematical operation using the two parameter fractions

void Fraction::Add(Fraction &f1, Fraction &f2)
{
	d_numerator = (f1.d_numerator * f2.d_denominator) + (f2.d_numerator * f1.d_denominator);
	d_denominator = f1.d_denominator * f2.d_denominator;
}

void Fraction::Subtract(Fraction &f1, Fraction& f2)
{
	d_numerator = (f1.d_numerator * f2.d_denominator) - (f2.d_numerator * f1.d_denominator);
	d_denominator = f1.d_denominator * f2.d_denominator;
}

void Fraction::Multiply(Fraction &f1, Fraction& f2)
{
	d_numerator = f1.d_numerator * f2.d_numerator;
	d_denominator = f1.d_denominator * f2.d_denominator;
}

void Fraction::Divide(Fraction &f1, Fraction& f2)
{
	// Multiply first fraction by reciprocal of second fraction
	d_numerator = f1.d_numerator * f2.d_denominator;
	d_denominator = f1.d_denominator * f2.d_numerator;
}

//***IO FUNCTIONS***

// Gets fraction input from console
void Fraction::Input()
{
	int num;
	int denom;
	bool done = false;  // Keeps track of whether fraction has been successfully input, for do while loop
	
	// Strings used for exception messaging
	const string inputError = "Input error!  Please try again.\n";
	const string divZero = "Divide by zero error!  Please enter a non-zero integer for the denominator.\n";

	// Do While loop repeats until user successfully enters a fraction in form NN/DD
	do {
		try {
			cout << "Enter a fraction NN/DD\n";
			cin >> num;
			cin.ignore(1, '/'); // ignore / in NN/DD
			cin >> denom;
			// if input error occurs (e.g. user enters a char), clear the stream, ignore rest of line and throw exception
			if (!cin) {  
				cin.clear();
				cin.ignore(100, '\n');
				throw inputError;
			}
			// if user enters 0 for denominator, throw exception
			else if (denom == 0)
				throw divZero;
			// done will only be set to true if no exceptions are thrown
			done = true;
		}
		// Output appropriate message for input or divide by zero error
		catch (string s) {
			cout << s << endl;
		}
		// Default catch statement for any other errors
		catch (...) {
			cout << "Error, please try again\n";
		}
	} while (!done);  // End of Do While loop

	// Set private members of Fraction object based on user input
	d_numerator = num;
	d_denominator = denom;
}

// Outputs fraction to console
void Fraction::Print()
{
	cout << endl << "The result is: " << d_numerator << "/" << d_denominator << endl;
}