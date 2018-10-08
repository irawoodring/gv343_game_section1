#include "Credits.h"
#include "Credit_Sprite.h"
#include <iostream>
#include <fstream>
#include <vector>
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

	//http://www.fredosaurus.com/notes-cpp/io/readtextfile.html
	//http://www.cplusplus.com/doc/tutorial/files/
	std::ifstream inFile;
	inFile.open("credits.txt");
	std::string line;
	std::vector<std::vector<std::string>> entries(11);
	if(!inFile){
		std::cerr << "Error opening file";
	}
	
	int local = 0;
	if(inFile.is_open()){
		while(getline (inFile,line)){
				std::cout << line << std::endl;
				//if(line.length() != 1){
				//if(line.compare('\n') != 0){
				if(line[0] != '~'){
					entries[local].push_back(line);
				}
				else
					local++;	
		}
		inFile.close();
	}

	sf::Font font;
	if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		return EXIT_FAILURE;
	}

	Credit_Sprite cs = Credit_Sprite("green", 26);

	for(int s = 0; s < entries.size(); s++){
		for(int i = 0; i < cs.getNumFrames(); i++){
			cs.update(i);
			window -> clear();
			window -> draw(cs.getSprite());
		
			if(i >= 4){
				for(int j = 0; j < entries[s].size(); j++){
					sf::Text text;
					text.setFont(font);
					text.setCharacterSize(25);
					text.setString(entries[s][j]);
					text.setFillColor(sf::Color::White);
					text.setPosition(200, 200 + 30*j);
					window -> draw(text);
				}
			}
			window -> display();

		}
		cs.changeColor();
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
