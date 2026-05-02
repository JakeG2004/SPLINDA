#ifndef SPRITE_H
#define SPRITE_H

#include <nds.h>
#include "SpriteManager.h"
#include "object.h"

class Sprite : public Attribute {
    private:
        // Graphics Variables
        int numSprites;
        u16** gfx;
        OamState* oam;

        // Sprite Variables
        SpriteSize size;
        SpriteColorFormat colorFormat;
        int spriteID;
        bool isHidden = false;

    public:
        Sprite(OamState* objOam, SpriteSize objSize, SpriteColorFormat objFormat, int newNumSprites)
            : oam(objOam), size(objSize), colorFormat(objFormat), numSprites(newNumSprites) 
        {
            gfx = (u16**)malloc(sizeof(u16*) * numSprites);
            for(int i = 0; i < numSprites; i++) {
                gfx[i] = oamAllocateGfx(oam, size, colorFormat);
            }
            spriteID = SpriteManager::CreateUniqueSpriteID(objOam);
        }

        // New method to load the data from the generated header files
        void loadGfx(const void* data, int frame) {
            if (frame >= 0 && frame < numSprites) {
                // TODO: Make this determine the size of each sprite
                dmaCopy(data, gfx[frame], 64 * 64);
            }
        }

        // Overloaded helper for simpler loading
        void loadAllFrames(const void* data, int bytesPerFrame) {
            for(int i = 0; i < numSprites; i++) {
                u8* offsetData = (u8*)data + (i * bytesPerFrame);
                dmaCopy(offsetData, gfx[i], bytesPerFrame);
            }
        }

        void render(int frame, int width, int height) 
        {
            int x = _object -> transform -> x;
            int y = _object -> transform -> y;

            // Safety check to ensure we don't go out of bounds of our gfx array
            if (frame < 0 || frame >= numSprites) frame = 0;

            // Directly use the pointer we allocated for this specific frame
            u16* framePtr = gfx[frame];

            // Use the internal spriteID instead of passing one in
            oamSet(oam, spriteID, x, y, 0, 0, size, colorFormat, 
                framePtr, -1, false, isHidden, false, false, false);
        }
};

#endif