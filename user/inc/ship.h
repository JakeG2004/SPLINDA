#ifndef SHIP_H
#define SHIP_H

#include "wrappingObject.h"

class Ship : public WrappingObject
{
    public:
        Ship(std::string, int);
        void MoveShip();
        void Update();

    protected:
        const float ROT_SPEED = 100;
        const float ROT_DAMPING = 0.9;
        float rotVel = 0;

        const float MOVE_SPEED = 0.5;
        const float MAX_VEL = 3;
        const float VEL_DAMPING = 0.99;
        float velX = 0;
        float velY = 0;

        void Rotate();
        void Move();
};

#endif