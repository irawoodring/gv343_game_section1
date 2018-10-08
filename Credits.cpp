#include "Credits.h"
#include "Credit_Sprite.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "SFML/Graphics.hpp"


/*****************************************************************
Displays the credits for the game Not on my Block.

@author Kehlsey Lewis, Hai Duoung, Logan Karney, Trungvuong Pham 
@version Fall 2018
*****************************************************************/

/*****************************************************************
    Constructor creates a renders a window to use for credits
    @param size the length of each side in pixels
    *****************************************************************/
Credits::Credits(sf::RenderWindow& gameWindow){
	this -> window = &gameWindow;
	window -> setFramerateLimit(5);
}

sf::RenderWindow* Credits::getWindow(){
	return window;
}

/*****************************************************************
    This function starts the credit and displays it on the screen
    *****************************************************************/
int Credits::start(){
	window -> clear();
	window -> display();

	//http://www.fredosaurus.com/notes-cpp/io/readtextfile.html
	//http://www.cplusplus.com/doc/tutorial/files/
	std::ifstream inFile;
	inFile.open("credits.txt");
	std::string line;
	std::vector<std::vector<std::string>> entries(11);

	if(!inFile){ //error checking opening the file
		std::cerr << "Error opening file";
	}
	
	int local = 0;

	//this opens the document and seprates by ~
	if(inFile.is_open()){
		while(getline (inFile,line)){
				std::cout << line << std::endl;
				if(line[0] != '~'){
					entries[local].push_back(line);
				}
				else
					local++;	
		}
		inFile.close();
	}

	//loads a font
	sf::Font font;
	if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		return EXIT_FAILURE;
	}

	Credit_Sprite cs = Credit_Sprite("green", 25);

	//iterates through the slime frames and the text
	for(int s = 0; s < entries.size(); s++){
		for(int i = 0; i < cs.getNumFrames(); i++){
			cs.update(i);
			window -> clear(); //clears the screen
			window -> draw(cs.getSprite()); //displays the sprite
		
			//4th frame is where text needs to be displayed
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
		cs.changeColor(); //changes slime color
	}

	return 0;
}
/*****************************************************************
This function sets the frame rate limit.
    *****************************************************************/
void Credits::end(){
	window -> setFramerateLimit(0);
}
