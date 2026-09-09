#pragma once

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
    void _draw_texture();
};