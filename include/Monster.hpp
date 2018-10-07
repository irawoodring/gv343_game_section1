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
		int velocityX;
		int velocityY;

	public:
		Monster();
		Monster(std::string path);
		Monster(int x, int y);
		int getHealth();
		void setHealth(int health);
		void setAttackPower(int attackPower);
		void harm(int amount);
		void updatePosition(int x, int y);
		sf::Sprite getSprite();
		bool dead();
};

#endif