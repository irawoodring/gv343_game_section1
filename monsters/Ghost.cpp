//
// Created by Nolan on 10/7/2018.
//

#include "Monster.hpp"
#include "Settings.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

class Ghost: public Monster{
    Ghost(int x_t, int y_t, int health, int damage, int score)
            :Monster(int (x_t), int (y_t),int (health), int (damage), int (score)){

        //set velocity
        velocityX = 5;
        velocityY = -5;

        setSprite();
    }

    void robeguy::setSprite(){
        std::string path = "sprites/Ghost_1.png";
        sprite.setTexture(path);
    }

    /*******************************************************************************************************************
    * Ghost moves from right to left on the screen and does not follow the player. The Ghost is more of an obstacle for
    * the player to avoid
    *
    * @param personX is not used.
    * @param personY is not used.
    *******************************************************************************************************************/
    void Monster::updatePosition(int personX, int personY){
        //update the x value. Loop to the other side of the screen if the ghost reaches the border, and adjust the
        //ghost's height.
        if(this->x >= WIDTH){   //if reach horizontal border
            this->x = 0;        //move to the other side
            this->y = this->y + this->velocityY;    //and adjust ghost's height

            if(this->y <= 0){   //if reach vertical border
                this->y = HEIGHT;// move to the other border
            }
        }

        else{
            this->x = this->velocity + this->x; //if ghost doesnt reach a border, just move horizontally
        }


        sprite.setPosition(this->x, this->y);


        std::cout<< this->x <<std::endl;
        std::cout<< this->y <<std::endl;
        std::cout<< this->velocityX <<std::endl;
        std::cout<< this->velocityY <<std::endl;
    }
};

