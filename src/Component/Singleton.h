#pragma once

template <typename T>
class Singleton {
    protected:
    Singleton() = default;
    virtual ~Singleton() = default;
    Singleton(const Singleton& r) = default;
    Singleton& operator=(const Singleton& r) = default;

    public:
    static T* getInstance() {
        static T instance;
        return &instance;
    }
};
