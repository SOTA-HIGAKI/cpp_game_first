#include "Looper.h"

#include "TitleScene.h"
#include "eScene.h"

using namespace std;

Looper::Looper() {
    Parameter parameter;
    _sceneStack.push(make_shared<TitleScene>(this, parameter));  //  make and push title
}

/*!
 * @brief スタックのトップのシーンの処理をする
 */
bool Looper::loop() const {
    _sceneStack.top()->update();
    _sceneStack.top()->draw();
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
}