#include <boost/test/unit_test.hpp>
#include "BiggerClass.h"

// Create a test suite
BOOST_AUTO_TEST_SUITE(FactorialTests)

BOOST_AUTO_TEST_CASE(FactorialsAreComputed) 
{
    BiggerClass object;

    // "validate simple cases" 
    {
        BOOST_CHECK_EQUAL( 1, object.CalculateFactorial(0) );
        BOOST_CHECK_EQUAL(1, object.CalculateFactorial(1) );
    }

    // "validate general cases" 
    {
        BOOST_REQUIRE_EQUAL( 2, object.CalculateFactorial(2) );
        BOOST_REQUIRE_EQUAL( 6, object.CalculateFactorial(3) );
        BOOST_REQUIRE_EQUAL( 3628800, object.CalculateFactorial(10) );
    }
}

// End the test suite
BOOST_AUTO_TEST_SUITE_END()