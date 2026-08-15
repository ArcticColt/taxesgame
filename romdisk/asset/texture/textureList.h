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
    {"koffiaRun", {"koffiaRun", "/rd/asset/texture/koffiaRunning.png", 512, 32, PVR_TXRFMT_ARGB1555, PNG_MASK_ALPHA}},
    {"sylveon", {"sylveon", "/rd/asset/texture/sylveon.png", 1024, 512, PVR_TXRFMT_RGB565, PNG_NO_ALPHA}}
};