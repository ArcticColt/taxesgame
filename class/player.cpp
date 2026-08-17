#include <kos.h>

#include "../game.h"
#include "player.h"
#include "drawable.h"



Player::Player()
{
    frame = 0.0f;
    globalDrawList.push_back(this);
    globalUpdateList.push_back(this);
    x = 160;
    y = 160;
    port = 0;
    speed = 4;
}

void Player::draw(){
    float spriteU = float(int(frame)) * 0.0625f;
    float spriteUHead = float(int(frame) % 6) * 0.03125f;
    draw_sprite("koffiaRun", x, y, 1.0f, 32, 32, spriteU, 0.0f, 0.0625f, 1.0f);
    draw_sprite("koffiaRun", x+10, y-16, 1.0f, 16, 16, 0.75+spriteUHead, 0.5f, 0.03125f, 0.5f);
}

void Player::update(){
    frame += 0.35f;
    if (frame >= 12.0f)
        frame -= 12.0f;
    MAPLE_FOREACH_BEGIN(MAPLE_FUNC_CONTROLLER, cont_state_t, t)

    if(t->joyx != 0) {
        x += joyx*speed;
    }
    if(t->joyy != 0) {
        y += joyy*speed;
    }
    }

    MAPLE_FOREACH_END()
}