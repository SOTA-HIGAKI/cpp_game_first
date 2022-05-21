#include "Image.h"

#include <DxLib.h>

Image::Image() {
    player = myLoadGraph("../../dat/image/player/body/seishi0.png");
    board = myLoadGraph("../../dat/image/board/board.png");
}

void Image::release() {
    const int size = images.size();
    for (int i = 0; i < size; i++) {
        DeleteGraph(images[i]);
    }
    images.clear();
}

int Image::myLoadGraph(const char* fileName) {
    int ret = LoadGraph(fileName);
    images.push_back(ret);
    return ret;
}

int Image::myLoadDivGraph(
    char* fileName,
    int n,
    int xn,
    int yn,
    int w,
    int h,
    int* buf) {
    int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
    for (int i = 0; i < n; i++) {
        images.push_back(buf[i]);
    }
    return ret;
}
