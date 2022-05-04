#include "TitleScene.h"

#include "DxLib.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter)
    : AbstractScene(impl, parameter) {
}

TitleScene::~TitleScene() {
}

void TitleScene::update() {
}

void TitleScene::draw() {
    DrawString(100, 100, "Title", GetColor(255, 255, 255));
}