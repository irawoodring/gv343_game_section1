//
// Created by Nick on 10/7/2018.
//
#include "Monster.hpp"
#include "SFML/Graphics.hpp"
#ifndef GITHUB_ROBEGUY_H
#define GITHUB_ROBEGUY_H

class robeguy : public Monster {

    public:
            robeguy(int x, int y,int health, int damage, int score);
            sf::Sprite getSprite();
            void robeguy::setSprite();
};
#endif //GITHUB_ROBEGUY_H
