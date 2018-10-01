#include <string>

class Weapon {
	
	public:
		//constructor with no parameters
		Weapon();

		Weapon(std::string name, int range, int damage, char type);
		//Accessors
		std::string getName();
		int getRange();
		int getDamage();
		//ranged or melee
		char getType();




