#include "../game.h"
#include "eneTrapper.h"
#include "drawable.h"
#include "player.h"
#include "math.h"

#include <tuple>

EneTrapper::EneTrapper()
{
    frame = 0.0f;
    globalDrawList.push_back(this);
    globalUpdateList.push_back(this);
    x = 420;
    y = 20;
    health = 10;
    speed = 0.03;
}

void EneTrapper::draw(){
    draw_sprite("eneTrapper", x, y, depth);
}

void EneTrapper::update(){
    frame += 0.35f;
    if (frame >= 12.0f)
        frame -= 12.0f;
    Player* plyr = getNearestPlayer(x, y);
    if (plyr == nullptr)
        return;
    float px = plyr->x - x;
    float py = plyr->y - y;
    if (hypot(px, py) < 128)
    {
        std::tuple<float, float> mov = vectorNormalize({px, py});
        x -= std::get<0>(mov);
        y -= std::get<1>(mov);
    }
    depth = y;
}