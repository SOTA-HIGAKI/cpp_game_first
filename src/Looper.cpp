#include "Looper.h"

#include <Macro.h>

#include "Error.h"
#include "GameScene.h"
#include "KeyBoard.h"
#include "TitleScene.h"

using namespace std;

Looper::Looper() {
    Parameter parameter;
    _sceneStack.push(make_shared<TitleScene>(this, parameter));  //  make and push title
}

/*!
 * @brief スタックのトップのシーンの処理をする
 */
bool Looper::loop() {  // constオブジェクトからは、constメンバ関数しか呼び出せない ?
                       // メンバ変数のメンバ変数も？だめっぽい const Fps ->
                       // Fps&へthisポインタを変換できないと言われたので
    KeyBoard::getInstance()->update();
    _sceneStack.top()->update();
    _sceneStack.top()->draw();
    _fps.draw();
    _fps.wait();
    return true;
}

/*!
 * @brief シーン変更(各シーンからコールバックされる)
 * @param scene 変更するシーンのenum
 * @param parameter 前のシーンから引き継ぐパラメータ
 * @param stackClear 現在のシーンのスタックをクリアするか
 */
void Looper::onSceneChanged(
    const eScene scene,
    const Parameter& parameter,
    const bool stackClear) {
    if (stackClear) {
        while (!_sceneStack.empty()) {
            _sceneStack.pop();
        }
    }

    switch (scene) {
        case eScene::Title:
            _sceneStack.push(make_shared<TitleScene>(this, parameter));
            break;
        case eScene::Game:
            _sceneStack.push(make_shared<GameScene>(this, parameter));
            break;
        default: ERR("Unexpected scene has called"); break;
    }
}