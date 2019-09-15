#pragma once
#include "Print.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Print;					// Let class know this other class exists, for purposes of print pointer

class Game
{
	string const d_answer;		// Hangman word
	string d_word;				// String with blanks and correct letter guesses filled in
	short const d_answerLen;	// Length of word
	char d_guess;				// Letter guess
	string d_lettersGuessed;	// All letters guessed so far
	short d_guessesLeft;		// Number of guesses remaining (starts with 8)
	bool d_gameOver;			// set to true when the game has ended
	bool d_win;					// initialized to false, set to true if the game is won
	bool d_lose;				// initialized to false, set to true if the game is lost
	Print* print;				// Pointer to print object

public:

	//Constructor
	Game(string &answer);

	//Setters
	Print* getPrint(Print* pPrint);
	void setGuess(char letter);
	bool checkGuess();

	//Getters
	bool gameOver() const;
	bool result() const;
	string answer() const;
	string lettersGuessed() const;
	string word() const;

private:

	//Determine if answer is correct
	bool compareToAnswer();

	//Outputs all private data members, only used for debugging
	void printDebug();
};