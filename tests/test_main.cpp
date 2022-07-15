#include <gtest/gtest.h>
#include "TestBase/TestBase.h"
#include "Storage/TestsStorage.h"
#include "Utils/Utils.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    Tests::TestsStorage::buildPath = Utils::getBuildDirPath();
    int result = RUN_ALL_TESTS();
    Utils::saveToFile(Tests::TestsStorage::testsClock, "../build/tests_time/tests_time.txt");
    return result;
}
