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
