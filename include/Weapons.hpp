#ifndef  __H_WEAPONS__
#define  __H_WEAPONS__


#include <string>
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include "Monster.hpp"

class Weapons{
	
	public:
		//constructor with no params
		Weapons();

		//Constructor with all params
		Weapons(std::string name, int range, int damage, char type);
		
		//all getters
		std::string getName();
		int getRange();
		int getDamage();
		//ranged or melee
		char getType();

		//all setters
		void setRange(int range);
		void setDamage(int damage);
		void setType(char type);
		void setName(std::string name);

		void setPosition(int x,int y);
		sf::Sprite getSprite();
		void setSprite(std::string filename);

		void attack(Monster monster, int dmg);

	private:
		//all variables owned by a Weapon
		int range;
		int damage;
		char type;

		int x;
		int y;

		std::string name;
		sf::Sprite sprite;
		sf::Texture texture;


};
#endif
