#include "Print.h"
#include "Game.h"
#include <iostream>
#include <regex>
#include <string>

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

// Displayed after a game is played, asks user if they want to play again or exit
int Print::gameMenu()
{
	int choice;
	
	do
	{
		cout << "********** GAME MENU **********\n\n";
		cout << "     1  Play Again \n";
		cout << "     TO DO 2  Change Word List \n";
		cout << "     TO DO 3  Change Player \n";
		cout << "     4  Quit \n\n";
		cout << "**** ENTER YOUR SELECTION ****\n\n";
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
	} while (!(choice == 1 || choice == 4));  // TO DO CHANGE ONCE 2 AND 3 IMPLEMENTED

	return choice;
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
	regex r("[a-zA-Z]");
	string s;

	cout << game->word() << "\n\n";				// TO DO - ADD EXCEPTION HANDLING
	if (game->lettersGuessed() != "")			// Do not print letters guessed for the first guess
		cout << "Letters guessed: " << game->lettersGuessed() << "\n\n";

	do
	{
		cout << "Guess a letter: ";
		cin >> guess;
		
		// Clear any junk from the stream
		cin.clear(); 
		cin.ignore(100, '\n');

		cout << "\n";

		// Following code converts guess to string for use in regex_match
		s = "";  // Clear string s in case this is a repeat of loop
		s.push_back(guess);  // Assign char guess to string s

	} while (!(regex_match(s, r))); // Loop will repeat until guess is an alpha character

	game->setGuess(toupper(guess));  // Send letter guess to game
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
	hangman(guessesLeft);
	cout << "You have " << guessesLeft << " guesses remaining \n\n";
}

//	************************
//	PRIVATE MEMBER FUNCTIONS
//	************************

void Print::hangman(short guessesLeft)
{
	switch (guessesLeft)
	{
	case 0:
		cout << "    ___    \n";
		cout << "   |   |   \n";
		cout << "   O   |   \n";
		cout << "  /|\\  |   \n";
		cout << "  / \\  |   \n";
		cout << "       |   \n";
		cout << "   ____|___\n\n";
		break;
	case 1:
		cout << "    ___    \n";
		cout << "       |   \n";
		cout << "   O   |   \n";
		cout << "  /|\\  |   \n";
		cout << "  / \\  |   \n";
		cout << "       |   \n";
		cout << "   ____|___\n\n";
		break;
	case 2:
		cout << "    ___    \n";
		cout << "       |   \n";
		cout << "   O   |   \n";
		cout << "  /|\\  |   \n";
		cout << "  /    |   \n";
		cout << "       |   \n";
		cout << "   ____|___\n\n";
		break;
	case 3:
		cout << "    ___    \n";
		cout << "       |   \n";
		cout << "   O   |   \n";
		cout << "  /|\\  |   \n";
		cout << "       |   \n";
		cout << "       |   \n";
		cout << "   ____|___\n\n";
		break;
	case 4:
		cout << "    ___    \n";
		cout << "       |   \n";
		cout << "   O   |   \n";
		cout << "  /|   |   \n";
		cout << "       |   \n";
		cout << "       |   \n";
		cout << "   ____|___\n\n";
		break;
	case 5:
		cout << "    ___    \n";
		cout << "       |   \n";
		cout << "   O   |   \n";
		cout << "   |   |   \n";
		cout << "       |   \n";
		cout << "       |   \n";
		cout << "   ____|___\n\n";
		break;
	case 6:
		cout << "    ___    \n";
		cout << "       |   \n";
		cout << "   O   |   \n";
		cout << "       |   \n";
		cout << "       |   \n";
		cout << "       |   \n";
		cout << "   ____|___\n\n";
		break;
	case 7:
		cout << "    ___    \n";
		cout << "       |   \n";
		cout << "       |   \n";
		cout << "       |   \n";
		cout << "       |   \n";
		cout << "       |   \n";
		cout << "   ____|___\n\n";
		break;
	}
}

