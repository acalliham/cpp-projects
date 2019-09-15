#include "Game.h"
#include <string>


word::word(string newWord)
	:
	d_word(newWord)

{
	d_numLetters = newWord.length();
}