#include "object.h"
#include <string>

// Constructor
Object::Object(std::string objName) {
    objectName = objName;
    Init();
}

// Init function
void Object::Init() {

}