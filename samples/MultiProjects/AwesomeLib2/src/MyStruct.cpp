#include "MyStruct.h"

#include <iostream>

namespace AwesomeLib2
{
    MyStruct::MyStruct()
    {
        std::cout << "MyStruct c-tor\n";
    }

    MyStruct::~MyStruct()
    {
        std::cout << "MyStruct d-tor\n";
    }
}