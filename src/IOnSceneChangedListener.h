#pragma once

#include "AbstractScene.h"
#include "Parameter.h"
#include "eScene.h"

class IOnSceneChangedListener {
    public:
    // (多分)不要だが明示的にデフォルトコンストラクタを作成
    IOnSceneChangedListener() = default;
    // 仮想デストラクタ。クラスのポリモーフィックな挙動を実現する目的で利用される
    virtual ~IOnSceneChangedListener() = default;
    virtual void onSceneChanged(
        const eScene scene,          // next scene
        const Parameter &parameter,  // parameter for next scene
        const bool stackClear        // if clear stack
        ) = 0;
};