#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include "object.h"

class Scene {
    public:
        std::string sceneName;

        Scene(std::string);

        virtual void Load();
        virtual void Unload();

        int AddObject(Object*);
        Object* AddObject(std::string);
        int RemoveObject(Object*);

    protected:
        std::vector<Object*> _objects;
};

#endif