#pragma once

#include "Task.h"

class Board : public Task {
    public:
    Board() = default;
    virtual ~Board() = default;
    bool update() override;
    void draw() const override;

    private:
    void drawFrame() const;
};
