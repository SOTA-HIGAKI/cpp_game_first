#include "DxLib.h"
#include "SystemMain.h"
#include "Define.h"
#include "Looper.h"

/*!
* @brief DXライブラリやゲームの初期処理
*/
bool SystemMain::initialize() const {
    SetAlwaysRunFlag(TRUE);  // run despite window non-active
    SetWindowSizeChangeEnableFlag(TRUE);  // window size changeable
    SetOutApplicationLogValidFlag(FALSE);  // log
    SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);  // aspect keep
    SetWindowText("Higaki Test");
    ChangeWindowMode(TRUE);  // run on window mode
    SetWindowSizeExtendRate(1.0);  // expand
    const int COLOR_BIT = 32;
    SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);  // 解像度
    if (DxLib_Init()) {
        return false;
    }
    SetDrawScreen(DX_SCREEN_BACK);  // 裏画面処理
    return true;
}

/*!
* @brief DXライブラリやゲームの終了処理
*/
void SystemMain::finalize() const {
    DxLib_End();
}

/*!
* @brief メイン処理
*/
void SystemMain::main() const {
    Looper looper;
    while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
        if(!looper.loop()) {
            break;
        }
    }
}