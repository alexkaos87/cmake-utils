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

BOOST_AUTO_TEST_SUITE_END()
