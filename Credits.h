#ifndef CREDITS_H_
#define CREDITS_H_

#include "SFML/Graphics.hpp"

class Credits{
	public:
		Credits(sf::RenderWindow& gameWindow);
		Credits();
	
	
		int start();
		sf::RenderWindow* getWindow();

	private:
		sf::RenderWindow* window;
};


#endif
