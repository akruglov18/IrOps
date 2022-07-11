#include <gtest/gtest.h>
#include "TestBase.h"
#include "TestsStorage.h"
#include "Utils.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    Utils::saveToFile(Tests::TestsStorage::testsClock, "../build/tests/tests.txt");
    return result;
}
