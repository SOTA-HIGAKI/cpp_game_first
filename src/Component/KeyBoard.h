#pragma once

#include <array>

#include "Singleton.h"

class KeyBoard final : public Singleton<KeyBoard> {
    KeyBoard() = default;
    friend Singleton<KeyBoard>;

    public:
    bool update();
    int getPressingCount(int keyCode);
    int getReleasingCount(int keyCode);

    private:
    static const int KEY_NUM = 256;
    std::array<int, KEY_NUM> _pressingCount;
    std::array<int, KEY_NUM> _releasingCount;

    bool isAvailableCode(int keyCode);
};
