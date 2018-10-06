#include "Credits.h"
#include <iostream>

Credits::Credits(sf::RenderWindow& gameWindow){
	this -> window = &gameWindow;
}

sf::RenderWindow* Credits::getWindow(){
	return window;
}

int Credits::start(){
	window -> clear();
	window -> display();
	std::cout << "press any char to continue" << std::endl;
	char input;
	std::cin >> input;

	return 0;
}



/*int main(int argc, char** argv){
	Credits c;
	
	return 0;
}*/
