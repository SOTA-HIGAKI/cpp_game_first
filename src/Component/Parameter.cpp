#include "Parameter.h"

void Parameter::set(std::string key, int val) {
    _map[key] = val;
}

int Parameter::get(std::string key) const {
    auto itr = _map.find(key);
    if (_map.end() == itr) {
        return Error;
    } else {
        return itr->second;
    }
}