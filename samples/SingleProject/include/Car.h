#pragma once
#include <memory>

class IEngine;

class Car
{
public:
    Car(std::unique_ptr<IEngine> pEngine);

    bool Start() const;

    double CalculateSpeed();

private:
    std::unique_ptr<IEngine> m_pEngine;

    int m_rotation{0};
};