#pragma once

#include <memory>

#include "AbstractScene.h"
#include "Board.h"
#include "Player.h"

class GameScene : public AbstractScene {
    public:
    const static char* ParameterTagStage;
    const static char* ParameterTagLevel;

    GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~GameScene() = default;

    void update() override;
    void draw() const override;  // const だとメンバ変数の変更が行えない。
    private:
    std::shared_ptr<Player> player;
    std::shared_ptr<Board> board;
};
