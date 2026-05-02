#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>
#include "attribute.h"
#include "transform.h"

class Object {
    public:
        std::string objectName;

        Transform* transform;

        Object(std::string);
        int AddAttribute(Attribute* attr);

    protected:
        std::vector<Attribute*> _attributes;
        virtual void Init();
};

#endif