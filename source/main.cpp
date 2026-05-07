#include "dsge.h"
#include "shipSprite.h"
#include "ship.h"

#include <math.h>
#include <ctime>

int main(void) 
{
    // Create and get the reference to the hardware manager
    HWManager::Create();
    HWManager* hwm = HWManager::getInstance();

    Ship newShip = Ship("Playership");

    // Create the palette
    dmaCopy(shipSpritePal, SPRITE_PALETTE, shipSpritePalLen);
    dmaCopy(shipSpritePal, SPRITE_PALETTE_SUB, shipSpritePalLen);

    while(1)
    {
        scanKeys();
        newShip.Update();

        Debug::Get().Print(std::to_string(newShip.transform -> x) + "\n" + std::to_string(newShip.transform -> y));

        hwm -> RenderScreens();
    }
}