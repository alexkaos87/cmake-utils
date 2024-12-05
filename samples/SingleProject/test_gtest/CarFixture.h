#pragma once
#include <gtest/gtest.h>
#include <memory>
#include <gmock/gmock.h>
#include "Car.h"
#include "EngineMock.h"

class CarFixture : public ::testing::Test
{
protected:
    CarFixture() : pEngineMock()
    {
        auto pEngine = std::make_unique<EngineMock>();
        pEngineMock = pEngine.get();

        pCar = std::make_unique<Car>(std::move(pEngine));
    }

    inline EngineMock& GetMock() noexcept { return *pEngineMock; }

    inline Car& GetCar() noexcept { return *pCar; }

private:
    EngineMock* pEngineMock;
    std::unique_ptr<Car> pCar;
};