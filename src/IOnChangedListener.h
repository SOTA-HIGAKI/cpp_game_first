#pragma once

#include "AbstractScene.h"
#include "Parameter.h"
#include "eScene.h"

// only interface
class IOnChangedListener {
    public:
    // (多分)不要だが明示的にデフォルトコンストラクタを作成
    IOnChangedListener() = default;
    // 仮想デストラクタ。クラスのポリモーフィックな挙動を実現する目的で利用される
    virtual ~IOnChangedListener() = default;
    virtual void onSceneChanged(
        const eScene scene,          // next scene
        const Parameter &parameter,  // parameter for next scene
        const bool stackClear        // if clear stack
        ) = 0;
};