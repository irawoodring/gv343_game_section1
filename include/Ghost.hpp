//
// Created by Nolan on 10/7/2018.
//

#ifndef _GHOST_H_
#define _GHOST_H_

class Ghost: public Monster{

    public:
        Ghost(int x_t, int y_t, int health, int damage, int score)
                :Monster(int (x_t), int (y_t),int (health), int (damage), int (score)){
        };

        void setSprite();

        /*******************************************************************************************************************
        * Ghost moves from right to left on the screen and does not follow the player. The Ghost is more of an obstacle for
        * the player to avoid
        *
        * @param personX is not used.
        * @param personY is not used.
        *******************************************************************************************************************/
        void Monster::updatePosition(int personX, int personY);
};

#endif //_GHOST_H_
