/* soundmgr.cpp
/ A Sound Manager class for the DSGE libnds API
/ Written by Jake Gendreau
/ 03/02/2026
/
*/

#include "soundmgr.h"

#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

// Singleton pattern
SoundManager* SoundManager::instance = nullptr;

// Private constructor
SoundManager::SoundManager()
{
    mmInitDefaultMem((mm_addr)soundbank_bin);
}

// Public Create function
void SoundManager::Create()
{
    if(instance == nullptr)
    {
        instance = new SoundManager();
    }
}

// Instance getter
SoundManager* SoundManager::getInstance()
{
    return instance;
}

// Load in multiple sounds at once
void SoundManager::LoadSounds(int sfxList[], int numSounds)
{
    for(int i = 0; i < numSounds; i++)
    {
        mmLoadEffect(sfxList[i]);
    }
}

// Unload multiple sounds at once
void SoundManager::UnloadSounds(int sfxList[], int numSounds)
{
    for(int i = 0; i < numSounds; i++)
    {
        mmUnloadEffect(sfxList[i]);
    }
}

// Plays a sound effect
short SoundManager::PlaySound(int soundId, int loadOnFly)
{
    if(loadOnFly == 1)
    {
        mmLoadEffect(soundId);
    }
 
    return mmEffect(soundId);
}

// Plays a sound effect allowing for customizations
short SoundManager::PlaySoundEX(int soundId, short rate, short handle, char volume, char panning, int loadOnFly)
{
    if(loadOnFly == 1)
    {
        mmLoadEffect(soundId);
    }

	mm_sound_effect sound = {
		{ (mm_word)soundId },
		(mm_hword)rate,
		(mm_sfxhand)handle, 
		volume,
		panning
	};

    return mmEffectEx(&sound);
}

// Loads in music tracks
void SoundManager::LoadMusic(int musicList[], int numMusic)
{
    for(int i = 0; i < numMusic; i++)
    {
        mmLoad(musicList[i]);
    }
}

// Unloads music tracks
void SoundManager::UnloadMusic(int musicList[], int numMusic)
{
    for(int i = 0; i < numMusic; i++)
    {
        mmUnload(musicList[i]);
    }
}

// Plays a music track. Does nothing if music already playing
void SoundManager::PlayMusic(int musicId, mm_pmode mode)
{
    if(mmActive())
    {
        return;
    }

    mmStart(musicId, mode);
}

// Pauses a music track
void SoundManager::PauseMusic()
{
    mmPause();
}

// Resumes a music track
void SoundManager::ResumeMusic()
{
    mmResume();
}

// Stops a music track
void SoundManager::StopMusic()
{
    mmStop();
}

// Sets a music track playback position
void SoundManager::SetMusicPosition(int pos)
{
    mmPosition(pos);
}

// Sets volume. Documentation at
// https://maxmod.org/ref/functions/mmSetModuleVolume.html
void SoundManager::SetMusicVolume(int vol)
{
    mmSetModuleVolume(vol);
}

// Sets tempo. Documentation at
// https://maxmod.org/ref/functions/mmSetModuleTempo.html
void SoundManager::SetMusicTempo(int tempo)
{
    mmSetModuleTempo(tempo);
}

// Sets pitch. Documentation at
// https://maxmod.org/ref/functions/mmSetModulePitch.html
void SoundManager::SetMusicPitch(int pitch)
{
    mmSetModulePitch(pitch);
}