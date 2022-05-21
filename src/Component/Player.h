#pragma once

#include "Task.h"

class Player : public Task {
    public:
    Player();
    virtual ~Player() = default;
    bool update() override;
    void draw() const override;

    private:
    void move();

    float x, y;
    int image;
};
