#include "ship.h"
#include "shipSprite.h"
#include "attributes.h"

#include <math.h>

Ship::Ship(std::string name, int spriteHalfSize) : WrappingObject(name, spriteHalfSize)
{
    // Set up the transform with generic object init
    Init();

    // Set up the sprite
    Sprite* shipSprite = new Sprite(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color, 32, 32, 1, shipSpriteTiles);
    this -> AddAttribute(shipSprite);
}

void Ship::Update()
{
    WrappingObject::Update();
    MoveShip();
}

void Ship::MoveShip()
{
    Rotate();
    Move();
}

void Ship::Move()
{
    float rotationRadians = transform -> GetRotationRadians();
    
    // Get user input
    if((keysHeld() & KEY_UP))
    {
        // Decompose the forces
        float xForce = cos(rotationRadians) * MOVE_SPEED;
        float yForce = sin(rotationRadians) * MOVE_SPEED;

        // Add the forces
        velX += xForce;
        velY += yForce;
    }

    if (keysHeld() & KEY_DOWN)
    {
        // Decompose the forces
        float xForce = cos(rotationRadians) * -MOVE_SPEED;
        float yForce = sin(rotationRadians) * -MOVE_SPEED;

        // Add the forces
        velX += xForce;
        velY += yForce;
    }

    // Limit velocity
    if(velX > MAX_VEL)
    {
        velX = MAX_VEL;
    }

    if(velX < -MAX_VEL)
    {
        velX = -MAX_VEL;
    }

    if(velY > MAX_VEL)
    {
        velY = MAX_VEL;
    }

    if(velY < -MAX_VEL)
    {
        velY = -MAX_VEL;
    }

    // Damping X
    velX = velX * VEL_DAMPING;
    if(abs(velX) < 0.1)
    {
        velX = 0;
    }

    // Damping Y
    velY = velY * VEL_DAMPING;
    if(abs(velY) < 0.1)
    {
        velY = 0;
    }

    // Calculate and set positions
    int newX = transform -> x + (int)(velX);
    int newY = transform -> y - (int)(velY);

    transform -> SetPosition(newX, newY);
}

void Ship::Rotate()
{
    int curRotation = transform -> GetRotation();

    // Apply clockwise rotation force
    if(keysHeld() & KEY_R)
    {
        rotVel -= ROT_SPEED;
    }

    // Apply counterclockwise rotation foce
    if(keysHeld() & KEY_L)
    {
        rotVel += ROT_SPEED;
    }

    // Apply rotation damping
    rotVel = rotVel * ROT_DAMPING;
    if(abs(rotVel) < 0.1)
    {
        rotVel = 0;
    }

    // Apply the rotation
    transform -> SetRotation(curRotation + rotVel);
}