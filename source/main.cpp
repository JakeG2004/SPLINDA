#include "dsge.h"
#include "sprite.h"
#include "test.h"

int main(void) 
{
    // Create and get the reference to the hardware manager
    HWManager::Create();
    HWManager* hwm = HWManager::getInstance();

    Scene curScene = Scene("curScene");
    Object newObject = Object("newObject");

    curScene.AddObject(&newObject);

    // Create the sprites
    Sprite* testSprite = new Sprite(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color, 1);
    testSprite -> loadGfx(testTiles, 0);

    newObject.AddAttribute(testSprite);

    // Create the palette
    dmaCopy(testPal, SPRITE_PALETTE, testPalLen);
    dmaCopy(testPal, SPRITE_PALETTE_SUB, testPalLen);

    while(1)
    {
        newObject.Update();

        newObject.transform -> SetPosition(newObject.transform -> x + 1, 0);
        if(newObject.transform -> x >= 256) {
            newObject.transform -> x = 0;
        }

        hwm -> RenderScreens();
    }
}