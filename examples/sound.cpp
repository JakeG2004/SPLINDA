#include <nds.h>
#include "hwmgr.h"
#include "soundmgr.h"

int main(void) 
{
    // Create and get the reference to the hardware manager
    HWManager::Create();
    HWManager* hwm = HWManager::getInstance();

    // Create and get the reference to the sound manager
    SoundManager::Create();
    SoundManager* sm = SoundManager::getInstance();

    // Load the sounds
    int numSounds = 1;
    int sounds[numSounds] = {SFX_HIT};
    sm -> LoadSounds(&sounds[0], numSounds);

    int music[1] = {MOD_MUSIC};
    sm -> LoadMusic(&music[0], 1);

    // Update loop
    while(1)
    {
        // Get input and play sound
        scanKeys();
        if(keysDown() & KEY_A)
        {
            sm -> PlaySound(SFX_HIT);
        }

        if(keysDown() & KEY_X)
        {
            sm -> PlaySoundEX(SFX_HIT, rand() % 1025);
        }

        if(keysDown() & KEY_B)
        {
            sm -> PlayMusic(MOD_MUSIC, MM_PLAY_LOOP);
        }

        // Wait for screen to finish drawing
        swiWaitForVBlank();

        // Commit the changes to hardware
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
    }
}