#include "TitleScene.h"

#include <Define.h>
#include <GameScene.h>

#include "DxLib.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter)
    : AbstractScene(impl, parameter) {
}

TitleScene::~TitleScene() {
}

void TitleScene::update() {
    if (CheckHitKey(KEY_INPUT_E)) {
        Parameter parameter;
        parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Easy);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
        return;
    }

    if (CheckHitKey(KEY_INPUT_N)) {
        Parameter parameter;
        parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Normal);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
        return;
    }
}

void TitleScene::draw() const {
    DrawString(100, 100, "Title", GetColor(200, 255, 255));
}