#include "attributes.h"
#include "wrappingObject.h"

#include <math.h>

WrappingObject::WrappingObject(std::string name, int spriteHalfSize) : Object(name)
{
    // Set up the transform with generic object initializer
    Init();
    spriteHalfSize = spriteHalfSize;
}

void WrappingObject::Update()
{
    Object::Update();
    WrappingObject::Wrap();
}

void WrappingObject::Wrap()
{
    // Horizontal wrapping
    int xpos = transform -> x;
    if(xpos >= 256 - (spriteHalfSize))
    {
        transform -> x = (-2 * spriteHalfSize) + 1;
    }
    else if(xpos <= (-2 * spriteHalfSize))
    {
        transform -> x = 255 - spriteHalfSize;
    }

    // Vertical wrapping
    int ypos = transform -> y;
    if(ypos <= -2 * spriteHalfSize)
    {
        transform -> y = 191;
    }

    if(ypos >= 192)
    {
        transform -> y = (-2 * spriteHalfSize) + 1;
    }
}

void WrappingObject::SetVelocity(float vX, float vY)
{
    velX = vX;
    velY = vY;
}