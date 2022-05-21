#pragma once

#include <vector>

#include "Singleton.h"

class Image final : public Singleton<Image> {
    public:
    Image();
    ~Image() = default;
    void load(){};
    void release();

    int getPlayer() const {
        return player;
    };
    int getBoard() const {
        return board;
    }

    private:
    int myLoadGraph(const char*);
    int myLoadDivGraph(char* fileName, int n, int xn, int yn, int w, int h, int* buf);

    std::vector<int> images;
    int player;
    int board;
};
