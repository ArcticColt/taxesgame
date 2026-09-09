#pragma once

#include <unordered_map>
#include <string>

struct TextureList{
    const char *name;
    const char *path;
    int width;
    int height;
    //int format;
    //uint32_t alphaType;
};

//dictionary
inline std::unordered_map<std::string, TextureList> textureMeta = {
    /*#define PNG_NO_ALPHA 0
    #define PNG_MASK_ALPHA 1
    #define PNG_FULL_ALPHA 2*/
    {"koffiaRun", {"koffiaRun", "/rd/asset/texture/koffiaRunning.png", 512, 32}},//, PVR_TXRFMT_ARGB1555, 1}},
    {"enemy1", {"enemy1", "/rd/asset/texture/enemy1.png", 32, 32}},
    {"eneTrapper", {"eneTrapper", "/rd/asset/texture/enemyTrapper.png", 64, 64}},
    {"pistol", {"pistol", "/rd/asset/texture/pistola.png", 32, 32}},
    {"BGDLevel1", {"BGDLevel1", "/rd/asset/texture/level1Floor.png", 32, 32}},
};