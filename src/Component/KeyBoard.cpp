#include "KeyBoard.h"

#include <DxLib.h>

bool KeyBoard::update() {
    char nowKeyStatus[KEY_NUM];
    GetHitKeyStateAll(nowKeyStatus);
    for (int i = 0; i < KEY_NUM; i++) {
        // if push some key
        if (nowKeyStatus[i] != 0) {
            if (_releasingCount[i] > 0) {
                _releasingCount[i] = 0;
            } else {
                _pressingCount[i]++;
            }
        } else {
            if (_pressingCount[i] > 0) {
                _pressingCount[i] = 0;
            } else {
                _releasingCount[i]++;
            }
        }
    }
    return true;
}

int KeyBoard::getPressingCount(int keyCode) {
    if (!isAvailableCode(keyCode)) {
        return -1;
    } else {
        return _pressingCount[keyCode];
    }
}

int KeyBoard::getReleasingCount(int keyCode) {
    if (!isAvailableCode(keyCode)) {
        return -1;
    } else {
        return _releasingCount[keyCode];
    }
}

bool KeyBoard::isAvailableCode(int keyCode) {
    if (!(0 <= keyCode && keyCode < KEY_NUM)) {
        return false;
    } else {
        return true;
    }
}
