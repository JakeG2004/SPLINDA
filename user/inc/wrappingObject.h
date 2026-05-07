#ifndef WRAPPING_OBJECT_H
#define WRAPPING_OBJECT_H

#include "object.h"

class WrappingObject : public Object
{
    public:
        WrappingObject(std::string, int);
        void SetVelocity(float, float);
    
    protected:
        void Wrap();
        void Update();

        float velX = 0;
        float velY = 0;

        int spriteHalfSize = 32;
};

#endif