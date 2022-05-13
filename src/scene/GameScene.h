#pragma once

#include "AbstractScene.h"

class GameScene : public AbstractScene {
    public:
    const static char* ParameterTagStage;
    const static char* ParameterTagLevel;

    GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~GameScene() = default;

    void update() override;
    void draw() const override;  // const ���ƃ����o�ϐ��̕ύX���s���Ȃ��B
    private:
    int _level;
};
