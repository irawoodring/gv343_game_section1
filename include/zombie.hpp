#ifndef GITHUB_ZOMBIE_H
#define GITHUB_ZOMBIE_H

#include "Monster.hpp"
#include "../SFML/Graphics.hpp"

class zombie : public Monster{

  public:

    zombie(int x_t, int y_t, int health, int damage, int score): Monster(int (x_t),int (y_t), int (health), int (damage), int (score)){

    };

    void setSprite();
};

#endif
