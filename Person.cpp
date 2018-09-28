#include "Person.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

Person::Person(){
	if(!texture.loadFromFile("sprites/person.png")){
		exit(EXIT_FAILURE);
	}
	sprite.setTexture(texture);
	sf::FloatRect spriteSize = sprite.getGlobalBounds();
	sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
	x = 400;
	y = 300;
	health = 1000;
	sprite.setPosition(x, y);
}

sf::Sprite Person::getSprite(){
	return this->sprite;
}

int Person::getHealth(){
	return this->health;
}

void Person::updatePosition(int dx, int dy){
	if( (x+dx) > 0 && (x+dx) < 800 ){
		x = x + dx;
	}
	if ( (y+dy) > 0 && (y+dy) < 600 ){
		y = y + dy;
	}
	sprite.setPosition(x,y);
}
