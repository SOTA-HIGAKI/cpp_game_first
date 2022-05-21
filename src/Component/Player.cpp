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
    if (moveX + x < Define::IN_X) {                        //¶˜g‚æ‚è¶‚È‚ç
        x = (float)Define::IN_X;                           //¶˜g‚Å~‚ß‚é
    } else if (moveX + x > Define::IN_X + Define::IN_W) {  //‰E˜g‚æ‚è‰E‚È‚ç
        x = (float)(Define::IN_X + Define::IN_W);          //‰E˜g‚Å~‚ß‚é
    } else {                                               //˜g“à‚È‚ç
        x += moveX;                                        //•’Ê‚ÉˆÚ“®
    }
    if (moveY + y < Define::IN_Y) {                        //ã˜g‚æ‚èã‚È‚ç
        y = (float)Define::IN_Y;                           //ã˜g‚Å~‚ß‚é
    } else if (moveY + y > Define::IN_Y + Define::IN_H) {  //‰º˜g‚æ‚è‰º‚È‚ç
        y = (float)(Define::IN_Y + Define::IN_H);          //‰º˜g‚Å~‚ß‚é
    } else {                                               //˜g“à‚È‚ç
        y += moveY;                                        //•’Ê‚ÉˆÚ“®
    }
}