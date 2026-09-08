#pragma once

#include "player.h"

#include <string>



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
    std::string floorTex;


    void init();
    void draw();
    void update();
    void spawnAdds();
    void addCurrency();
};