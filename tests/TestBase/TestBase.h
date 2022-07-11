#ifndef _TEST_BASE_H_
#define _TEST_BASE_H_

#include <gtest/gtest.h>
#include <unordered_map>

namespace Tests {

template<typename T>
class TestBase : public ::testing::Test<T> {
public:
    void Run() final {
        auto start = std::clock();
        runBody();
        auto end = std::clock();
        std::string testName(::testing::UnitTest::GetInstance()->current_test_info()->name());
        testsClock[testName] = clock;
    }

protected:
    virtual void runBody() = 0;
};

}

#endif
