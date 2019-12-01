#pragma once

class Fraction 
{

	int d_numerator;
	int d_demoninator;

public:
	Fraction();
	Fraction(int numerator);
	Fraction(double d);
	Fraction(int numerator, int demoninator);
	Fraction Add(Fraction &f);
	Fraction Subtract(Fraction &f);
	Fraction Multiply(Fraction &f);
	Fraction Divide(Fraction &f);
	void Add(Fraction &f);
	void Subtract(Fraction &f);
	void Multiply(Fraction &f);
	void Divide(Fraction &f);
	void Input();
	void print();

};