
#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Game;

class Print
{	
	Game* game;

public:
	Print();
	Game* getGame(Game *pGame);
	void mainMenu();
	void fileList();
	void getGuess();
	void result(bool result);
	void error(string message);
	void goodGuess(char guess);
	void badGuess(char guess, short guessesLeft);
};