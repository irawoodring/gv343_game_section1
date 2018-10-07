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
	this->x = x;
	this ->y = y;
	this->health = health;
	sprite.setPosition(100,100);
	velocityX = 0;
	velocityY = -2;
}

Monster::Monster(std::string path){
	if (!texture.loadFromFile(path)){
		std::cerr << "Can't load sprite." << std::endl;
		exit(EXIT_FAILURE);
	}
	sprite.setTexture(texture);
	sf::FloatRect spriteSize = sprite.getGlobalBounds();
	sprite.setOrigin(spriteSize.width/2.0,spriteSize.height/2.0);
	sprite.setPosition(100,100);
}

void Monster::setAttackPower(int attackPower){
	this->attackPower = attackPower;
}

void Monster::setHealth(int health){
	this->health = health;
}

int Monster::getHealth(){
	return health;
}

void Monster::harm(int amount){
	health = health - amount;
}

bool Monster::dead(){
	return (health < 0);
}

void Monster::updatePosition(int personX, int personY){
	int desiredX = (personX - this->x) ;
	int desiredY = (personY - this->y) ;

	this->velocityX = (desiredX - this->velocityX) / 10;
	this->velocityY = (desiredY - this->velocityY) / 10;

	this->x = this->velocityX+ this->x;
	this->y = this->velocityY+ this->y;

	sprite.setPosition(this->x, this->y);


	std::cout<< this->x <<std::endl;
	std::cout<< this->y <<std::endl;
	std::cout<< this->velocityX <<std::endl;
	std::cout<< this->velocityY <<std::endl;
}

sf::Sprite Monster::getSprite(){
	sprite.setTexture(texture);
	return this->sprite;
}
