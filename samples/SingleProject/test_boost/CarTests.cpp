#include <boost/test/unit_test.hpp>
#include "CarFixture.h"

// Start Test Suite
BOOST_FIXTURE_TEST_SUITE(CarFixtureTests, CarFixture)

BOOST_AUTO_TEST_CASE(StartWithSuccessTest)
{
    // Expect the Start method to be called once and return true
    MOCK_EXPECT(GetMock().Start).once().returns(true);

    BOOST_CHECK(GetCar().Start());
}

BOOST_AUTO_TEST_CASE(DoesNotStartTest)
{
    // Expect the Start method to be called once and return false
    MOCK_EXPECT(GetMock().Start).once().returns(false);

    BOOST_CHECK(!GetCar().Start());
}

BOOST_AUTO_TEST_CASE(CalculateSpeedWithStoppedEngineTest)
{
    // Expect the Start method to be called once and return false
    MOCK_EXPECT(GetMock().Start).once().returns(false);

    // Ensure the DoSomething method is not called
    MOCK_EXPECT(GetMock().DoSomething).never();

    BOOST_CHECK_CLOSE(GetCar().CalculateSpeed(), 0.0, 0.1);
}

BOOST_AUTO_TEST_CASE(CalculateSpeedWithStartedEngineTest)
{
    // Expect the Start method to be called twice and always return true
    MOCK_EXPECT(GetMock().Start).exactly(2).returns(true);

    // Expect specific calls to DoSomething with particular arguments and results
    MOCK_EXPECT(GetMock().DoSomething).with("speed", 1).once().returns(true);
    MOCK_EXPECT(GetMock().DoSomething).with("speed", 2).once().returns(false);

    BOOST_CHECK_CLOSE(GetCar().CalculateSpeed(), 10.0, 0.1);
    BOOST_CHECK_CLOSE(GetCar().CalculateSpeed(), 0.2, 0.1);
}

BOOST_AUTO_TEST_SUITE_END()