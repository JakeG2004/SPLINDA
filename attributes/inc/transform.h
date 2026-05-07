#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "attribute.h"

class Transform : public Attribute {
    public:
        Transform();

        int x = 0;
        int y = 0;

        float scalerX = 1;
        float scalerY = 1;

        // Rotation stored as libnds expects (-32768, 32767)
        int rotation = 0;

        void SetPosition(int, int);

        // Several options for rotating sprites
        void SetRotationRadians(float);
        void SetRotation(int);
        void SetRotationDegrees(float);

        // Set inverse scale factor. larger number -> smaller sprite. smaller number -> larger sprite
        void SetInvScale(float, float);

        // Getters for rotations
        float GetRotationDegrees();
        float GetRotationRadians();
        int GetRotation();

        // Getters for scales
        int GetScaleX();
        int GetScaleY();

    protected:
        int scaleX = 255;
        int scaleY = 255;
};

#endif