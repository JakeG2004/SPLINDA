#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

class Object;

class Attribute {
    public:
        Attribute();
        Attribute(Object* obj);
        
        void SetObject(Object* obj);

    protected:
        Object* _object;
};

#endif