#include "TitleScene.h"

#include "DxLib.h"

TitleScene::TitleScene(IOnSceneChagedListener* impl, const Parameter& parameter) {
}

void TitleScene::update() {
}

void TitleScene::draw() {
    DrawString(100, 100, "TItle", GetColor(255, 255, 255));
}