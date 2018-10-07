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
		int score;
		int minV;
		int maxV;

	public:
		Monster();
		Monster(std::string path);
		Monster(int x, int y, int health, int damage);
		int getHealth();
		void setHealth(int health);
		void setAttackPower(int attackPower);
		int getAttackPower();
		int getScore();
		void setScore(int score);
		void harm(int amount);
		void updatePosition(int x, int y);
		bool dead();
		sf::Sprite getSprite();
};

#endif