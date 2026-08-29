#include "../game.h"
#include "enemy.h"
#include "drawable.h"
#include "player.h"

#include <tuple>

Enemy::Enemy()
{
    frame = 0.0f;
    globalDrawList.push_back(this);
    globalUpdateList.push_back(this);
    x = 20;
    y = 20;
    health = 10;
    speed = 0.03;
}

void Enemy::draw(){
    draw_sprite("enemy1", x, y, 0.9f, 32, 32, 0.0f, 0.0f, 1.0f, 1.0f);
}

void Enemy::update(){
    frame += 0.35f;
    if (frame >= 12.0f)
        frame -= 12.0f;
    Player* plyr = getNearestPlayer(x, y);
    std::tuple<float, float> mov = vectorNormalize({plyr->x - x, plyr->y - y});
    x += std::get<0>(mov);
    y += std::get<1>(mov);
}