#include <iostream>
#include <iomanip>
#include "card.h"

using namespace std;

card::card() {
	suit = SPADES;
	description = "No card";
	value = 0;
};

void card::Set_Card(int val) {

	if (val >= 1 && val <= 13)
		suit = HEARTS;
	else if (val >= 14 && val <= 26)
		suit = DIAMONDS;
	else if (val >= 27 && val <= 39)
		suit = CLUBS;
	else if (val >= 40 && val <= 52)
		suit = SPADES;

	value = ((val - 1) % 13) + 1;
		//determine whether 1st through 13th card of suit, to use as input to description array arrDesc[]
	
	string arrDesc[14] = { "", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
		//array index correlates value with description of card, index 0 will never be used
	description = arrDesc[value];
	
	if (value >= 11)
		value = 10;
		//set all face cards to value of 10
};

void card::Display() {

	cout << "Card Information is: " << description << " of ";
	switch (suit) {
	case HEARTS:
		cout << "Hearts";
		break;
	case DIAMONDS:
		cout << "Diamonds";
		break;
	case CLUBS:
		cout << "Clubs";
		break;
	case SPADES:
		cout << "Spades";
		break;
	};
	cout << "   Value of card is " << Card_Value() << endl << endl;
	//not sure what purpose of calling Card_Value() is here, instead of referencing variable name value
	//added this as instructions wanted this member function to be created, maybe to show application of private function?
};

int card::Card_Value() {
	return value;
};