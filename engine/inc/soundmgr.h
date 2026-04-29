/* soundmgr.h
/ Header for soundmgr.cpp
/ Written by Jake Gendreau
/ 03/02/2026
*/

#ifndef SOUNDMGR_H
#define SOUNDMGR_H

#include <maxmod9.h>
#include "soundbank.h"

class SoundManager
{
    public:
        static SoundManager* instance;
        static SoundManager* getInstance();
        
        static void Create();
        
        // SFX Functions
        void LoadSounds(int sfxList[], int numSounds);
        void UnloadSounds(int sfxList[], int numSounds);
        short PlaySound(int soundId, int loadOnFly = 0);
        short PlaySoundEX(int soundId, short rate = 1024, short handle = 0, char volume = 255, char panning = 127, int loadOnFly = 0);

        // Music Functions
        void LoadMusic(int musicList[], int numMusic);
        void UnloadMusic(int musicList[], int numMusic);

        // Music Playback
        void PlayMusic(int musicId, mm_pmode mode);
        void PauseMusic();
        void ResumeMusic();
        void StopMusic();
        void SetMusicPosition(int pos);

        // Music metadata
        void SetMusicVolume(int vol);
        void SetMusicTempo(int tempo);
        void SetMusicPitch(int pitch);

    private:     
        SoundManager();
};

#endif