#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene {
    public:
    TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~TitleScene();
    void update() override;
    void draw() const override;
};