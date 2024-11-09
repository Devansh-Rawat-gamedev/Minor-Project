#pragma once

#include "GameObject.h"

class Platform : public GameObject {
public:
    void update() override;
    void reset() override;

    float getWidth() const { return width; }
    float getHeight() const { return height; }
    float getSpeed() const { return speed; }

private:
    float width = 100.0f;
    float height = 10.0f;
    float speed = 5.0f;
};