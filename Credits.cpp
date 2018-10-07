#include "Credits.h"
#include "Credit_Sprite.h"
#include <iostream>
#include "SFML/Graphics.hpp"

Credits::Credits(sf::RenderWindow& gameWindow){
	this -> window = &gameWindow;
	window -> setFramerateLimit(5);
}

sf::RenderWindow* Credits::getWindow(){
	return window;
}

int Credits::start(){

	window -> clear();
	window -> display();
	//std::cout << "press any char to continue" << std::endl;
	//char input;
	//std::cin >> input;
	Credit_Sprite cs = Credit_Sprite("green");

	for(int i = 0; i < 18; i++){
		cs.update(i);
		window -> clear();
		window -> draw(cs.getSprite());
		window -> display();
	}

	return 0;
}

void Credits::end(){
	window -> setFramerateLimit(0);
}


/*int main(int argc, char** argv){
	Credits c;
	
	return 0;
}*/
