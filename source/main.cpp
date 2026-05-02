#include "dsge.h"
#include "sprite.h"

int main(void) 
{
    // Create and get the reference to the hardware manager
    HWManager::Create();

    Scene curScene = Scene("curScene");
    Object newObject = Object("newObject");

    curScene.AddObject(&newObject);

    Sprite newSprite = Sprite(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color, 1);
    newSprite.SetObject(&newObject);

    while(1)
    {
        Debug::Get().Print(newObject.objectName);
        newSprite.render(0, 64, 64);
    }
}