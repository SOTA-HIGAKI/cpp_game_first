#include "Player.h"

#include <DxLib.h>

#include "Define.h"
#include "GamePad.h"

//#include "Image.h"

const static float SPEED = 9;

Player::Player(): x(100), y(100) {
    image = LoadGraph("seishi0.png");
}

bool Player::update() {
    move();
    return true;
}

void Player::draw() const {
    // DrawRotaGraphF(x, y, 1.0, 0.0, Image::getInstance()->getPlayer(), TRUE);
    DrawBox(x, y, x + 10, y + 10, GetColor(200, 200, 200), TRUE);
}

void Player::move() {
    float moveX = 0, moveY = 0;
    if (GamePad::getInstance()->get(ePad::left) > 0) {
        moveX -= SPEED;
    }
    if (GamePad::getInstance()->get(ePad::right) > 0) {
        moveX += SPEED;
    }
    if (GamePad::getInstance()->get(ePad::down) > 0) {
        moveY += SPEED;
    }
    if (GamePad::getInstance()->get(ePad::up) > 0) {
        moveY -= SPEED;
    }
    if (moveX && moveY) {
        moveX /= (float)sqrt(2.0);
        moveY /= (float)sqrt(2.0);
    }
    if (GamePad::getInstance()->get(ePad::slow) > 0) {
        moveX /= 3;
        moveY /= 3;
    }
    if (moveX + x < Define::IN_X) {                        //左枠より左なら
        x = (float)Define::IN_X;                           //左枠で止める
    } else if (moveX + x > Define::IN_X + Define::IN_W) {  //右枠より右なら
        x = (float)(Define::IN_X + Define::IN_W);          //右枠で止める
    } else {                                               //枠内なら
        x += moveX;                                        //普通に移動
    }
    if (moveY + y < Define::IN_Y) {                        //上枠より上なら
        y = (float)Define::IN_Y;                           //上枠で止める
    } else if (moveY + y > Define::IN_Y + Define::IN_H) {  //下枠より下なら
        y = (float)(Define::IN_Y + Define::IN_H);          //下枠で止める
    } else {                                               //枠内なら
        y += moveY;                                        //普通に移動
    }
}