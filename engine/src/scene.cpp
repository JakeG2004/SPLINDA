#include "scene.h"
#include <string>
#include <algorithm>

// Constructor
Scene::Scene(std::string newSceneName) {
    sceneName = newSceneName;
}

// Loads all of its child objects into memory
void Scene::Load() {

}

// Unloads all of its child objects from memory
void Scene::Unload() {

}

// Adds an object to the object vector in the scene
int Scene::AddObject(Object* obj) {
    if(obj == nullptr) {
        return 1;
    }

    _objects.push_back(obj);
    return 0;
}

// Override for AddObject which also creates an object
Object* Scene::AddObject(std::string objName) {
    Object* newObj = new Object(objName);

    if(newObj == nullptr) {
        return nullptr;
    }

    AddObject(newObj);

    return newObj;
}

// Removes an object from the vector in the scene
int Scene::RemoveObject(Object* obj) {
    if(obj == nullptr) {
        return 1;
    }

    auto curObj = std::find(_objects.begin(), _objects.end(), obj);

    if(curObj != _objects.end()) {
        _objects.erase(curObj);
        return 0;
    }

    return 2;
}