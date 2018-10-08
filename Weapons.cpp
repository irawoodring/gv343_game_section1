#include <string>
#include "Weapons.hpp"
#include "Monster.hpp"
#include <iostream>

	Weapons::Weapons(){
		x = WIDTH/2;
		y = HEIGHT/2;
		range = 0;
		damage = 0;
		type = 'x'; // set default to x can be changed / removed
	}

	Weapons::Weapons(std::string name, int range, int damage, char type){
		this->name = name;
		this->range = range;
		this->damage = damage;
		this->type = type;
		x = WIDTH/2;
		y = HEIGHT/2;
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

	void Weapons::setPosition(int x,int y){
		if(x>=0 && x<=WIDTH)		
			this->x = x;
		if(y>=0 && y<=HEIGHT)		
			this->y = y;
		sprite.setPosition(x,y);
	}

	sf::Sprite Weapons::getSprite(){
		return this->sprite;
	}
	
	void Weapons::setSprite(std::string filename){
		if(!texture.loadFromFile(filename)){
			std::cerr << "Failed to load weapon texture: " << filename << "\n";
			exit(EXIT_FAILURE);
		}
		sprite.setTexture(texture);
		sf::FloatRect spriteSize = sprite.getGlobalBounds();
		sprite.setOrigin(spriteSize.width/2.0,spriteSize.height/2.0);		
	}

	void Weapons::attack(Monster monster, int dmg){
		monster.harm(dmg);
	}



