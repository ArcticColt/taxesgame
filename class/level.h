#pragma once

#include "player.h"



class Player;

class Level{
public:
    Level();
    int level;
    float spawnCurrency;
    float currencyTimerReset;
    float currencyTimer;
    float currencyTimerLossRate;
    float currencyAdd;
    Player *P1;
    Player *P2;
    Player *P3;
    Player *P4;


    void init();
    void update();
    void spawnAdds();
    void addCurrency();
};