#include "transform.h"

Transform::Transform() {

}

void Transform::SetPosition(int nX, int nY) {
    x = nX;
    y = nY;
}

void Transform::SetRotationBinaryRadians(int rot)
{
    rotation = rot;
}

void Transform::SetRotationRadians(float rot)
{
    float PI = 3.14;
    SetRotationBinaryRadians((int)(rot * (32767 / (2 * PI))));
}

void Transform::SetRotationDegrees(float rot)
{
    float PI = 3.14;
    SetRotationRadians(rot * PI / 180);
}

void Transform::SetInvScale(float sX, float sY)
{
    scalerX = sX;
    scalerY = sY;

    scaleX = scalerX * 255;
    scaleY = scalerY * 255;
}

int Transform::GetScaleX()
{
    return scaleX;
}

int Transform::GetScaleY()
{
    return scaleY;
}