#pragma once

#include "IOnChangedListener.h"
#include "Parameter.h"

class IOnChangedListener;

class AbstractScene {
    protected:
    IOnChangedListener* _implSceneChanged;

    public:
    AbstractScene(IOnSceneChagedListener* impl, const Parameter& parameter);
    virtual ~AbstractScene() = default;
    virtual void update() = 0;
    virtual void draw() = 0;
};