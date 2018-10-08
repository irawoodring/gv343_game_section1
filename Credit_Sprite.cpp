#include "Credit_Sprite.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

Credit_Sprite::Credit_Sprite(std::string color, int numFrames){
	this -> color = color;
	this -> numFrames = numFrames;

	colors.push_back("green");
	colors.push_back("red");
	colors.push_back("purple");
	colors.push_back("blue");
	colors.push_back("orange");

	sprite.setPosition(25,0);
} 

void Credit_Sprite::update(int currentFrame){
	sstream.str(std::string());
	
	if(currentFrame < 10)
		sstream << "sprites/"<< color << "_slime_0" << currentFrame << ".png";
	else
		sstream << "sprites/"<< color << "_slime_" << currentFrame << ".png";
	this -> fileName = sstream.str();

	if(!texture.loadFromFile(fileName)){
		std::cerr << "Can't load sprite" << std::endl;
		exit(EXIT_FAILURE);
	}
	sprite.setTexture(texture);
}

sf::Sprite Credit_Sprite::getSprite(){
	return this -> sprite;
}

int Credit_Sprite::getNumFrames(){
	return numFrames;
}

void Credit_Sprite::changeColor(){
	if(currentColor == 4)
		currentColor = 0;	
	else
		currentColor++;

	this -> color = colors[currentColor];
}
