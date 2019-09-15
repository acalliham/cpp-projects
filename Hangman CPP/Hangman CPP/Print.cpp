#include "Print.h"
#include "Game.h"
#include <iostream>

using namespace std;

//	***********
//	CONSTRUCTOR
//	***********

Print::Print()
{}

//	***********************
//	PUBLIC MEMBER FUNCTIONS
//	***********************

void Print::mainMenu()  // TO DO - WILL ASK USER TO SELECT OR CREATE NEW PLAYER
{

}

void Print::fileList() // TO DO - WILL PROMPT USER TO CHOOSE A WORD LIST
{

}

Game* Print::getGame(Game *pGame)
{
	game = pGame;
	return game;
}

// Prompts user to enter a letter and passes that to game->setGuess()

void Print::getGuess()
{
	char guess;
	cout << game->word() << "\n\n";				// TO DO - ADD EXCEPTION HANDLING
	if (game->lettersGuessed() != "")			// Do not print letters guessed for the first guess
		cout << "Letters guessed: " << game->lettersGuessed() << "\n\n";
	cout << "Guess a letter: ";
	cin >> guess;
	game->setGuess(toupper(guess));
}

void Print::result(bool result)
{
	if (result)
		cout << "WOOOOOOHOOOOO!!!  YOU ARE A WINNER \n\n";
	if (!result)
		cout << "D'OH!  YOU ARE OUT OF GUESSES.  GAME LOST!! \n\n";
	cout << "The answer is " << game->answer() << "\n\n";
}

void Print::error(string message = "An error has occurred")
{
	cout << message << endl;
}

void Print::goodGuess(char guess)
{
	cout << "GUESS IS CORRECT! \n\n";
}

void Print::badGuess(char guess, short guessesLeft)
{
	cout << "GUESS IS INCORRECT - NO \"" << guess << "\"s FOUND \n\n";
	cout << "You have " << guessesLeft << " guesses remaining \n\n";
}