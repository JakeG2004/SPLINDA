#include <nds.h> // DS Hardware requirements
#include "hwmgr.h"

// Use the singleton pattern
HWManager* HWManager::instance = nullptr;

// Private constructor so that other scripts don't accidentally activate it
HWManager::HWManager()
{
    InitScreens();
}

// Publicly accessible Create() function for singleton pattern
void HWManager::Create() 
{
    if (instance == nullptr) 
    {
        instance = new HWManager();
    }
}

HWManager* HWManager::getInstance() 
{
    return instance;
}

// TODO: Support more video modes
void HWManager::InitScreens()
{
    // Setup Video Modes for Tiled Graphics (Mode 0)
    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);

    // Map VRAM Banks
    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankB(VRAM_B_MAIN_SPRITE);
    vramSetBankC(VRAM_C_SUB_BG);
    vramSetBankD(VRAM_D_SUB_SPRITE);

    // This line enables writing to the bottom screen
    consoleDemoInit();

    // Initialize the Sprite Engines
    oamInit(&oamMain, SpriteMapping_1D_32, false);
    oamInit(&oamSub, SpriteMapping_1D_32, false);
}

void HWManager::RenderScreens()
{
    // Wait for screen to finish drawing
    swiWaitForVBlank();

    // Commit the changes to hardware
    oamUpdate(&oamMain);
    oamUpdate(&oamSub);
}