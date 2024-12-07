#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(FactorialTests)

BOOST_AUTO_TEST_CASE(FatalAssertionsTest) 
{
    int a = 5;
    int b = 10;
    float f1 = 3.14f;
    double d1 = 3.14159;
    const char* str1 = "Hello";
    const char* str2 = "World";
    int* ptr1 = nullptr;
    int* ptr2 = &a;

    // BOOST_REQUIRE_EQUAL: Checks if the values are equal
    BOOST_REQUIRE_EQUAL(a, 5);

    // BOOST_REQUIRE_NE: Checks if the values are not equal
    BOOST_REQUIRE_NE(a, b);

    // BOOST_REQUIRE_LT: Checks if the first value is less than the second
    BOOST_REQUIRE_LT(a, b);

    // BOOST_REQUIRE_LE: Checks if the first value is less than or equal to the second
    BOOST_REQUIRE_LE(a, b);

    // BOOST_REQUIRE_GT: Checks if the first value is greater than the second
    BOOST_REQUIRE_GT(b, a);

    // BOOST_REQUIRE_GE: Checks if the first value is greater than or equal to the second
    BOOST_REQUIRE_GE(b, a);

    // BOOST_REQUIRE: Checks if the condition is true
    BOOST_REQUIRE(a < b);

    // BOOST_REQUIRE_CLOSE: Checks if two float values are approximately equal within a tolerance
    BOOST_REQUIRE_CLOSE(f1, 3.14f, 0.0001);

    // BOOST_REQUIRE_CLOSE: Checks if two double values are approximately equal within a tolerance
    BOOST_REQUIRE_CLOSE(d1, 3.14159, 0.000001);

    // BOOST_REQUIRE_EQUAL: Checks if two C-style strings (null-terminated) are equal
    BOOST_REQUIRE_EQUAL(str1, "Hello");

    // BOOST_REQUIRE_NE: Checks if two C-style strings (null-terminated) are not equal
    BOOST_REQUIRE_NE(str1, str2);

    // BOOST_REQUIRE(ptr == nullptr): Checks if a pointer is NULL
    BOOST_REQUIRE(ptr1 == nullptr);

    // BOOST_REQUIRE(ptr != nullptr): Checks if a pointer is not NULL
    BOOST_REQUIRE(ptr2 != nullptr);

    // BOOST_REQUIRE_THROW: Checks if a statement throws a specific exception
    BOOST_REQUIRE_THROW(throw std::runtime_error("error"), std::runtime_error);

    // BOOST_REQUIRE_EXCEPTION: Checks if a statement throws a specific exception type and evaluates a predicate
    BOOST_REQUIRE_EXCEPTION(throw std::runtime_error("error"), std::runtime_error, []([[maybe_unused]] const std::runtime_error& e) { return true; });

    // BOOST_REQUIRE_NO_THROW: Checks if a statement does not throw any exception
    BOOST_REQUIRE_NO_THROW({ int x = 42; x *= 2; });
}

BOOST_AUTO_TEST_CASE(NonFatalAssertionsTest) 
{
    int a = 5;
    int b = 10;
    float f1 = 3.14f;
    double d1 = 3.14159;
    const char* str1 = "Hello";
    const char* str2 = "World";
    int* ptr1 = nullptr;
    int* ptr2 = &a;

    // BOOST_CHECK_EQUAL: Checks if the values are equal
    BOOST_CHECK_EQUAL(a, 5);

    // BOOST_CHECK_NE: Checks if the values are not equal
    BOOST_CHECK_NE(a, b);

    // BOOST_CHECK_LT: Checks if the first value is less than the second
    BOOST_CHECK_LT(a, b);

    // BOOST_CHECK_LE: Checks if the first value is less than or equal to the second
    BOOST_CHECK_LE(a, b);

    // BOOST_CHECK_GT: Checks if the first value is greater than the second
    BOOST_CHECK_GT(b, a);

    // BOOST_CHECK_GE: Checks if the first value is greater than or equal to the second
    BOOST_CHECK_GE(b, a);

    // BOOST_CHECK: Checks if the condition is true
    BOOST_CHECK(a < b);

    // BOOST_CHECK_CLOSE: Checks if two float values are approximately equal within a tolerance
    BOOST_CHECK_CLOSE(f1, 3.14f, 0.0001);

    // BOOST_CHECK_CLOSE: Checks if two double values are approximately equal within a tolerance
    BOOST_CHECK_CLOSE(d1, 3.14159, 0.000001);

    // BOOST_CHECK_EQUAL: Checks if two C-style strings (null-terminated) are equal
    BOOST_CHECK_EQUAL(str1, "Hello");

    // BOOST_CHECK_NE: Checks if two C-style strings (null-terminated) are not equal
    BOOST_CHECK_NE(str1, str2);

    // BOOST_CHECK(ptr == nullptr): Checks if a pointer is NULL
    BOOST_CHECK(ptr1 == nullptr);

    // BOOST_CHECK(ptr != nullptr): Checks if a pointer is not NULL
    BOOST_CHECK(ptr2 != nullptr);

    // BOOST_CHECK_THROW: Checks if a statement throws a specific exception
    BOOST_CHECK_THROW(throw std::runtime_error("error"), std::runtime_error);

    // BOOST_CHECK_EXCEPTION: Checks if a statement throws a specific exception type and evaluates a predicate
    BOOST_CHECK_EXCEPTION(throw std::runtime_error("error"), std::runtime_error, []([[maybe_unused]] const std::runtime_error& e) { return true; });

    // BOOST_CHECK_NO_THROW: Checks if a statement does not throw any exception
    BOOST_CHECK_NO_THROW({ int x = 42; x *= 2; });
}

BOOST_AUTO_TEST_SUITE_END()