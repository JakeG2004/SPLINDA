#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
    public:
        std::string objectName;

        Object(std::string);

    protected:
        virtual void Init();
};

#endif