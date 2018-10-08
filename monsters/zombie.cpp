#include "Monster.hpp"
#include "zombie.hpp"
#include "../SFML/Graphics.hpp"
#include <iostream>
#include <string>

zombie::zombie(int x_t, int y_t, int health, int damage, int score):Monster(x_t, y_t, health, damage, score){
    setSprite();
}

void zombie::setSprite(){
  std::string path = "sprites/zombie/zombie1.png";
  sprite.setTexture(path);
}
