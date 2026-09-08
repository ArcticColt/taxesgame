#include "../game.h"
#include "level.h"
#include "enemy.h"
#include "player.h"

Level::Level()
{
    level = 1;
    spawnCurrency = 0;//spawn adds, but how strong?
    currencyTimerReset = 1.0f;
    currencyTimer = currencyTimerReset;//how long until we add money to the currency amount
    currencyTimerLossRate = 0.1f;
    currencyAdd = 10.0f;//how much currency to add when invoked
}

void Level::init()
{
    P1 = new Player();
    P2 = nullptr;
    P3 = nullptr;
    P4 = nullptr;
    Enemy *enemy = new Enemy();
    switch (level)
    {
        //1
        default:
            load_texture("BGDLevel1");
            floorTex = "BGDLevel1";
        break;
    }
}

void Level::update()
{



    currencyTimer -= currencyTimerLossRate;
    if (currencyTimer <= 0)
    {
        currencyTimer += currencyTimerReset;
        addCurrency();
    }
}

void Level::draw()
{
    //draw the floor
    for (int8_t x = 0; x < 5; x ++)
    {
        for (int8_t y = 0; y < 5; y ++)
        {
            draw_sprite("BGDLevel1", 32*x, 32*y, 1.0f);
        }
    }
}

void Level::spawnAdds()
{

}

void Level::addCurrency()
{

}