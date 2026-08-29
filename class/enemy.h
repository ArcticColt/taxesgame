#pragma once

#include "entity.h"
#include "drawable.h"
#include "player.h"

//class Player;

class Enemy : public Entity, public Drawable {
public:
    Enemy();
    float frame;
    float health;
    float speed;

    void draw() override;
    void update() override;
};