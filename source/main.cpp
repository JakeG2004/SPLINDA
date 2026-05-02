#include "dsge.h"
#include "sprite.h"
#include "test.h"

int main(void) 
{
    // Create and get the reference to the hardware manager
    HWManager::Create();

    Scene curScene = Scene("curScene");
    Object newObject = Object("newObject");

    curScene.AddObject(&newObject);

    // Create the sprites
    Sprite* testSprite = new Sprite(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color, 1);
    testSprite -> loadGfx(testTiles, 0);

    // Create the pallette
    vramSetBankF(VRAM_F_LCD);
    dmaCopy(testPal, VRAM_F_EXT_SPR_PALETTE[0], testPalLen);
    vramSetBankF(VRAM_F_OBJ_EXT_PALETTE);

    while(1)
    {
        testSprite.render(0, 64, 64);
    }
}