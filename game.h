#pragma once

#include <vector>

class Drawable;
class Entity;

extern std::vector<Drawable*> globalDrawList;
extern std::vector<Entity*> globalUpdateList;

void draw_sprite(const char* texture, float x, float y, float depth, int width, int height, float u, float v, float uwid, float vhig);