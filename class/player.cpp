#include <kos.h>

#include "../game.h"
#include "player.h"
#include "drawable.h"
#include "camera.h"



Player::Player()
{
    frame = 0.0f;
    globalDrawList.push_back(this);
    globalUpdateList.push_back(this);
    players.push_back(this);
    x = 160.0f;
    y = 160.0f;
    joyx = 0.0f;
    joyy = 0.0f;
    port = 0;
    speed = 2.0f;//0.03125f;
    health = 10.0f;
    dead = false;
    moveAngle = 0.70710677;
}

void Player::draw(){
    float spriteU = float(int(frame)) * 0.0625f;
    float spriteUHead = float(int(frame) % 6) * 0.03125f;
    draw_sprite("koffiaRun", x, y, depth, 32, 32, spriteU, 0.0f, 0.0625f, 1.0f);
    draw_sprite("koffiaRun", x+10, y-16, depth, 16, 16, 0.75+spriteUHead, 0.5f, 0.03125f, 0.5f);
    depth = y;

    //rotate gun
}

void Player::update(){
    frame += 0.35f;
    if (frame >= 12.0f)
        frame -= 12.0f;
    MAPLE_FOREACH_BEGIN(MAPLE_FUNC_CONTROLLER, cont_state_t, t)

        joyx = t->joyx;
        joyy = t->joyy;


        bool u = t->buttons & CONT_Y;
        bool d = t->buttons & CONT_A;
        bool l = t->buttons & CONT_X;
        bool r = t->buttons & CONT_B;

        if (u || d || l || r)
        {
            int8_t field = r | l << 1| d << 2 | u << 3;
            switch (field)
            {
                //up
                case 0b1011:
                case 0b1000:
                    y -= speed;
                break;

                //up right
                case 0b1001:
                    x += speed*moveAngle;
                    y -= speed*moveAngle;
                break;

                //right
                case 0b1101:
                case 0b0001:
                    x += speed;
                break;

                //down right
                case 0b0101:
                    x += speed*moveAngle;
                    y += speed*moveAngle;
                break;

                //down
                case 0b0100:
                case 0b0111:
                    y += speed;
                break;

                //down left
                case 0b0110:
                    x -= speed*moveAngle;
                    y += speed*moveAngle;
                break;

                //left
                case 0b1110:
                case 0b0010:
                    x -= speed;
                break;

                //up left
                case 0b1010:
                    x -= speed*moveAngle;
                    y -= speed*moveAngle;
                break;
            }
        }
        

    MAPLE_FOREACH_END()

    camera.x = x - 304;
    camera.y = y - 216;
}