#pragma once

class CalcUtils final {
    public:
    CalcUtils() = delete;  // T t1; T t2 = t1; <- error
    static float roundPoint(float val, int point);
};
