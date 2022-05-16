#include "GamePad.h"

#include <algorithm>
#include <string>

#include "Define.h"
#include "DxLib.h"
#include "KeyBoard.h"

#define PAD(S) (_pad[_idArray[static_cast<int>(ePad::S)]])

using namespace std;

GamePad::GamePad() {
    _idArray[static_cast<int>(ePad::down)] = 0;
    _idArray[static_cast<int>(ePad::left)] = 1;
    _idArray[static_cast<int>(ePad::right)] = 2;
    _idArray[static_cast<int>(ePad::up)] = 3;
    _idArray[static_cast<int>(ePad::bom)] = 4;
    _idArray[static_cast<int>(ePad::shot)] = 5;
    _idArray[static_cast<int>(ePad::slow)] = 11;
    _idArray[static_cast<int>(ePad::start)] = 12;
    _idArray[static_cast<int>(ePad::change)] = 8;
}

void GamePad::update() {
    int padInput;
    padInput = GetJoypadInputState(DX_INPUT_PAD1);  // return bit assign int
    for (int i = 0; i < 16; i++) {
        if (padInput & (1 << i)) {
            _pad[i]++;
        } else {
            _pad[i] = 0;
        }
    }
    merge();
}

void GamePad::merge() {
    PAD(down) =
        max(PAD(down), KeyBoard::getInstance()->getPressingCount(KEY_INPUT_DOWN));
    PAD(left) =
        max(PAD(left), KeyBoard::getInstance()->getPressingCount(KEY_INPUT_LEFT));
    PAD(right) =
        max(PAD(right), KeyBoard::getInstance()->getPressingCount(KEY_INPUT_RIGHT));
    PAD(up) = max(PAD(up), KeyBoard::getInstance()->getPressingCount(KEY_INPUT_UP));
    PAD(bom) = max(PAD(bom), KeyBoard::getInstance()->getPressingCount(KEY_INPUT_X));
    PAD(shot) = max(PAD(shot), KeyBoard::getInstance()->getPressingCount(KEY_INPUT_Z));
    PAD(slow) =
        max(PAD(slow), KeyBoard::getInstance()->getPressingCount(KEY_INPUT_LSHIFT));
    PAD(start) =
        max(PAD(start), KeyBoard::getInstance()->getPressingCount(KEY_INPUT_ESCAPE));
    PAD(change) =
        max(PAD(change), KeyBoard::getInstance()->getPressingCount(KEY_INPUT_C));
}

int GamePad::get(ePad eID) const {
    return _pad[_idArray[static_cast<int>(eID)]];
}
