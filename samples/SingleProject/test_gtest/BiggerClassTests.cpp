#include <gtest/gtest.h>
#include "BiggerClass.h"

TEST(FactorialTests, FactorialsAreComputed) 
{
    BiggerClass object;

    // "validate simple cases" 
    {
        ASSERT_EQ( 1, object.CalculateFactorial(0) );
        ASSERT_EQ(1, object.CalculateFactorial(1) );
    }

    // "validate general cases" 
    {
        ASSERT_EQ( 2, object.CalculateFactorial(2) );
        ASSERT_EQ( 6, object.CalculateFactorial(3) );
        ASSERT_EQ( 3628800, object.CalculateFactorial(10) );
    }
}