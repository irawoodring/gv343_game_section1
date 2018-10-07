/**
	Class: BluePotion
	Inherits: Collectibles
	Purpose: A blue potion that slows the player.

	Made for CIS343 @ GVSU Fall 2018
	Team Members:
	Isfar Baset
	Aliision Bickford
	Nick Cone
	Farid Karadsheh

*/

#include "SFML/Graphics.hpp"
#include "include/Collectibles.hpp"
#include "include/Person.hpp"
#include <iostream>

class BluePotion: public Collectibles {
public:
	/* Default Constructor, loads sprite and uses default (x,y) coordinates
	   set in Collectibles. */
	BluePotion() {
		loadSprite("sprites/bluePotion.png");
	}
	
	/* Loads in the sprite, and accepts (x,y) cooridnates, so that it may be
	   placed anywhere in the game world. */
	BluePotion(int x , int y) {
		this->x = x;
		this->y = y;
		loadSprite("sprites/bluePotion.png");
	}


	/* Modifies the player speed by 0.8, slowing the player down temporarily. */
	void activate(Person &person) {
		//slow the character
		hasActivated = true;
	}

	/* After aproximately 5 seconds, return the player to normal speed. */
	void deactivate(Person &person) {
	  	 sf::Time time = clock.getElapsedTime();
                 sf::Int32 mills = time.asMilliseconds();
                 if(mills % 5000 > 500) {
                         //speed up character
                 
		 }
		hasDeactivated = true;
	}
 };
