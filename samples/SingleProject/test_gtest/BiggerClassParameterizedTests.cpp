#include <gtest/gtest.h>
#include "BiggerClass.h"

class BiggerClassParametersTests :public ::testing::TestWithParam<std::tuple<int, int>> {
protected:
    BiggerClass object;
};

TEST_P(BiggerClassParametersTests, CalculateFactorialTests) 
{
    const auto input = std::get<0>(GetParam());
    const auto expected = std::get<1>(GetParam());
    ASSERT_EQ(expected, object.CalculateFactorial(input));
}

INSTANTIATE_TEST_SUITE_P(
        FactorialSequenceTests,
        BiggerClassParametersTests,
        ::testing::Values(
                std::make_tuple(0, 1),
                std::make_tuple(1, 1),
                std::make_tuple(2, 2),
                std::make_tuple(3, 6),
                std::make_tuple(10, 3628800)));
                
