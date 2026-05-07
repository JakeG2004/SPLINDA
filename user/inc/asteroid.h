#ifndef ASTEROID_H
#define ASTEROID_H

#include "wrappingObject.h"

class Asteroid : public WrappingObject
{
    public:
        Asteroid(std::string, int);
        void Update();
    
    protected:
        void Move();
};

#endif