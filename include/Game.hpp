#ifndef		H__GAME__
#define		H__GAME__

#include "Person.hpp"
#include "Monster.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

class Game {
	public:
		Game();
		int start();
		void run();
	private:
		sf::RenderWindow window;
		void processEvents();
		void update();
		void render();

		std::vector<Monster> monsters;
		Person player;
		bool done;
		int score;
		sf::Text scoreLabel;
		sf::Text playerHealth;	
        	sf::Font font;
		
};

#endif
