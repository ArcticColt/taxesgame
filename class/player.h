#pragma once

#include "entity.h"
#include "drawable.h"

class Player : public Entity, public Drawable {
public:
    Player();
    int frame;

    void draw() override;
    void update();
};