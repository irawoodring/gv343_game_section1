#include "Credit_Sprite.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

Credit_Sprite::Credit_Sprite(std::string color){
	this -> color = color;
} 

void Credit_Sprite::update(std::string currentFrame){
	sstream << color << "_slime_" << currentFrame << ".png";
	this -> fileName = sstream.str();

	if(!texture.loadFromFile(fileName)){
		std::cerr << "Can't load sprite" << std::endl;
		exit(EXIT_FAILURE);
	} 
}

sf::Texture Credit_Sprite::getSprite(){
	return this -> texture;
}
