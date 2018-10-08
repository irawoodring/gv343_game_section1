#ifndef CREDIT_SPRITE_H_
#define CREDIT_SPRITE_H_

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <sstream>

class Credit_Sprite{
	public:
		Credit_Sprite(std::string color, int numFrames);
		void update(int currentFrame);
		sf::Sprite getSprite();
		int getNumFrames();
		void changeColor();
	private:
		std::ostringstream sstream;

		std::string color;
		std::vector<std::string> frames;
		std::vector<std::string> colors;
		std::string fileName;
		sf::Texture texture;
		sf::Sprite sprite;
		int numFrames;
		int currentColor;
};

#endif
