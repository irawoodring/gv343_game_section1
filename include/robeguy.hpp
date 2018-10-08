//
// Created by Nick on 10/7/2018.
//

#ifndef GITHUB_ROBEGUY_H
#define GITHUB_ROBEGUY_H
#include "Monster.hpp"
#include "../SFML/Graphics.hpp"

class robeguy : public Monster {

    public:
            robeguy(int x_t, int y_t, int health, int damage, int score):Monster(int (x_t), int (y_t),int (health), int (damage), int (score)){

            };
            void setSprite();
};
#endif //GITHUB_ROBEGUY_H
