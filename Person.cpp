#include "Person.hpp"
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include <iostream>

Person::Person(){
	if(!texture.loadFromFile("sprites/person.png")){
		exit(EXIT_FAILURE);
	}
	sprite.setTexture(texture);
	sf::FloatRect spriteSize = sprite.getGlobalBounds();
	sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
	if(!punchBuffer.loadFromFile("sounds/punch.wav")){
		std::cerr << "Can't load punch sound." << std::endl;
	}
	punch.setBuffer(punchBuffer);
	initialize();
}

void Person::initialize(){
	x = WIDTH / 2;
	y = HEIGHT / 2;
	health = STARTING_HEALTH;
	sprite.setPosition(x, y);
}

sf::Sprite Person::getSprite(){
	return this->sprite;
}

int Person::getHealth(){
	return this->health;
}

void Person::setHealth(int health){
	this->health = health;
}

void Person::updatePosition(int dx, int dy){
	if( (x+dx) > 0 && (x+dx) < WIDTH ){
		x = x + dx;
	}
	if ( (y+dy) > 0 && (y+dy) < HEIGHT ){
		y = y + dy;
	}
	sprite.setPosition(x,y);
}

void Person::harm(int hp){
	health = health - hp;
	punch.play();
}
