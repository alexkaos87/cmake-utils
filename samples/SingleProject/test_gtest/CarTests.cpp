#include <gtest/gtest.h>
#include "CarFixture.h"

TEST_F(CarFixture, StartWithSuccessTest) 
{
    EXPECT_CALL(GetMock(), Start())
      .Times(1)
      .WillOnce(::testing::Return(true));

    ASSERT_TRUE(GetCar().Start());

    ::testing::Mock::VerifyAndClearExpectations(std::addressof(GetMock()));
}

TEST_F(CarFixture, DoesNotStartTest) 
{
    EXPECT_CALL(GetMock(), Start())
      .Times(1)
      .WillOnce(::testing::Return(false));

    ASSERT_FALSE(GetCar().Start());
    
    ::testing::Mock::VerifyAndClearExpectations(std::addressof(GetMock()));
}

TEST_F(CarFixture, CalculateSpeedWithStoppedEngineTest) 
{
    EXPECT_CALL(GetMock(), Start())
      .Times(1)
      .WillOnce(::testing::Return(false));
      
    EXPECT_CALL(GetMock(), DoSomething("speed", 1))
      .Times(0);

    ASSERT_NEAR(0.0, GetCar().CalculateSpeed(), 0.1);
    
    ::testing::Mock::VerifyAndClearExpectations(std::addressof(GetMock()));
}

TEST_F(CarFixture, CalculateSpeedWithStartedEngineTest) 
{
    EXPECT_CALL(GetMock(), Start())
      .Times(2)
      .WillRepeatedly(::testing::Return(true));
      
    EXPECT_CALL(GetMock(), DoSomething("speed", 1))
      .Times(1)
      .WillOnce(::testing::Return(true));

    EXPECT_CALL(GetMock(), DoSomething("speed", 2))
      .Times(1)
      .WillOnce(::testing::Return(false));

    ASSERT_NEAR(10.0, GetCar().CalculateSpeed(), 0.1);
    ASSERT_NEAR(0.2, GetCar().CalculateSpeed(), 0.1);
    
    ::testing::Mock::VerifyAndClear(std::addressof(GetMock()));
}