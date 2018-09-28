#include "Monster.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

Monster::Monster(){
	if (!texture.loadFromFile("sprites/monster_one.png")){
		std::cerr << "Can't load sprite." << std::endl;
		exit(EXIT_FAILURE);
	}
	sprite.setTexture(texture);
	sf::FloatRect spriteSize = sprite.getGlobalBounds();
	sprite.setOrigin(spriteSize.width/2.0,spriteSize.height/2.0);
	sprite.setPosition(100,100);
}

int Monster::getHealth(){
	return health;
}

void Monster::harm(int amount){
	health = health - amount;
}

void Monster::updatePosition(int x, int y){
	this->x = x;
	this->y = y;
}

sf::Sprite Monster::getSprite(){
	sprite.setTexture(texture);
	return this->sprite;
}
