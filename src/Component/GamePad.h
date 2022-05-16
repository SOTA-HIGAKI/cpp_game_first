#pragma once

#include <array>

#include "Singleton.h"

enum class ePad : int
{
    left,
    up,
    right,
    down,
    shot,
    bom,
    slow,
    start,
    change
};

class GamePad final : public Singleton<GamePad> {
    public:
    GamePad();
    ~GamePad() = default;
    void update();
    int get(ePad eID) const;

    private:
    void merge();

    const static int PAD_KEY_NUM = 16;
    std::array<int, PAD_KEY_NUM> _idArray;  // button allocate
    std::array<int, PAD_KEY_NUM> _pad;      // input state
};
