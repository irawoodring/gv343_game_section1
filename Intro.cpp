#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Intro.hpp"

namespace Intro{
	Intro::Intro(sf::RenderWindow &win) : window(win) {
		this -> showIntro();
		
	}
	
	int Intro::showIntro(){
	sf::Texture splash;
    if (!splash.loadFromFile("./images/NotOnMyBlockLogo.png")) {
        std::cerr <<"Cant load Logo Image."<< std::endl;
    }
    // Get music
    sf::Music music;
    if (!music.openFromFile("music/Intro_Song.mp3")) {
    return EXIT_FAILURE;
    }
    // Start song
    music.play();
	return 0;	

	}
}
















