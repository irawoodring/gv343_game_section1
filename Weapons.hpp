#ifndef  __H_WEAPONS__
#define  __H_WEAPONS__


#include <string>

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


	private:
		//all variables owned by a Weapon
		int range;
		int damage;
		char type;
		std::string name;


};
#endif
