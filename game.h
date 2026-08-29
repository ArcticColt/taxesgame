#pragma once

#include <vector>
#include <tuple>

class Drawable;
class Entity;
class Player;

extern std::vector<Drawable*> globalDrawList;
extern std::vector<Entity*> globalUpdateList;
extern std::vector<Player*> players;

void draw_sprite(const char* texture, float x, float y, float depth, int width, int height, float u, float v, float uwid, float vhig);
Player* getNearestPlayer(float x, float y);
Player vectorNormalize(std::tuple<float, float>);