#include <gtest/gtest.h>

// A simple function to test
int AddNumbers(int a, int b)
{
    return a + b;
}

// Basic Assertion Test
TEST(HelloGTestSuite, BasicAssertions)
{
    // Expect equality: 2 + 2 should equal 4
    EXPECT_EQ(AddNumbers(2, 2), 4);

    // Expect inequality: 2 + 2 should not equal 5
    EXPECT_NE(AddNumbers(2, 2), 5);
}

// Boolean Truth Test
TEST(HelloGTestSuite, TruthAssertions)
{
    bool isChessFun = true;
    EXPECT_TRUE(isChessFun);
}
