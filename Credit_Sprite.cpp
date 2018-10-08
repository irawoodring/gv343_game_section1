#include "Credit_Sprite.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

/*****************************************************************
This class is in charge of the slime sprites for the credits.

@author Kehlsey Lewis, Hai Duoung, Logan Karney, Trungvuong Pham 
@version Fall 2018
*****************************************************************/

/*****************************************************************
    Constructor creates a renders a window to use for credits
    @param size the length of each side in pixels
    *****************************************************************/
Credit_Sprite::Credit_Sprite(std::string color, int numFrames){
	this -> color = color;
	this -> numFrames = numFrames;

	//Adds the possible slime colors to a vector
	colors.push_back("green");
	colors.push_back("red");
	colors.push_back("purple");
	colors.push_back("blue");
	colors.push_back("orange");

	//Sets the position of the sprite
	sprite.setPosition(25,0);
} 

/*****************************************************************
    This function updates the current slime sprite
    *****************************************************************/
void Credit_Sprite::update(int currentFrame){
	sstream.str(std::string());
	
	//Selects the correct filename using string concatination
	if(currentFrame < 10)
		sstream << "sprites/"<< color << "_slime_0" << currentFrame << ".png";
	else
		sstream << "sprites/"<< color << "_slime_" << currentFrame << ".png";
	this -> fileName = sstream.str();

	//Error catching
	if(!texture.loadFromFile(fileName)){
		std::cerr << "Can't load sprite" << std::endl;
		exit(EXIT_FAILURE);
	}
	sprite.setTexture(texture);
}

/*****************************************************************
  This function returns the current slime sprite
    *****************************************************************/
sf::Sprite Credit_Sprite::getSprite(){
	return this -> sprite;
}

/*****************************************************************
  This funtion returns the number of frames
    *****************************************************************/
int Credit_Sprite::getNumFrames(){
	return numFrames;
}

/*****************************************************************
    This function changes the color of the slime
    *****************************************************************/
void Credit_Sprite::changeColor(){
	if(currentColor == colors.size() - 1)
		currentColor = 0;	
	else
		currentColor++;

	this -> color = colors[currentColor];
}
