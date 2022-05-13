#pragma once

class Define final {
    public:
    const static int WIN_W;
    const static int WIN_H;

    const static float PI;

    enum class eStage : int
    {
        Stage1,
        Stage2,
        Stage3,
        Stage4,
        Stage5,
        StageEX,
        StageNum,
    };

    enum class eLevel : int
    {
        Easy,
        Normal,
        LevelNum,
    };
};