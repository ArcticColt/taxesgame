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
}

void Level::init()
{
    Player *P1;
    Player *P2 = nullptr;
    Player *P3 = nullptr;
    Player *P4 = nullptr;
    Enemy *enemy;
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

void Level::spawnAdds()
{

}

void Level::addCurrency()
{

}