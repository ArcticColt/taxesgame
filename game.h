#pragma once

#include <vector>

class Entity;

extern std::vector<Entity*> globalDrawList;

void draw_sprite(const char* texture, float x, float y, float scale);