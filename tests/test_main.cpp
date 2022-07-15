#include <gtest/gtest.h>
#include "TestBase/TestBase.h"
#include "Storage/TestsStorage.h"
#include "Utils/Utils.h"

int main(int argc, char** argv) {
    Tests::TestsStorage::buildPath = Utils::getBuildDirPath();
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    Utils::saveToFile(Tests::TestsStorage::testsClock, Tests::TestsStorage::buildPath + "tests_time/tests_time.txt");
    return result;
}
