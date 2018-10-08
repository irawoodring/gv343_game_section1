#include "Weapons.hpp"
#include "Weapons.cpp"
#include "Chainsaw.hpp"
#include <iostream>
#include <string>

	Chainsaw::Chainsaw(){
		Weapons("Chainsaw", 1, 50, 'm');
		setPosition(200, 300);
		setSprite("sprites/chainsaw.png");
	}
	
