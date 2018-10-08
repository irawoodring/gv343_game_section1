#include "Weapons.hpp"
#include "Brick.hpp"

		Brick::Brick(){
			Weapons("Brick",1,25,'r');
			setPosition(500,500);
			setSprite("sprites/brick.png");
		}
