#include "dsge.h"
#include "shipSprite.h"
#include "ship.h"
#include "asteroid.h"

#include <math.h>
#include <ctime>

int main(void) 
{
    // Create and get the reference to the hardware manager
    HWManager::Create();
    HWManager* hwm = HWManager::getInstance();

    Ship newShip = Ship("Playership", 16);
    Asteroid newAsteroid = Asteroid("Asteroid", 16);

    // Create the palette
    dmaCopy(shipSpritePal, SPRITE_PALETTE, shipSpritePalLen);
    dmaCopy(shipSpritePal, SPRITE_PALETTE_SUB, shipSpritePalLen);

    while(1)
    {
        scanKeys();
        newShip.Update();
        newAsteroid.Update();

        Debug::Get().Print(std::to_string(newShip.transform -> x) + "\n" + std::to_string(newShip.transform -> y));

        hwm -> RenderScreens();
    }
}