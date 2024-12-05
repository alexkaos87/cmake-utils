#pragma once
#include <string>

class IEngine
{
public:
    virtual ~IEngine() = default;

    virtual bool Start() = 0;

    virtual bool DoSomething(const std::string& name, const int count) const = 0;
};
