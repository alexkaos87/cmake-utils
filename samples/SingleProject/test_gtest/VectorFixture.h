#pragma once
#include <gtest/gtest.h>

class VectorFixture : public ::testing::Test
{
protected:
    VectorFixture()
    {
        v1.resize(5);
    }

    std::vector<int> v1;
    std::vector<int> v2;
};