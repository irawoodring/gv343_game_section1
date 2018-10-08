#include "Game.hpp"
#include "gameOptions.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Settings.hpp"
#include "HighScores.hpp"

/**Added by Nate **/
#include "Person.hpp"
#include <vector>






/*************************************************************************
* Default constructor
*************************************************************************/
gameOptions::gameOptions() {


}

/**
* Default destructor
*/
gameOptions::~gameOptions() {

}

/*************************************************************************
* Constructor ()
*************************************************************************/
gameOptions::gameOptions(sf::RenderWindow& window, sf::Music& music){

    if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		std::cerr << "We should be throwing exceptions here... font can't load." << std::endl;
	}
}

/*************************************************************************
* Pauses the music
*************************************************************************/
void gameOptions::stopMusic(sf::Music& music) {
    music.pause();
}

/*************************************************************************
* Starts the music
*************************************************************************/
void gameOptions::startMusic(sf::Music& music) {
    music.play();
}

/*************************************************************************
*
*************************************************************************/
void gameOptions::displayMenu(sf::RenderWindow& window){
    window.clear();

    sf::Text txtTitle;
	txtTitle.setFont(font);
	txtTitle.setString("Options");
	txtTitle.setCharacterSize(44);
	txtTitle.setFillColor(sf::Color::White);
	txtTitle.setPosition(175,200);

    sf::Text txtChangeDisplay;
	txtChangeDisplay.setFont(font);
	txtChangeDisplay.setString("FullScreen On/Off V");
	txtChangeDisplay.setCharacterSize(24);
	txtChangeDisplay.setFillColor(sf::Color::White);
	txtChangeDisplay.setPosition(175,300);

    sf::Text txtExit;
	txtExit.setFont(font);
	txtExit.setString("Exit - 'Backspace'");
	txtExit.setCharacterSize(24);
	txtExit.setFillColor(sf::Color::White);
	txtExit.setPosition(175,350);


    sf::Text txtMusic;
	txtMusic.setFont(font);
	txtMusic.setString("Music On/Off 'M'");
	txtMusic.setCharacterSize(24);
	txtMusic.setFillColor(sf::Color::White);
	txtMusic.setPosition(175,400);

    window.draw(txtTitle);
    window.draw(txtChangeDisplay);
    window.draw(txtMusic);
    window.draw(txtExit);

    window.display();
   
}

/*************************************************************************
* Overloaded displayMenu to include music when calling acceptUserInput
*************************************************************************/
void gameOptions::displayMenu(sf::RenderWindow& window, sf::Music& music){
    displayMenu(window);
    acceptUserInput(window,music);
}

/*********************************************************************************
* This function runs the duration of the game options screen listening for
* user input.
********************************************************************************/
void gameOptions::acceptUserInput(sf::RenderWindow& window, sf::Music& music){
    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
				music.stop();
				exit(0);
			}

			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::BackSpace){
					window.clear();
					return;
				}
				if(event.key.code == sf::Keyboard::M){
                    if(music.getStatus()==sf::Music::Paused)
                        music.play();
                    else 
					    stopMusic(music);
				}

                
				if(event.key.code == sf::Keyboard::V){
					fullScreen(window);
				}
			}

		}
}
}

/** Added by Nate, unconfirmed if works **/
void gameOptions::changeResolution(sf::RenderWindow& window, int x, int y) {
	window.setSize(sf::Vector2<unsigned int>(x, y));
	window.setPosition(sf::Vector2<int>(0,0));
	
}


void gameOptions::displayCredits(){

}

/**Added by Nate, unconfirmed if works **/
void gameOptions::reset(std::vector<Monster>& monsters, Person& player, bool& done){
	resetPlayer(player); //player.initialize() would work too
	monsters.clear(); //Clearing monster vector
	monsters.push_back(Monster()); //Adding a single monster like game says.
	done = false; //Maybe this isnt neccecary
}

/**
 * This method gathers the top scores of the previous played games
 */
void gameOptions::highScore(){
	HighScores highScores = new HighScores();
	highScores.launchHighScoresScreen();
}

/*************************************************************************
* Should effectively quit the game and return to the main screen
*************************************************************************/
void gameOptions::exitToMenu(){
	Game g;
	g.start();
	g.run();
}

void gameOptions::changeTextColor(/**sf::RenderWindow& window, sf::Color color **/){
	/**This one I think we would have to ask to change his render funcion - Nate **/
}

void gameOptions::fullScreen(sf::RenderWindow& window) 
{
	/**I think that window.setSize(sf::Vector2<unsigned int>(1300, 1400));
	* might work here instead of .create. Thats what I used before and it
	* seemed to work. Its worth a shot. */
    //window.create(sf::VideoMode(1300, 1400), "Not on my block.", 3 << 3);
	const std::vector<sf::VideoMode>& fullscreenModes = sf::VideoMode::getFullscreenModes();
	changeResolution(window,fullscreenModes[0].width,fullscreenModes[0].height);
    displayMenu(window);
}

/**Added by Nate, unconfirmed if works **/
void gameOptions::setPlayerHealth(Person& player, int health){
	player.setHealth(health);
	/** player->setHealth(health)? idk if its on stack or heap **/
}

/**Added by Nate, unconfirmed if works **/
void gameOptions::resetPlayer(Person& player){
	/**I belive this will reset the player back to its original position and health **/
	player.initialize(); //player->initialize()?
}

/**Added by Nate, unconfirmed if works **/
void gameOptions::endGame(bool& done){
	done = true; //Should break the loop, see Game::run function
}

/**Change Difficulty**/
void gameOptions::changeDifficulty(int diff, std::vector<Monster>& monsters, Person& player){
	switch diff{
		case 1:
			//Easy
			setPlayerHealth(player, 200);
			break;
		case 2:
			//Medium
			setPlayerHealth(player, 100);
			//Will this work? or will the moster dissapear when the function ends?
			monsters.push_back(monster().updatePosition(50, 50));
			break;
		case 3:
			//Hard
			setPlayerHealth(player, 50);
			monsters.push_back(monster().updatePosition(50, 50));
			monster.push_back(monster().updatePosition(25, 25));
			break;
		default:
			break;
	}
}
