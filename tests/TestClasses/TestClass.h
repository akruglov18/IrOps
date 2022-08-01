#ifndef _TEST_CLASS_H_
#define _TEST_CLASS_H_

#include "../TestBase/TestBase.h"
#include <tuple>

namespace Tests {

class TestClass : public TestBase<std::tuple<int>> {
protected:
    virtual void runBody() override;
    virtual void validate() override;

    std::vector<int> data;
};

}

#endif
