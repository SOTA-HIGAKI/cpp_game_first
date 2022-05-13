#include "TitleScene.h"

#include <Define.h>
#include <GameScene.h>

#include "DxLib.h"
#include "KeyBoard.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter)
    : AbstractScene(impl, parameter) {
}

TitleScene::~TitleScene() {
}

void TitleScene::update() {
    if (KeyBoard::getInstance()->getPressingCount(KEY_INPUT_E) == 1) {
        Parameter parameter;
        parameter.set(
            GameScene::ParameterTagLevel,
            static_cast<int>(Define::eLevel::Easy));
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
        return;
    }

    if (KeyBoard::getInstance()->getPressingCount(KEY_INPUT_N) == 1) {
        Parameter parameter;
        parameter.set(
            GameScene::ParameterTagLevel,
            static_cast<int>(Define::eLevel::Normal));
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
        return;
    }
}

void TitleScene::draw() const {
    DrawString(100, 100, "Title", GetColor(200, 255, 255));
    // push‚Ærelease‚ÌƒtƒŒ[ƒ€‚ð•\Ž¦‚Å‚«‚é
    // DrawFormatString(
    //     200,
    //     200,
    //     GetColor(200, 255, 255),
    //     "push: %d",
    //     KeyBoard::getInstance()->getPressingCount(KEY_INPUT_RETURN));
    // DrawFormatString(
    //     200,
    //     220,
    //     GetColor(200, 255, 255),
    //     "release: %d",
    //     KeyBoard::getInstance()->getReleasingCount(KEY_INPUT_RETURN));
}