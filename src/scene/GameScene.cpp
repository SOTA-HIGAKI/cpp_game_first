#include "GameScene.h"

#include <DxLib.h>

const char* GameScene::ParameterTagLevel = "ParameterTagLevel";
const char* GameScene::ParameterTagStage = "ParameterTagStage";

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter)
    : AbstractScene(impl, parameter) {
    _level = parameter.get(ParameterTagLevel);
}

void GameScene::update() {
    // update�ŏ����͑S�������āAdraw�͕\�����邾��
}

void GameScene::draw() const {
    DrawFormatString(100, 100, GetColor(255, 255, 255), "Game level is ... %d", _level);
}