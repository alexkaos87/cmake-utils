#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "CarFixture.h"

// Now define the test suite using Catch2 syntax
TEST_CASE("StartWithSuccessTest", "[CarFixture]") 
{
    CarFixture fixture;
    
    EXPECT_CALL(fixture.GetMock(), Start())
      .Times(1)
      .WillOnce(::testing::Return(true));

    REQUIRE(fixture.GetCar().Start());

    ::testing::Mock::VerifyAndClearExpectations(std::addressof(fixture.GetMock()));
}

TEST_CASE("DoesNotStartTest", "[CarFixture]") 
{
    CarFixture fixture;

    // Set expectation for Start method
    EXPECT_CALL(fixture.GetMock(), Start())
      .Times(1)
      .WillOnce(::testing::Return(false));

    REQUIRE_FALSE(fixture.GetCar().Start());
    
    ::testing::Mock::VerifyAndClearExpectations(std::addressof(fixture.GetMock()));
}

TEST_CASE("CalculateSpeedWithStoppedEngineTest", "[CarFixture]") 
{
    CarFixture fixture;

    // Expect the engine to return false for Start()
    EXPECT_CALL(fixture.GetMock(), Start())
      .Times(1)
      .WillOnce(::testing::Return(false));

    // Ensure DoSomething is never called
    EXPECT_CALL(fixture.GetMock(), DoSomething("speed", 1))
      .Times(0);

    REQUIRE_THAT(fixture.GetCar().CalculateSpeed(), Catch::Matchers::WithinRel(0.0, 0.1));
    
    ::testing::Mock::VerifyAndClearExpectations(std::addressof(fixture.GetMock()));
}

TEST_CASE("CalculateSpeedWithStartedEngineTest", "[CarFixture]") 
{
    CarFixture fixture;

    // Expect engine to return true for the first two Start() calls
    EXPECT_CALL(fixture.GetMock(), Start())
      .Times(2)
      .WillRepeatedly(::testing::Return(true));
      
    EXPECT_CALL(fixture.GetMock(), DoSomething("speed", 1))
      .Times(1)
      .WillOnce(::testing::Return(true));

    EXPECT_CALL(fixture.GetMock(), DoSomething("speed", 2))
      .Times(1)
      .WillOnce(::testing::Return(false));

    REQUIRE_THAT(fixture.GetCar().CalculateSpeed(), Catch::Matchers::WithinRel(10.0, 0.1));
    REQUIRE_THAT(fixture.GetCar().CalculateSpeed(), Catch::Matchers::WithinRel(0.2, 0.1));
    
    ::testing::Mock::VerifyAndClear(std::addressof(fixture.GetMock()));
}