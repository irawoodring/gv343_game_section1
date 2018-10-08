/**
	Class: OrangePotion
	Inherits: Collectibles
	Purpose: An orange potion that heals the player.

	Made for CIS343 @ GVSU Fall 2018
	Team Members:
	Isfar Baset
	Allision Bickford
	Nick Cone
	Farid Karadsheh

*/

#include "include/Collectibles.hpp"
#include "include/Collision.hpp"
#include <stdio.h>

class OrangePotion: public Collectibles {
public:
	/* Default constructor, loads sprite and uses default (x,y) coordinates
	   set in Collectibles */
	OrangePotion() {
		loadSprite("sprites/orangePoition.png");	
	}

	/* Loads in the sprite, and accepts (x,y) coordinates, so that it may be
	   placed anywhere in the game world. */
	OrangePotion(int x, int y) {
		this->x = x;
		this->y = y;
		loadSprite("sprites/orangePoition.png");
	}

	/* Heals the player by 50 hp to a maximum of 100 hp. */
	void activate(Person &person){
		int health = person.getHealth();
		if(health <= 50) person.setHealth(health+50);
		else person.setHealth(100);
		hasActivated = true;
	}
};
