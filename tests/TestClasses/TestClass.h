#ifndef _TEST_CLASS_H_
#define _TEST_CLASS_H_

#include "../TestBase/TestBase.h"

namespace Tests {

class TestClass : public TestBase<int> {
protected:
    void runBody() override;
};

}

#endif
