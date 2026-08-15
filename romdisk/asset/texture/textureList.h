#pragma once

#include <unordered_map>
#include <string>

struct TextureList{
    const char *name;
    const char *path;
    int width;
    int height;
    int format;
    uint32_t alphaType;
};

//dictionary
std::unordered_map<std::string, TextureList> textureMeta = {
    /*#define PNG_NO_ALPHA 0
    #define PNG_MASK_ALPHA 1
    #define PNG_FULL_ALPHA 2*/
    {"koffiaRun", {"koffiaRun", "/rd/asset/texture/koffiaRunning.png", 512, 32, PVR_TXRFMT_ARGB1555, 1}},
    {"sylveon", {"sylveon", "/rd/asset/texture/sylveon.png", 1024, 512, PVR_TXRFMT_RGB565, 0}}
};