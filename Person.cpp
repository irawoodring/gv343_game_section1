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
    speed = STARTING_SPEED;
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
    // ignore
}

void Person::harm(int hp){
	health = health - hp;
	punch.play();
}

void Person::render(sf::RenderTarget& window) {

}

void Person::update() {
	float delta = (float(movementClock.restart().asMicroseconds()) * float(1e-6));
    
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		y -= speed * delta;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		y += speed * delta;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		x -= speed * delta;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		x += speed * delta;
	}

	sprite.setPosition(x, y);
}

float Person::getSpeed() {
	return speed;
}

void Person::setSpeed(float pixelsPerSecond) {
	speed = pixelsPerSecond;
}
