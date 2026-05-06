#include "dsge.h"
#include "ds.h"

#include <math.h>
#include <ctime>

int main(void) 
{
    // Create and get the reference to the hardware manager
    HWManager::Create();
    HWManager* hwm = HWManager::getInstance();

    Scene curScene = Scene("curScene");
    Object newObject = Object("newObject");

    curScene.AddObject(&newObject);

    // Create the sprites
    Sprite* dsSprite = new Sprite(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color, 64, 64, 1, dsTiles);

    newObject.AddAttribute(dsSprite);

    // Create the palette
    dmaCopy(dsPal, SPRITE_PALETTE, dsPalLen);
    dmaCopy(dsPal, SPRITE_PALETTE_SUB, dsPalLen);

    while(1)
    {
        newObject.Update();
        scanKeys();

        // Rotate to face right
        if(keysDown() & KEY_A)
        {
            newObject.transform -> SetRotationDegrees(-90);
        }

        // Rotate to face down
        if(keysDown() & KEY_B)
        {
            newObject.transform -> SetRotationDegrees(180);
        }

        // Rotate to face left
        if(keysDown() & KEY_Y)
        {
            newObject.transform -> SetRotationDegrees(90);
        }

        // Rotate to face up
        if(keysDown() & KEY_X)
        {
            newObject.transform -> SetRotationDegrees(0);
        }

        // Scale down
        if(keysDown() & KEY_DOWN)
        {
            newObject.transform -> SetInvScale(newObject.transform -> scalerX * 2, newObject.transform -> scalerY * 2);
        }

        // Scale up
        if(keysDown() & KEY_UP)
        {
            newObject.transform -> SetInvScale(newObject.transform -> scalerX * 0.5, newObject.transform -> scalerY * 0.5);
        }

        Debug::Get().Print(std::to_string(newObject.transform -> rotation) + "\nScaleX: " + std::to_string(newObject.transform -> scalerX) + "\nScaleY: " + std::to_string(newObject.transform -> scalerY));
        

        hwm -> RenderScreens();
    }
}