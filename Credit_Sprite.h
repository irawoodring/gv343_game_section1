#ifndef CREDIT_SPRITE_H_
#define CREDIT_SPRITE_H_

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <sstream>

/*****************************************************************
The .h file for the credits sprite file

@author Kehlsey Lewis, Hai Duoung, Logan Karney, Trungvuong Pham 
@version Fall 2018
*****************************************************************/

class Credit_Sprite{
	public:
		/* The constructor */
		Credit_Sprite(std::string color, int numFrames);

		/* updates the window */
		void update(int currentFrame);

		/* returns the sprite*/
		sf::Sprite getSprite();

		/* function to get the number of frames*/
		int getNumFrames();

		/* function to change the color*/
		void changeColor();

	private:
		/* string concatination*/
		std::ostringstream sstream;

		/* the color name*/
		std::string color;

		/* the vector to hold the frames*/
		std::vector<std::string> frames;

		/* the vector to hold the color*/
		std::vector<std::string> colors;

		/* the filename*/
		std::string fileName;

		/* the texture*/
		sf::Texture texture;

		/* the current sprite*/
		sf::Sprite sprite;

		/* the current frame */
		int numFrames;

		/* the current color*/
		int currentColor;
};

#endif
