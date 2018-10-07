#include "include/Collectibles.hpp"
#include "include/Collision.hpp"
#include <stdio.h>

//@Author Nicholas Cone
//@Version October 8th, 2018
class YellowPotion: public Collectibles{
	public:
	//loads in image of yellow potion
		YellowPotion(){
			loadSprite("sprites/yellowPoition.png");
		}
		//Allows user to update position of collectible
		YellowPotion(int x, int y): Collectibles(){

			this->x = x;
			this->y = y;
			loadSprite("sprites/yellowPoition.png");
		}
	//Activates the collectible to remove 20 damage everytime it is hit.
		void activate(Person &person){
			int h = person.getHealth();
			person.setHealth(h-20);
			hasActivated = true;
		}
};
