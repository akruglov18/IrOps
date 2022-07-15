#include "../TestClasses/TestClass.h"

namespace Tests {

TEST_P(TestClass, TestClass1) {
    Run();
}

INSTANTIATE_TEST_SUITE_P(Example, TestClass, ::testing::Combine(::testing::ValuesIn( { 1 } )));

}
