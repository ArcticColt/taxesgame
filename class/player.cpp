#include "../game.h"
#include "player.h"
#include "drawable.h"



Player::Player()
{
    frame = 0;
    globalDrawList.push_back(this);
}

void Player::draw(){
    draw_sprite("koffiaRun", 15.0f, 15.0f, 1.0f);
}

void Player::update(){
}