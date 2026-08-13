#pragma once

#include <unordered_map>
#include <string>

struct TextureList{
    const char *path;
    int width;
    int height;
    int format;
    uint32_t alphaType;
    int xframes;
    int yframes;
};

//dictionary
std::unordered_map<std::string, TextureList> textures = {
    {"koffiaRun", {"/rd/asset/texture/koffiaRunning.png", 512, 64, PVR_TXRFMT_ARGB1555, PNG_MASK_ALPHA, 12, 1}}
};