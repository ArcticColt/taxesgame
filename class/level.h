#pragma once

#include "player.h"



class Player;

class Level{
public:
    Level();
    int level;
    int spawnCurrency;
    float currencyTimerReset;
    float currencyTimer;
    float currencyTimerLossRate;
    Player* P1;
    Player* P2;
    Player* P3;
    Player* P4;


    void init();
    void update();
    void spawnAdds();
    void addCurrency();
};