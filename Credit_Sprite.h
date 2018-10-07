#ifndef CREDIT_SPRITE_H_
#define CREDIT_SPRITE_H_

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <sstream>

class Credit_Sprite{
	public:
		Credit_Sprite(std::string color);
		void update(std::string currentFrame);
		sf::Texture getSprite();
	private:
		std::ostringstream sstream;

		std::string color;
		std::vector<std::string> frames;
		std::string fileName;
		sf::Texture texture;
};

#endif
