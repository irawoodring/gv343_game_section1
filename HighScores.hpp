//
// Created by Justin Dowty on 10/2/2018.
//

#ifndef HIGHSCORES_HIGHSCORES_H
#define HIGHSCORES_HIGHSCORES_H



#include "SFML/Graphics.hpp"
#include <vector>

class HighScores{
	public:
		HighScores(sf::RenderWindow &window, int score);
		int displayHighScores();
		int launchHighScoresScreen();
		std::string readScoresToString();
		int score;	
	private:
		sf::RenderWindow &window;
		int addToScores(std::string initials, int score);
		// Need a vector for holding on to scores

};

#endif //HIGHSCORES_HIGHSCORES_H
