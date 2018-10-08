/**********************************************************************
* This class defines all of the variables being used by the class 
* Credits.cpp. This is the interface file.
*
* @author Logan Karney, Kehlsey Lewis, Hai Duong, Trungvuong Pham
* @version 1.0
* @date October 7, 2018
**********************************************************************/
#ifndef CREDITS_H_
#define CREDITS_H_
#include "SFML/Graphics.hpp"
#include "Credit_Sprite.h"

class Credits{
	public:
		/* Method call to fix window */
		Credits(sf::RenderWindow& gameWindow);
		
		/* Credits method default constructor */
		Credits();
		
		/* Starts the program */
		int start();

		/* receives the window */
		sf::RenderWindow* getWindow();

	private:
		/* Private instance variables */
		sf::RenderWindow* window;

		/* ends the screen */
		void end();

		std::vector<Credit_Sprite> slimes;
};
#endif
