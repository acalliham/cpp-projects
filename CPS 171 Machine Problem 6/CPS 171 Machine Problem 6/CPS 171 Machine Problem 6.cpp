// CPS 171 Machine Problem 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Instructions: http://www.hal9k.com/cps171/MP6card.pdf
// Description: You will develop a program that creates a class for a playing card. The main program will then use a loop
// to test the class for all 52 cards in a deck.

#include <iostream>
#include "card.h"
using namespace std;

int main()
{
	cout << "Card Tests by Amy Calliham" << endl << endl;

	for (int i = 1; i <= 52; i++) {
		cout << "Testing the integer " << i << endl;
		card card;
		card.Set_Card(i);
		card.Display();
	};

	return 0;
}

