#pragma once

#include "GameObject.h"

class Ball : public GameObject {
public:
    void update() override;
    void reset() override;

    float getDX() const { return dx; }
    float getDY() const { return dy; }
    void setDX(float value) { dx = value; }
    void setDY(float value) { dy = value; }
    float getRadius() const { return radius; }

private:
    float dx = 3.0f;
    float dy = -3.0f;
    float radius = 10.0f;
};