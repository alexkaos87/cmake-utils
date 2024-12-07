#include <gtest/gtest.h>

TEST(FooTests, FatalAssertionsTest)
{
    int a = 5;
    int b = 10;
    float f1 = 3.14f;
    double d1 = 3.14159;
    const char* str1 = "Hello";
    const char* str2 = "World";

    // ASSERT_EQ: Checks if the values are equal
    ASSERT_EQ(a, 5);

    // ASSERT_NE: Checks if the values are not equal
    ASSERT_NE(a, b);

    // ASSERT_LT: Checks if the first value is less than the second
    ASSERT_LT(a, b);

    // ASSERT_LE: Checks if the first value is less than or equal to the second
    ASSERT_LE(a, b);

    // ASSERT_GT: Checks if the first value is greater than the second
    ASSERT_GT(b, a);

    // ASSERT_GE: Checks if the first value is greater than or equal to the second
    ASSERT_GE(b, a);

    // ASSERT_TRUE: Checks if the condition is true
    ASSERT_TRUE(a < b);

    // ASSERT_FALSE: Checks if the condition is false
    ASSERT_FALSE(a > b);

    // ASSERT_FLOAT_EQ: Checks if two float values are approximately equal
    ASSERT_FLOAT_EQ(f1, 3.14f);

    // ASSERT_DOUBLE_EQ: Checks if two double values are approximately equal
    ASSERT_DOUBLE_EQ(d1, 3.14159);

    // ASSERT_NEAR: Checks if the difference between two values is within a tolerance
    ASSERT_NEAR(d1, 3.1416, 0.0001);

    // ASSERT_STREQ: Checks if two C-style strings (null-terminated) are equal
    ASSERT_STREQ(str1, "Hello");

    // ASSERT_STRNE: Checks if two C-style strings (null-terminated) are not equal
    ASSERT_STRNE(str1, str2);

    // ASSERT_THROW: Checks if a statement throws a specific exception
    ASSERT_THROW(throw std::runtime_error("error"), std::runtime_error);

    // ASSERT_ANY_THROW: Checks if a statement throws any exception
    ASSERT_ANY_THROW(throw std::runtime_error("error"));

    // ASSERT_NO_THROW: Checks if a statement does not throw any exception
    ASSERT_NO_THROW({ int x = 42; x *= 2; });
}

TEST(FooTests, NonFatalAssertionsTest) 
{
    int a = 5;
    int b = 10;
    float f1 = 3.14f;
    double d1 = 3.14159;
    const char* str1 = "Hello";
    const char* str2 = "World";

    // EXPECT_EQ: Checks if the values are equal
    EXPECT_EQ(a, 5);

    // EXPECT_NE: Checks if the values are not equal
    EXPECT_NE(a, b);

    // EXPECT_LT: Checks if the first value is less than the second
    EXPECT_LT(a, b);

    // EXPECT_LE: Checks if the first value is less than or equal to the second
    EXPECT_LE(a, b);

    // EXPECT_GT: Checks if the first value is greater than the second
    EXPECT_GT(b, a);

    // EXPECT_GE: Checks if the first value is greater than or equal to the second
    EXPECT_GE(b, a);

    // EXPECT_TRUE: Checks if the condition is true
    EXPECT_TRUE(a < b);

    // EXPECT_FALSE: Checks if the condition is false
    EXPECT_FALSE(a > b);

    // EXPECT_FLOAT_EQ: Checks if two float values are approximately equal
    EXPECT_FLOAT_EQ(f1, 3.14f);

    // EXPECT_DOUBLE_EQ: Checks if two double values are approximately equal
    EXPECT_DOUBLE_EQ(d1, 3.14159);

    // EXPECT_NEAR: Checks if the difference between two values is within a tolerance
    EXPECT_NEAR(d1, 3.1416, 0.0001);

    // EXPECT_STREQ: Checks if two C-style strings (null-terminated) are equal
    EXPECT_STREQ(str1, "Hello");

    // EXPECT_STRNE: Checks if two C-style strings (null-terminated) are not equal
    EXPECT_STRNE(str1, str2);

    // EXPECT_THROW: Checks if a statement throws a specific exception
    EXPECT_THROW(throw std::runtime_error("error"), std::runtime_error);

    // EXPECT_ANY_THROW: Checks if a statement throws any exception
    EXPECT_ANY_THROW(throw std::runtime_error("error"));

    // EXPECT_NO_THROW: Checks if a statement does not throw any exception
    EXPECT_NO_THROW({ int x = 42; x *=2; });
}