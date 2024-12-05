#include <gtest/gtest.h>
#include "VectorFixture.h"

TEST_F(VectorFixture, InitializationTest) 
{
    ASSERT_EQ(5, v1.size());
    ASSERT_GE(v1.capacity(), 5);

    ASSERT_TRUE(v2.empty());
}

TEST_F(VectorFixture, ResizingBiggerChangesSizeAndCapacity) 
{
    v1.resize( 10 );
    ASSERT_EQ(10, v1.size());
    ASSERT_GE(v1.capacity(), 10);
}

TEST_F(VectorFixture, ResizingSmallerChangesSizeButNotCapacity) 
{
    v1.resize( 0 );
    ASSERT_EQ(0, v1.size());
    ASSERT_GE(v1.capacity(), 5);
}

TEST_F(VectorFixture, ReservingBiggerChangesCapacityButNotSize) 
{
    v2.reserve( 10 );
    ASSERT_TRUE(v2.empty());
    ASSERT_EQ(0, v2.size());
    ASSERT_GE(v2.capacity(), 10);
}

TEST_F(VectorFixture, ReservingSmallerChangesNotChangeSireOrCapacity) 
{
    v1.reserve( 0 );
    ASSERT_EQ(5, v1.size());
    ASSERT_GE(v1.capacity(), 5);
}
