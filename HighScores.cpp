#include <iostream>
#include <string.h>
#include<iostream>
#include<fstream>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "HighScores.hpp"
#include "include/Settings.hpp"

HighScores::HighScores(sf::RenderWindow &rw):window(rw){
	/* Setting the High Scores window to the current game window */
} 

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
	title.setPosition(10,200);

	sf::Text text;
	text.setFont(font);
	text.setString("TEST TEST");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(150, 350); 
	while(1){}
}

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

/* TEST MAIN TO BE DELETED */
int main(int argc, char** argv){
	sf::RenderWindow window;
	window.create(sf::VideoMode(WIDTH, HEIGHT + 100), "Not on my block.");
    //HighScores h = new HighScores(window);
	//h.launchHighScoresScreen();
}








