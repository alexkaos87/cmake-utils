#include "BiggerClass.h"

#include <iostream>

BiggerClass::BiggerClass()
{
    std::cout << "BiggerClass c-tor\n";
}

BiggerClass::~BiggerClass()
{
    std::cout << "BiggerClass d-tor\n";
}

unsigned BiggerClass::CalculateFactorial( const unsigned number ) const
{
    return number > 1 ? CalculateFactorial(number-1) * number : 1;
}