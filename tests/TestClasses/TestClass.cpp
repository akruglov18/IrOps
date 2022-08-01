#include "TestClass.h"
#include <fstream>

namespace Tests {

void TestClass::runBody() {
    auto params = GetParam();
    int value;
    std::tie (value) = params;
    data.resize(6);
    for (int i = 1; i <= 6; i++) {
        data[i - 1] = i;
    }
}

void TestClass::validate() {
    std::string path = Tests::TestsStorage::buildPath + "tests_ref/tests.txt";
    std::ifstream in(path);
    bool isOpen = in.is_open();
    ASSERT_TRUE(isOpen) << "Can't open file in test: " << ::testing::UnitTest::GetInstance()->current_test_info()->name() <<
                        " path: " << path << '\n';
    for (int i = 0; i < 6; i++) {
        int refValue;
        in >> refValue;
        ASSERT_EQ(refValue, data[i]) << "Not equal, ref_value: " << refValue << " cur_value: " << data[i] << "\n";
    }
}

}
