#include "../game.h"
#include "player.h"
#include "drawable.h"



Player::Player()
{
    frame = 0.0f;
    globalDrawList.push_back(this);
}

void Player::draw(){
    float spriteU = float(int(frame)) * 0.0625f;
    draw_sprite("koffiaRun/0", 15.0f, 15.0f, 1.0f, spriteU, 0.0f, 0.0625f, 1.0f);
}

void Player::update(){
    frame += 0.25f;
    if (frame >= 12.0f)
        frame -= 12.0f;
}