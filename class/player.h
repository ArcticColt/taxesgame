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
    bool dead;

    void draw() override;
    void update() override;
};