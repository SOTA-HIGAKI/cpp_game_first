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
    if (moveX + x < Define::IN_X) {                        //���g��荶�Ȃ�
        x = (float)Define::IN_X;                           //���g�Ŏ~�߂�
    } else if (moveX + x > Define::IN_X + Define::IN_W) {  //�E�g���E�Ȃ�
        x = (float)(Define::IN_X + Define::IN_W);          //�E�g�Ŏ~�߂�
    } else {                                               //�g���Ȃ�
        x += moveX;                                        //���ʂɈړ�
    }
    if (moveY + y < Define::IN_Y) {                        //��g����Ȃ�
        y = (float)Define::IN_Y;                           //��g�Ŏ~�߂�
    } else if (moveY + y > Define::IN_Y + Define::IN_H) {  //���g��艺�Ȃ�
        y = (float)(Define::IN_Y + Define::IN_H);          //���g�Ŏ~�߂�
    } else {                                               //�g���Ȃ�
        y += moveY;                                        //���ʂɈړ�
    }
}