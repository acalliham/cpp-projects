// Hangman CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include "File.h"
#include "Game.h"
#include "Print.h"

using namespace std;

int main()
{
	File file;					// Initialize File object
	Print print;				// Initialize Print object

	// Get new random word from File
	string word;
	string* pWord = &word;
	file.getWord(*pWord);

	Game game(*pWord);			// Initialize Game object using word

	// Create pointers to print and game, and pass them to each other
	Print* pPrint = &print;
	Game* pGame = &game;
	print.getGame(pGame);
	game.getPrint(pPrint);

	// The following code promts the user for a new guess, checks the guess, updates
	// the Game object data members, and outputs the results of each guess to
	// the console.  Loop repeats until the game is over (either the user guesses
	// all letters in the word or they run out of guesses).

	while (!game.gameOver())
	{
		print.getGuess();
		game.checkGuess();
	}
	
	// Print the result of the game (win or lose) and the answer to the console

	print.result(game.result());

}

