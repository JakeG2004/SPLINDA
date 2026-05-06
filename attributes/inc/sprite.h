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
        int width = 0;
        int height = 0;

    public:
        Sprite(OamState* objOam, SpriteSize objSize, SpriteColorFormat objFormat, int sizeX, int sizeY, int newNumSprites, const void* data = nullptr, int frame = 0)
            : numSprites(newNumSprites), 
            oam(objOam), 
            size(objSize), 
            colorFormat(objFormat) 
        {
            width = sizeX;
            height = sizeY;

            gfx = (u16**)malloc(sizeof(u16*) * numSprites);
            for(int i = 0; i < numSprites; i++) {
                gfx[i] = oamAllocateGfx(oam, size, colorFormat);
            }
            spriteID = SpriteManager::CreateUniqueSpriteID(objOam);

            loadGfx(data, frame);
        }

        // New method to load the data from the generated header files
        void loadGfx(const void* data, int frame) {
            if (frame >= 0 && frame < numSprites) {
                // TODO: Make this determine the size of each sprite
                dmaCopy(data, gfx[frame], width * height);
            }
        }

        void Update() {
            render(0, width, height);
        }

    private:
        void render(int frame, int width, int height) 
        {
            int x = _object -> transform -> x;
            int y = _object -> transform -> y;

            // Safety check to ensure we don't go out of bounds of our gfx array
            if (frame < 0 || frame >= numSprites) frame = 0;

            // Directly use the pointer we allocated for this specific frame
            u16* framePtr = gfx[frame];

            oamRotateScale(oam, spriteID, _object -> transform -> rotation, _object -> transform -> GetScaleX(), _object -> transform -> GetScaleY());

            // Use the internal spriteID instead of passing one in
            oamSet(oam, spriteID, x, y, 0, 0, size, colorFormat, 
                framePtr, spriteID, true, isHidden, false, false, false);
        }
};

#endif