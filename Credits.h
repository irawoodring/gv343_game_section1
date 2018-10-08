#ifndef CREDITS_H_
#define CREDITS_H_

#include "SFML/Graphics.hpp"
#include "Credit_Sprite.h"

class Credits{
	public:
		Credits(sf::RenderWindow& gameWindow);
		Credits();
	
	
		int start();
		sf::RenderWindow* getWindow();

	private:
		sf::RenderWindow* window;
		void end();
		std::vector<Credit_Sprite> slimes;
};


#endif
