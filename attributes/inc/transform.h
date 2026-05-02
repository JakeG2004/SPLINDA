#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "attribute.h"

class Transform : public Attribute {
    public:
        Transform();

        int x;
        int y;

        void SetPosition(int, int);
};

#endif