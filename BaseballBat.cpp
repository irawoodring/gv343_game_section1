#include <string>
#include "BaseballBat.hpp"
#include "Weapons.hpp"

BaseballBat::BaseballBat(){
		 Weapons("Baseball Bat", 3, 30,'c');
		 setPosition(400,400);
		 setSprite("sprites/baseballBat.png");
}
	
