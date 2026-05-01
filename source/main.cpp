#include <nds.h>
#include "scene.h"
#include "hwmgr.h"
#include "object.h"

int main(void) 
{
    // Create and get the reference to the hardware manager
    HWManager::Create();
    //HWManager* hwm = HWManager::getInstance();

    Scene curScene = Scene("curScene");
    Object newObject = Object("newObject");

    curScene.AddObject(&newObject);
    curScene.AddObject("TestObject");

    while(1)
    {
        
    }
}