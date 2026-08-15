#include "../game.h"
#include "player.h"
#include "drawable.h"



Player::Player()
{
    frame = 0.0f;
    globalDrawList.push_back(this);
    x = 160;
    y = 160;
}

void Player::draw(){
    float spriteU = float(int(frame)) * 0.0625f;
    draw_sprite("koffiaRun", x, y, 1.0f, 32, 32, spriteU, 0.0f, 0.0625f, 1.0f);
}

void Player::update(){
    frame += 0.25f;
    if (frame >= 12.0f)
        frame -= 12.0f;
}