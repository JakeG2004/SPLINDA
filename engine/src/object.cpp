#include "object.h"
#include <string>
#include <vector>

// Constructor
Object::Object(std::string objName) {
    objectName = objName;
    Init();
}

// Init function
void Object::Init() {
    transform = new Transform();
}

int Object::AddAttribute(Attribute* attr) {
    attr -> SetObject(this);
    _attributes.push_back(attr);
    return 1;
}