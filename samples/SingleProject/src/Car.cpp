#include "Car.h"
#include "IEngine.h"

Car::Car(std::unique_ptr<IEngine> pEngine) : m_pEngine(std::move(pEngine))
{}

bool Car::Start() const
{
    return m_pEngine->Start();    
}

double Car::CalculateSpeed()
{
    if(!Start())
    {
        return 0.0;
    }

    return m_pEngine->DoSomething("speed", ++m_rotation) ? m_rotation * 10.0 : m_rotation * 0.1;
}