#include "attribute.h"
#include "object.h"

// Constructor
Attribute::Attribute() {
    _object = nullptr;
}

Attribute::Attribute(Object* obj) {
    SetObject(obj);
}

// Sets the object
void Attribute::SetObject(Object* obj) {
    _object = obj;
}

void Attribute::Update() {
    
}