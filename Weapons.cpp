#include <string>
#include "Weapons.hpp"


	Weapons::Weapons(){
		range = 0;
		damage = 0;
		type = 'x'; // set default to x can be changed / removed
	}

	Weapons::Weapons(std::string name, int range, int damage, char type){
		this->name = name;
		this->range = range;
		this->damage = damage;
		this->type = type;
	}	


	std::string Weapons::getName(){
		return this->name;
	}
	

	int Weapons::getRange(){
		return this->range;
	}

	int Weapons::getDamage(){
		return this->damage;
	}
	
	char Weapons::getType(){
		return this->type;
	}

	void Weapons::setRange(int range){
		this->range = range;
	}

	void Weapons::setDamage(int damage){
		this->damage = damage;
	}

	void Weapons::setType(char type){
		this->type = type;
	}

	void Weapons::setName(std::string name){
		this->name = name;
	}
