#pragma once
#include <string>
using namespace std;
class card
{
private:
	string description;
		//Face value of card, e.g. Ace, Two, ... King

	enum suit {HEARTS, DIAMONDS, CLUBS, SPADES} suit;
		//Suit of card

	int value;
		//Ace = 1, Two through Ten = face value, Jack/Queen/King = 10

	int Card_Value();
		//Returns value of card, called by Display()

public:
	card();
		//Constructor
		//Postcondition: sets suit to SPADES, value to 0, description to "No Card"

	void Set_Card(int val);
		//Function to set the variables of the card
		//Postcondition: Sets the card suit, value, and description based on the card number

	void Display();
		//Function to output the card details
		//Postcondition: outputs the card description, suit, and value

};