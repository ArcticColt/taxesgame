#pragma once

#include <vector>
#include <tuple>
#include <string>

#include <cstdint>

class Drawable;
class Entity;
class Player;

extern std::vector<Drawable*> globalDrawList;
extern std::vector<Entity*> globalUpdateList;
extern std::vector<Player*> players;

uint8_t load_texture(std::string texture);
void draw_sprite(const char* texture, float x, float y, float depth);
void draw_sprite(const char* texture, float x, float y, float depth, int width, int height, float u, float v, float uwid, float vhig);
Player* getNearestPlayer(float x, float y);
std::tuple<float, float> vectorNormalize(std::tuple<float, float>);