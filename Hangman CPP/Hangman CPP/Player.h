#pragma once
#include <string>
#include "Game.h"
using namespace std;
class Player {

	string d_name;
	string d_catchphrase;
	int d_wins_total;
	int d_losses_total;
	int d_longword_length;
	string d_longword_word;
	int d_wordsoflength_total;
	int d_wordsoflength_won;
	int d_wordsoflength_guesses;

public:
	Player(string name = "Guest", string phrase = "Crack an egg on it!");
	void updateScores(Game& game);

private:
	bool dupeCheck(string name);
};