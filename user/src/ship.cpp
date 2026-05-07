#include "ship.h"
#include "ds.h"
#include "attributes.h"

#include <math.h>

Ship::Ship(std::string name) : Object(name)
{
    // Set up the transform with generic object init
    Init();

    // Set up the sprite
    Sprite* dsSprite = new Sprite(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color, 64, 64, 1, dsTiles);
    this -> AddAttribute(dsSprite);
}

void Ship::Update()
{
    Object::Update();
    MoveShip();
}

void Ship::MoveShip()
{
    Rotate();
    Move();
    Wrap();
}

void Ship::Wrap()
{
    int xpos = transform -> x;
    if(xpos >= 220)
    {
        transform -> x = -63;
    }
    else if(xpos <= -64)
    {
        transform -> x = 221;
    }

    int ypos = transform -> y;
    if(ypos <= -64)
    {
        transform -> y = 191;
    }

    if(ypos >= 192)
    {
        transform -> y = -63;
    }
}

void Ship::Move()
{
    // Get user input
    if(keysHeld() & KEY_UP)
    {
        vel += MOVE_SPEED;
    }

    if(keysHeld() & KEY_DOWN)
    {
        vel -= MOVE_SPEED;
    }

    // Limit velocity
    if(vel > MAX_VEL)
    {
        vel = MAX_VEL;
    }

    if(vel < -MAX_VEL)
    {
        vel = -MAX_VEL;
    }

    // Damping
    vel = vel * VEL_DAMPING;
    if(abs(vel) < 0.1)
    {
        vel = 0;
    }

    // Calculate and set the new positions
    int newX = transform -> x + (int)(cos(transform -> GetRotationRadians()) * vel);
    int newY = transform -> y - (int)(sin(transform -> GetRotationRadians()) * vel);

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