#ifndef CREDIT_SPRITE_H_
#define CREDIT_SPRITE_H_

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>

class Credit_Sprite{
	public:
		Credit_Sprite(std::string color);
		void update(int currentFrame);
	private:
		std::string color;
		sf::Texture texture;
		std::vector<std::string> frames;
		
};

#endif
