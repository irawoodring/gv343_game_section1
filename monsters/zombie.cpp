#include "Monster.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

void zombie(){
    std::String path = "sprites/zombie1.png";
    Monster::Monster(path);
    int health = 100;
    Monster::setHealth(health);
    int attackPower = 10;
    Monster::setAttackPower(attackPower);
}