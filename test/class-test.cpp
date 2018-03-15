#include "../src/manager.h"
#include "gtest/gtest.h"

class ManagerTest : public ::testing::Test {
protected:
    ManagerTest()
    {
        // before each test
    }

    virtual ~ManagerTest()
    {
        // after each test
    }

    virtual void SetUp()
    {
        // if the constructor is not enough, called before each test
    }

    virtual void TearDown()
    {
        // if the destructor is not enough, called after each test
    }

    Manager man;
};

TEST_F(ManagerTest, should_pass)
{
    man.camera();
    EXPECT_EQ(0, 0);
}
