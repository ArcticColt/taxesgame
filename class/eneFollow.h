#pragma once

#include "entity.h"
#include "drawable.h"
#include "player.h"

//class Player;

class EneFollow : public Entity, public Drawable {
public:
    EneFollow();
    float frame;
    float health;
    float speed;

    void draw() override;
    void update() override;
};