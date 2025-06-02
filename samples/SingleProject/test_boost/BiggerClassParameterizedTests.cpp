#include <boost/test/data/test_case.hpp>
#include <boost/test/included/unit_test.hpp>
#include "BiggerClass.h"

BOOST_AUTO_TEST_SUITE(BiggerClassParametersTestsSuite)

BOOST_DATA_TEST_CASE(CalculateFactorialTests, 
    boost::unit_test::data::make(
        std::make_tuple(0, 1),
        std::make_tuple(1, 1),
        std::make_tuple(2, 2),
        std::make_tuple(3, 6),
        std::make_tuple(10, 3628800)
    ),
    input, expected)
{
    BiggerClass object;
    
    BOOST_REQUIRE_EQUAL(expected, object.CalculateFactorial(input));
}

BOOST_DATA_TEST_CASE(CalculateOwnerTests, 
    boost::unit_test::data::make(
        std::make_tuple("4111111111111111", "VISA"),
        std::make_tuple("4111111111111", "VISA"),
        std::make_tuple("4012888888881881", "VISA"),
        std::make_tuple("378282246310005", "AMEX"),
        std::make_tuple("6011111111111117", "Discover"),
        std::make_tuple("5105105105105100", "Mastercard"),
        std::make_tuple("5105105105105106", "Mastercard"),
        std::make_tuple("9111111111111111", "Unknown")
    ),
    input, expected)
{
    BiggerClass object;
    
    BOOST_REQUIRE_EQUAL(expected, object.CalculateOwner(input));
}

BOOST_AUTO_TEST_SUITE_END()
