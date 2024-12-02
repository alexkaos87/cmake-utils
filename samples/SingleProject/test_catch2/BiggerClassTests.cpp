#include <catch2/catch_test_macros.hpp>
#include "BiggerClass.h"

TEST_CASE( "Factorials are computed", "[factorial]" ) 
{
    BiggerClass object;

    SECTION( "validate simple cases" ) 
    {
        REQUIRE( object.CalculateFactorial(0) == 1 );
        REQUIRE( object.CalculateFactorial(1) == 1 );
    }

    SECTION( "validate general cases" ) 
    {
        REQUIRE( object.CalculateFactorial(2) == 2 );
        REQUIRE( object.CalculateFactorial(3) == 6 );
        REQUIRE( object.CalculateFactorial(10) == 3628800 );
    }
}