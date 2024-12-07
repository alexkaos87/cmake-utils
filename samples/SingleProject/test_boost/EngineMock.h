#pragma once
#include <turtle/mock.hpp>
#include "IEngine.h" 

// Mock class definition using Turtle
MOCK_BASE_CLASS(EngineMock, IEngine)
{
    MOCK_METHOD(Start, 0, bool()); // Mock the Start method with no parameters
    MOCK_METHOD(DoSomething, 2, bool(const std::string& name, const int count)); // Mock the DoSomething method
};