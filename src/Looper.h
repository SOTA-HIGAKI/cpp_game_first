#pragma once

#include <memory>
#include <stack>

#include "AbstractScene.h"
#include "IOnSceneChagedListener.h"

class Looper final : public IOnSceneChagedListener {
    public:
    Looper();
    ~Looper() = default;
    bool loop() const;
    void onSceneChanged(
        const eScene scene,
        const Parameter& parameter,
        const bool StackClear) override;

    private:
    std::stack<std::shared_ptr<AbstractScene>> _sceneStack;
};