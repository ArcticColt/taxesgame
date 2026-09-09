#include "../game.h"
#include "eneFollow.h"
#include "drawable.h"
#include "player.h"

#include <tuple>

EneFollow::EneFollow()
{
    frame = 0.0f;
    globalDrawList.push_back(this);
    globalUpdateList.push_back(this);
    x = 20;
    y = 20;
    health = 10;
    speed = 0.03;
}

void EneFollow::draw(){
    draw_sprite("enemy1", x, y, depth);
}

void EneFollow::update(){
    frame += 0.35f;
    if (frame >= 12.0f)
        frame -= 12.0f;
    Player* plyr = getNearestPlayer(x, y);
    if (plyr == nullptr)
        return;
    std::tuple<float, float> mov = vectorNormalize({plyr->x - x, plyr->y - y});
    x += std::get<0>(mov);
    y += std::get<1>(mov);
    depth = y;
}