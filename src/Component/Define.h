#pragma once

class Define final {
    public:
    const static int WIN_W;
    const static int WIN_H;

    const static int OUT_W;     //ŠO˜g•
    const static int OUT_H;     //ŠO˜g‚‚³
    const static int IN_W;      //“à˜g•
    const static int IN_H;      //“à˜g‚‚³
    const static int CENTER_X;  //“®‚¯‚é”ÍˆÍ‚Ì’†‰›X
    const static int CENTER_Y;  //“®‚¯‚é”ÍˆÍ‚Ì’†‰›Y
    const static int IN_X;      //“à˜gX
    const static int IN_Y;      //“à˜gY

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