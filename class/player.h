#pragma once

#include "entity.h"
#include "drawable.h"

class Player : public Entity, public Drawable {
public:
    Player();
    float frame;

    void draw() override;
    void update();
};