#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class game
{
string d_word;
short d_numLetters;

public:
	word(string newWord);
	void setAnswer();
	void checkLetterGuess();

private:
	bool compareWords(word& wordGuess);
	void updateWordGuess();
};