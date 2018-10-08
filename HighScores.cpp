#include <iostream>
#include<fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "HighScores.hpp"
#include "include/Settings.hpp"

/* Constructor takes the window and the score of the
current player */
HighScores::HighScores(sf::RenderWindow &rw, int score):window(rw){
	this->score = score;
} 

/* Launches the screen to add your high score to the high scores
text file */
int HighScores::launchHighScoresScreen(){
	window.clear();
	sf::Font font;
	if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		return EXIT_FAILURE;
	}

	sf::Text title;
	title.setFont(font);
	title.setString("HIGH SCORES");
	title.setCharacterSize(64);
	title.setFillColor(sf::Color::White);
	title.setPosition(110,40);

	sf::Text enterLabel;
	enterLabel.setFont(font);
	enterLabel.setString("Enter your initials:");
	enterLabel.setCharacterSize(24);
	enterLabel.setFillColor(sf::Color::White);
	enterLabel.setPosition(60, 250); 

	sf::Text initialsLabel;
	initialsLabel.setFont(font);
	initialsLabel.setCharacterSize(24);
	initialsLabel.setFillColor(sf::Color::White);
	initialsLabel.setPosition(480, 250); 	

	sf::Text scoreLabel;
	scoreLabel.setFont(font);
	scoreLabel.setString(std::to_string(score));
	scoreLabel.setCharacterSize(24);
	scoreLabel.setFillColor(sf::Color::White);
	scoreLabel.setPosition(620, 250); 	

	sf::Clock clock;
	std::string initials;
	while(window.isOpen()){
		sf::Event event;
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
				exit(0);				
			}
			/* Return key calls addToScores to write the score to file */
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Return){
					window.clear();
					HighScores::addToScores(initials, score);
					return 0;
				}
			}
			/* Referenced: https://en.sfml-dev.org/forums/index.php?topic=2269.0 */
			if (event.type == sf::Event::TextEntered){
				if (event.text.unicode < 128){
					if(initials.size() < 3){
						initials += static_cast<char>(event.text.unicode);
						initialsLabel.setString(initials);						
					}
				}
			}
		}
		window.draw(title);
		window.draw(enterLabel);
		window.draw(initialsLabel);
		window.draw(scoreLabel);
		window.display();
		sf::Time time = clock.getElapsedTime();
		sf::Int32 mills = time.asMilliseconds();
		if(mills % 1000 > 500){
			title.setFillColor(sf::Color::Black);
		} else {
			title.setFillColor(sf::Color::White);
		}
	}
	return 0;
}

/* Launches screen to display high scores */
int HighScores::displayHighScores(){
	window.clear(sf::Color(0, 0, 0));
	sf::Font font;
	if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		return EXIT_FAILURE;
	}

	sf::Text title;
	title.setFont(font);
	title.setString("HIGH SCORES");
	title.setCharacterSize(64);
	title.setFillColor(sf::Color::White);
	title.setPosition(110,20);

	sf::Text scores;
	scores.setFont(font);
	scores.setString(HighScores::readScoresToString());
	scores.setCharacterSize(32);
	scores.setFillColor(sf::Color::White);
	scores.setPosition(280,140);

	sf::Clock clock;
	std::string initials;
	while(window.isOpen()){
		sf::Event event;
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
				exit(0);
				
			}
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Return){
					window.clear();
					return 0;
				}
			}
		}
		window.draw(title);
		window.draw(scores);
		window.display();
		sf::Time time = clock.getElapsedTime();
		sf::Int32 mills = time.asMilliseconds();
		if(mills % 1000 > 500){
			title.setFillColor(sf::Color::Black);
		} else {
			title.setFillColor(sf::Color::White);
		}
	}
	return 0;
}

/* Adds the players score and initials into the HighScores.txt file
if it exists, otherwise it creates the file and players score is first in */
int HighScores::addToScores(std::string initials, int score) {
    std::string line;
    bool hasWritten = false;
    /* Opens HighScores.txt to read if file exists
     * If file does not exist, file is created, and
     * current entry is the first to be written */
    std::fstream highScores("HighScores.txt", std::ios::in);
    if(highScores.fail()){
        std::fstream highScores("HighScores.txt", std::ios::out);
        if(highScores.fail()){
            std::cout << "Failed to create new HighScores file" << std::endl;
            return 0;
        }
        highScores << initials << " " << score << std::endl;
        return 0;
    }
    std::fstream tempFile("temp.txt", std::ios::out);
    int currLine = 0;
    /* Each line will be read into these variables
     * and written to the temp file in its correct place */
    std::string currInitials;
    int currScore;
    /* Saving 10 scores, reading each entry in the current file */
    while (currLine < 10 && (highScores >> currInitials >> currScore)) {
        /* Writing players score to file if score in file is less than
         * or equal to players score, inserting the score in correct place */
        if (!hasWritten && currScore <= score) {
            tempFile << initials << " " << score << std::endl;
            hasWritten = true;
        }
        /* Writes the entry from HighScores.txt back into temp if
         * the players score if written and less than 9 scores have been
         * written back, or if the players score was too low to write,
         * which means all 10 entries are written back to file */
        if (currLine < 9 || !hasWritten) {
            tempFile << currInitials << " " << currScore << std::endl;
        }
        currLine++;
    }
    /* Writes players score at bottom if there is space and player
     * has not already been written */
    if (!hasWritten && currLine < 10) {
        tempFile << initials << " " << score << std::endl;
    }
    highScores.close();
    tempFile.close();
    remove("HighScores.txt");
    rename("temp.txt", "HighScores.txt");
    return 1;
}

/* Function to open file and read content into String file
Referenced: https://stackoverflow.com/questions/25517397/create-stdstring-from-stdistreambuf-iterator-strange-syntax-quirk */
std::string HighScores::readScoresToString(){
	std::ifstream ifs("HighScores.txt");
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	return content;
}

/* TEST MAIN TO BE DELETED */
/*int main(int argc, char** argv){
	sf::RenderWindow window;
	window.create(sf::VideoMode(WIDTH, HEIGHT + 100), "Not on my block.");
    HighScores h(window, 66677);
	h.launchHighScoresScreen();
	h.displayHighScores();
}*/








