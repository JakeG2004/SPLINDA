#ifndef SHIP_H
#define SHIP_H

#include "object.h"

class Ship : public Object
{
    public:
        Ship(std::string);
        void MoveShip();
        void Update();

    private:
        const float ROT_SPEED = 100;
        const float ROT_DAMPING = 0.9;
        float rotVel = 0;

        const float MOVE_SPEED = 0.5;
        const float MAX_VEL = 3;
        const float VEL_DAMPING = 0.99;
        float vel = 0;

        void Rotate();
        void Move();
        void Wrap();
};

#endif