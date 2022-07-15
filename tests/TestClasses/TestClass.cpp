#include "TestClass.h"
#include <fstream>

namespace Tests {

void TestClass::runBody() {
    auto params = GetParam();
    int value;
    std::tie (value) = params;
    std::string path = Tests::TestsStorage::buildPath + "tests_ref/tests.txt";
    std::cout << path << "\n";
    std::ifstream in(path);
    bool isOpen = in.is_open();
    ASSERT_TRUE(isOpen) << "Can't open file in test: " << ::testing::UnitTest::GetInstance()->current_test_info()->name();
    if (isOpen) {
        for (int i = 1; i <= 6; i++) {
            int value;
            in >> value;
            ASSERT_EQ(value, i) << "Not equal, ref_value: " << value << " cur_value: " << i << "\n";
        }
    }
}

}
