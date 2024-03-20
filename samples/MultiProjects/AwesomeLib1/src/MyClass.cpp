#include "MyClass.h"

#include <iostream>

namespace AwesomeLib1
{
    MyClass::MyClass()
    {
        std::cout << "MyClass c-tor\n";
    }

    MyClass::~MyClass()
    {
        std::cout << "MyClass d-tor\n";
    }
}