#pragma once

#include "entity.h"

//class Entity;

class Camera {
public:
    Camera();

    float x;//position in-level
    float y;
    int hpos;//position on-screen
    int vpos;
    int wid;//size
    int hig;

    void draw();
    void _draw_texture(const char* texture, float x, float y, float depth, int width, int height, float u, float v, float uwid, float vhig);
};