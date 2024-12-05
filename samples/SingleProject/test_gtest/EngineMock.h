#pragma once
#include <gmock/gmock.h>
#include "IEngine.h" 


class EngineMock : public IEngine 
{
public:
    MOCK_METHOD(bool, Start, (), (override));
    
    MOCK_METHOD(bool, DoSomething, (const std::string& name, const int count), (const, override));
};