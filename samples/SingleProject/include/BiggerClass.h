#pragma once

#include <string>

class BiggerClass
{
public:
    BiggerClass();
    ~BiggerClass();

    unsigned CalculateFactorial(unsigned number) const;
    std::string CalculateOwner(const std::string& numbers) const;
};