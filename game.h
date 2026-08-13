#pragma once

#include <vector>

class Drawable;

extern std::vector<Drawable*> globalDrawList;

void draw_sprite(const char* texture, float x, float y, float depth);