#pragma once

#include <vector>

class Drawable;

extern std::vector<Drawable*> globalDrawList;

void draw_sprite(const char*, float, float, float, float, float, float, float);