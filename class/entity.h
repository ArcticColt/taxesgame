#pragma once

class Entity {
public:
    Entity();
    virtual void update() = 0;
    float x;
    float y;
    float depth;
};