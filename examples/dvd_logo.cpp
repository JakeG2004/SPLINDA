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
    newObject.transform -> SetPosition(128, 96);

    // Create the sprites
    Sprite* dsSprite = new Sprite(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color, 64, 64, 1, dsTiles);

    newObject.AddAttribute(dsSprite);

    // Create the palette
    dmaCopy(dsPal, SPRITE_PALETTE, dsPalLen);
    dmaCopy(dsPal, SPRITE_PALETTE_SUB, dsPalLen);

    const float PI = 3.142;

    srand(time(0));
    float angle = 2 * PI * ((float)rand() / (float)(2 * PI));
    int speed = 3;

    while(1)
    {
        newObject.Update();

        // Calculate new position
        float nextX = newObject.transform->x + (cos(angle) * speed);
        float nextY = newObject.transform->y + (sin(angle) * speed);

        // Bounce off right side (account for 64px sprite width)
        if (nextX > 192) {
            nextX = 192;
            angle = PI - angle;
        }

        // Bounce off left side
        else if (nextX < 0) {
            nextX = 0;
            angle = PI - angle;
        }

        // Bounce off bottom (account for 64px sprite height)
        if (nextY > 128) {
            nextY = 128;
            angle = -angle; 
        }

        // Bounce off top
        else if (nextY < 0) {
            nextY = 0;
            angle = -angle;
        }

        angle = fmodf(angle, 2.0f * PI);

        if(abs((PI / 2) - angle) < 0.1f) {
            angle += 0.1f;
        }

        Debug::Get().Print(std::to_string(angle));

        // Set the new positions
        newObject.transform->SetPosition(nextX, nextY);

        hwm -> RenderScreens();
    }
}