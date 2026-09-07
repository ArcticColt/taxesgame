#pragma once

#include "entity.h"
#include "drawable.h"

#include <cstdint>

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

    void draw() override;
    void update() override;
};