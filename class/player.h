#pragma once

#include "entity.h"
#include "drawable.h"

class Player : public Entity, public Drawable {
public:
    Player();
    float frame;
    int8_t port;
    float speed;
    float health;

    void draw() override;
    void update() override;
};