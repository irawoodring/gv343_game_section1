//
// Created by Nick on 10/2/2018.
//
#include "Monster.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

class robeguy: public Monster{
    robeguy(){
        std::string path = "sprites/robeguy.png";
        Monster::Monster(path);
        int health = 80;
        Monster::setHealth(health);
        int attackPower = 30;
        Monster::setAttackPower(attackPower);
        this->setScore()
    }

    void Monster::updatePosition(int x, int y) {

    }
};
