#pragma once
#include <memory>
#include "Car.h"
#include "EngineMock.h"

class CarFixture
{
public:
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