#ifndef _TEST_BASE_H_
#define _TEST_BASE_H_

#include <gtest/gtest.h>
#include <unordered_map>
#include "../Storage/TestsStorage.h"

namespace Tests {

template<typename T>
class TestBase : public ::testing::TestWithParam<T> {
public:
    void Run() {
        auto start = std::clock();
        runBody();
        auto end = std::clock();
        validate();
        std::string testName(::testing::UnitTest::GetInstance()->current_test_info()->name());
        TestsStorage::testsClock[testName] = (end - start);
    }

protected:
    virtual void runBody() = 0;
    virtual void validate() = 0;
};

}

#endif
