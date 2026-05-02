#include "dsge.h"

int main(void) 
{
    // Create and get the reference to the hardware manager
    HWManager::Create();

    Scene curScene = Scene("curScene");
    Object newObject = Object("newObject");

    curScene.AddObject(&newObject);
    curScene.AddObject("TestObject");

    while(1)
    {
        Debug::Get().Print(newObject.objectName);
    }
}