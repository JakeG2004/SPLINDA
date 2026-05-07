#include "transform.h"

Transform::Transform() {

}

void Transform::SetPosition(int nX, int nY) {
    x = nX;
    y = nY;
}

void Transform::SetRotation(int rot)
{
    rotation = rot % 32767;
}

void Transform::SetRotationRadians(float rot)
{
    float PI = 3.14;
    SetRotation((int)(rot * (32767 / (2 * PI))));
    
}

void Transform::SetRotationDegrees(float rot)
{
    SetRotation((int)(rot * (32767 / (360))));
}

void Transform::SetInvScale(float sX, float sY)
{
    scalerX = sX;
    scalerY = sY;

    scaleX = scalerX * 255;
    scaleY = scalerY * 255;
}

// GETTERS

float Transform::GetRotationDegrees()
{
    return rotation * (360 / 32767);
}

float Transform::GetRotationRadians()
{
    return rotation * (2 * 3.14 / 32767);
}

int Transform::GetRotation()
{
    return rotation;
}

int Transform::GetScaleX()
{
    return scaleX;
}

int Transform::GetScaleY()
{
    return scaleY;
}