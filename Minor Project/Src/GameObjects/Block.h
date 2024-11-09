#pragma once

#include "GameObject.h"

class Block : public GameObject {
public:
    void update() override {}
    void reset() override {}

    float getWidth() const { return width; }
    float getHeight() const { return height; }
    bool isActive() const { return active; }
    void setActive(bool value) { active = value; }

private:
    float width = 78.0f;
    float height = 19.0f;
    bool active = true;
};