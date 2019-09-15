#include "Game.h"
#include "Print.h"
#include <string>
#include <iostream>

using namespace std;

//	***********
//	CONSTRUCTOR
//	***********

Game::Game(string& answer)
	:
	d_answer(answer),
	d_answerLen(answer.length()),
	d_word(" _"),
	d_guess(),
	d_lettersGuessed(),
	d_guessesLeft(8),
	d_gameOver(false),
	d_win(false),
	d_lose(false)
	{
	// Set word equal to number of underscores separated by spaces equivalent to length of answer
	for (int i = 0; i < (d_answerLen - 1); i++)
		d_word += " _";
//	printDebug();
	}


//	***********************
//	PUBLIC SETTER FUNCTIONS
//	***********************

// Function getPrint
// Set pointer to Print object to allow Game to call Print member functions
Print* Game::getPrint(Print* pPrint)
{
	print = pPrint;
	return print;
}

// Function setGuess
// Called by Print::getGuess()
// If letter already guessed, prints error and prompts for new guess
// If letter not guessed, sets guess to letter
void Game::setGuess(char letter)
{
	// Check to see if letter has already been guessed
	bool repeat = false;
	for (char& c : d_lettersGuessed)
	{
		if (c == toupper(letter))
		{
			repeat = true;
			break;
		}
	}
	// If letter has already been guessed, print error and prompt user for new guess
	if (repeat)
	{
		print->error("You have already guessed this letter, enter a different guess");
		print->getGuess();
	}
	// If letter has not been guessed, set guess to letter and add letter to string of guesses
	else
	{
		d_guess = letter;
		d_lettersGuessed += letter;
	}
	
}

// Function checkGuess
// Checks to see if letter guessed exists anywhere in the answer
// If guess is incorrect, decrements guesses remaining, prints result of guess, and
//		marks game as over and lost if zero guesses remaining.
// If guess is correct, updates word string with each instance of guess, prints result
//		of guess, and marks game as over and won if all letters have been correctly guessed.
bool Game::checkGuess()
{
	bool correct = false;
	// Loop through all characters in answer to see if guess exists
	for (int i=0; i<d_answerLen; i++)
	{
		if (d_answer[i] == d_guess)
		{
			correct = true;
			// Using (i*2)+1 because word has a space before each underscore/letter
			d_word[(i * 2) + 1] = d_guess;	
		}
	}
	// Case where guess does not appear in answer
	if (!correct)
	{
		print->badGuess(d_guess, --d_guessesLeft);
		// If no guesses left, game is over and lost
		if (d_guessesLeft == 0)
		{
			d_gameOver = true;
			d_lose = true;
		}
	}
	// Case where guess appears in answer
	if (correct)
	{
		print->goodGuess(d_guess);
		// If word matches answer, game is over and won
		if (compareToAnswer())
		{
			d_gameOver = true;
			d_win = true;
		}
	}

//	printDebug();

	return correct;  // True if guess correct, false if guess incorrect
}

//	***********************
//	PUBLIC GETTER FUNCTIONS
//	***********************

bool Game::gameOver() const
{
	return d_gameOver;
}

// Returns true if game won, false if game lost
bool Game::result() const
{
	if (d_win)
		return true;
	if (d_lose)
		return false;
}

string Game::answer() const
{
	return d_answer;
}

string Game::lettersGuessed() const
{
	return d_lettersGuessed;
}

string Game::word() const
{
	return d_word;
}

//	*****************
//	PRIVATE FUNCTIONS
//	*****************

bool Game::compareToAnswer()
{
	bool match = true;
	for (int i = 0; i < d_answerLen; i++)
		// Using (i*2)+1 because word has a space before each underscore/letter
		if (d_answer[i] != d_word[(i * 2) + 1])
			return false;
	return match;
}

void Game::printDebug()
{
	cout << "d_answer = " << d_answer << endl;
	cout << "d_answerLen = " << d_answerLen << endl;
	cout << "d_word = " << d_word << endl;
	cout << "d_guess = " << d_guess << endl;
	cout << "d_lettersGuessed = " << d_lettersGuessed << endl;
	cout << "d_guessesLeft = " << d_guessesLeft << endl;
	cout << "d_gameOver = " << d_gameOver << endl;
	cout << "d_win = " << d_win << endl;
	cout << "d_lose = " << d_lose << endl;
}