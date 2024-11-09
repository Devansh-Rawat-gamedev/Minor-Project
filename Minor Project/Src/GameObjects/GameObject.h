#pragma once

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update() = 0;
    virtual void reset() = 0;

    float getX() const { return x; }
    float getY() const { return y; }
    void setX(float value) { x = value; }
    void setY(float value) { y = value; }

protected:
    float x = 0.0f;
    float y = 0.0f;
};