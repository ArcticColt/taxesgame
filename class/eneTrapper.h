#pragma once

#include "entity.h"
#include "drawable.h"
#include "player.h"

//class Player;

class EneTrapper : public Entity, public Drawable {
public:
    EneTrapper();
    float frame;
    float health;
    float speed;

    void draw() override;
    void update() override;
};