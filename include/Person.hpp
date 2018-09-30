#ifndef		__H_PERSON__
#define		__H_PERSON__

#include "SFML/Graphics.hpp"

class Person {
	public:
		Person();
		int getHealth();
		void setHealth(int health);
		sf::Sprite getSprite();
		void harm(int hp);
		void updatePosition(int x, int y);
		
	private:
		sf::Sprite sprite;
		sf::Texture texture;
		int x;
		int y;
		int health;
};

#endif
