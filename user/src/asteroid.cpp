#include "asteroid.h"
#include "attributes.h"
#include "asteroidSprite.h"

#include <ctime>

Asteroid::Asteroid(std::string name, int spriteHalfSize) : WrappingObject(name, spriteHalfSize)
{
    srand(time(0));
    Init();
    SetVelocity(rand() % 2, rand() % 2);

    // Set up the sprite
    Sprite* asteroidSprite = new Sprite(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color, 32, 32, 1, asteroidSpriteTiles);
    this -> AddAttribute(asteroidSprite);
}

void Asteroid::Update()
{
    WrappingObject::Update();
    Move();
}

void Asteroid::Move()
{
    transform -> x += velX;
    transform -> y += velY;
}