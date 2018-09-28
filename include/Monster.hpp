#ifndef		__H__MONSTER__
#define		__H__MONSTER__

#include "SFML/Graphics.hpp"
#include <string>

class Monster {
	private:
		int attackPower;
		int health;
		int x;
		int y;
		sf::Texture texture;
		sf::Sprite sprite;

	public:
		Monster();
		int getHealth();
		void harm(int amount);
		void updatePosition(int x, int y);
		sf::Sprite getSprite();
};

#endif
