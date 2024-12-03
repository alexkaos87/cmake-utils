#include <boost/test/unit_test.hpp>

struct VectorFixture
{
    VectorFixture()
    {
        v1.resize(5);
    }

    std::vector<int> v1;
    std::vector<int> v2;
};

// Create a test suite
BOOST_FIXTURE_TEST_SUITE(fixture, VectorFixture)

BOOST_AUTO_TEST_CASE(InitializationTest) 
{
    BOOST_CHECK_EQUAL(5, v1.size());
    BOOST_CHECK_GE(v1.capacity(), 5);

    BOOST_CHECK(v2.empty());
}

BOOST_AUTO_TEST_CASE(ResizingBiggerChangesSizeAndCapacity) 
{
    v1.resize( 10 );
    BOOST_CHECK_EQUAL(10, v1.size());
    BOOST_CHECK_GE(v1.capacity(), 10);
}

BOOST_AUTO_TEST_CASE(ResizingSmallerChangesSizeButNotCapacity) 
{
    v1.resize( 0 );
    BOOST_CHECK_EQUAL(0, v1.size());
    BOOST_CHECK_GE(v1.capacity(), 5);
}

BOOST_AUTO_TEST_CASE(ReservingBiggerChangesCapacityButNotSize) 
{
    v2.reserve( 10 );
    BOOST_CHECK(v2.empty());
    BOOST_CHECK_EQUAL(0, v2.size());
    BOOST_CHECK_GE(v2.capacity(), 10);
}

BOOST_AUTO_TEST_CASE(ReservingSmallerChangesNotChangeSireOrCapacity) 
{
    v1.reserve( 0 );
    BOOST_CHECK_EQUAL(5, v1.size());
    BOOST_CHECK_GE(v1.capacity(), 5);
}

BOOST_AUTO_TEST_SUITE_END()