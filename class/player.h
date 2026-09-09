#pragma once

#include "entity.h"
#include "drawable.h"
#include "camera.h"

#include <cstdint>

class Camera;

class Player : public Entity, public Drawable {
public:
    Player();
    float frame;
    int8_t port;
    float speed;
    float health;
    float joyx;
    float joyy;
    bool dead;
    float moveAngle;
    Camera camera;

    void draw() override;
    void update() override;
};