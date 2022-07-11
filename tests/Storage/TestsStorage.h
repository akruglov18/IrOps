#ifndef _TESTS_STORAGE_H
#define _TESTS_STORAGE_H

#include <unordered_map>

namespace Tests {

class TestsStorage {
public:
    static std::unordered_map<std::string, int> testsClock;
};

}

#endif