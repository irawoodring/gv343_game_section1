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
		int run();
	private:
		sf::RenderWindow window;
		void processEvents();
		void update();
		void render();

		std::vector<Monster> monsters;
		Person player;
		int x;
		int y;
		bool done;
};

#endif
