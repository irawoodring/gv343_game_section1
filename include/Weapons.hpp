#include <string>
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include "Monster.hpp"

 class Weapons{
	
class Weapons{
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