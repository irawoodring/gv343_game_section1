//
// Created by Nick on 10/2/2018.
//
#include "robeguy.hpp"
#include "../SFML/Graphics.hpp"
#include <iostream>
#include <string>

robeguy::robeguy(int x_t, int y_t, int health, int damage,int score): Monster(x_t, y_t, health, damage, score) {
setSprite();
}

void robeguy::setSprite(){
    std::string path = "sprites/zombie1.png";
}



    void Monster::updatePosition(int x, int y) {

}
