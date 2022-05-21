#include "GameScene.h"

#include <DxLib.h>
#include <Macro.h>

using namespace std;

const char* GameScene::ParameterTagLevel = "ParameterTagLevel";
const char* GameScene::ParameterTagStage = "ParameterTagStage";

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter)
    : AbstractScene(impl, parameter) {
    player = make_shared<Player>();
    board = make_shared<Board>();
}

void GameScene::update() {
    player->update();
    board->update();
    // update‚Åˆ—‚Í‘S•”‘‚¢‚ÄAdraw‚Í•\Ž¦‚·‚é‚¾‚¯
}

void GameScene::draw() const {
    player->draw();
    board->draw();
}