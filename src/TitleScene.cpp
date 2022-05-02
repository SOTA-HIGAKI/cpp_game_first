#include "TitleScene.h"

#include "DxLib.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) {
}

TitleScene::~TitleScene() {
}

void TitleScene::update() {
}

void TitleScene::draw() {
    DrawString(100, 100, "TItle", GetColor(255, 255, 255));
}